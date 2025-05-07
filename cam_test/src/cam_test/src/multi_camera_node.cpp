#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

class MultiCameraNode {
public:
    MultiCameraNode() {
        nh_ = ros::NodeHandle("~");
        int frame_rate;
        std::string resolution;
        int camera_count;
        
        // 读取参数
        nh_.param("frame_rate", frame_rate, 30);  // 默认30fps
        nh_.param<std::string>("resolution", resolution, "1920x1536");  // 默认1920x1536
        nh_.param("camera_count", camera_count, 8);  // 默认8个摄像头
        
        int width, height;
        sscanf(resolution.c_str(), "%dx%d", &width, &height);

        // 初始化摄像头和发布者
        for (int i = 0; i < camera_count; i++) {
            // 创建摄像头捕获对象
            cv::VideoCapture cap;
            if (cap.open(i)) {
                // 设置摄像头参数
                cap.set(cv::CAP_PROP_FRAME_WIDTH, width);
                cap.set(cv::CAP_PROP_FRAME_HEIGHT, height);
                cap.set(cv::CAP_PROP_FPS, frame_rate);
                cap.set(cv::CAP_PROP_CONVERT_RGB, false);  // 捕获原始格式
                
                // 存储摄像头对象
                cameras_.push_back(cap);
                
                // 创建对应的发布者
                std::string topic_name = "camera" + std::to_string(i) + "/image";
                ros::Publisher pub = nh_.advertise<sensor_msgs::Image>(topic_name, 1);
                publishers_.push_back(pub);
                
                ROS_INFO("Camera %d initialized successfully", i);
            } else {
                ROS_WARN("Failed to open camera %d", i);
            }
        }
        
        if (cameras_.empty()) {
            ROS_ERROR("No cameras could be opened. Shutting down.");
            ros::shutdown();
        }
        
        frame_rate_ = frame_rate;
    }

    ~MultiCameraNode() {
        for (auto& cap : cameras_) {
            if (cap.isOpened()) {
                cap.release();
            }
        }
        ROS_INFO("All cameras released.");
    }

    void captureAndPublish() {
        ros::Rate loop_rate(frame_rate_);

        while (ros::ok()) {
            // 逐个处理每个摄像头
            for (size_t i = 0; i < cameras_.size(); i++) {
                cv::Mat frame;
                // 捕获图像
                cameras_[i] >> frame;
                if (frame.empty()) {
                    ROS_WARN("Camera %zu captured empty frame.", i);
                    continue;
                }

                // 处理图像
                cv::Mat processed_frame;
                if (frame.channels() == 2) {
                    // 2通道（YUV，例如UYVY）
                    cv::cvtColor(frame, processed_frame, cv::COLOR_YUV2RGB_UYVY);
                } else if (frame.channels() == 3) {
                    // 3通道（BGR）
                    cv::cvtColor(frame, processed_frame, cv::COLOR_BGR2RGB);
                } else {
                    ROS_ERROR("Camera %zu: Unsupported number of channels: %d", i, frame.channels());
                    continue;
                }

                // 创建消息头并发布图像
                std_msgs::Header header;
                header.stamp = ros::Time::now();
                header.frame_id = "camera" + std::to_string(i) + "_frame";
                sensor_msgs::ImagePtr msg = cv_bridge::CvImage(header, "rgb8", processed_frame).toImageMsg();
                publishers_[i].publish(msg);
            }

            ros::spinOnce();
            loop_rate.sleep();
        }
    }

private:
    ros::NodeHandle nh_;
    std::vector<ros::Publisher> publishers_;
    std::vector<cv::VideoCapture> cameras_;
    int frame_rate_;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "multi_camera_node");
    MultiCameraNode camera_node;
    camera_node.captureAndPublish();
    return 0;
}