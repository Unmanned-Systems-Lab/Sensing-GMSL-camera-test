#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <iostream>

class CameraNode {
public:
    CameraNode() {
        nh_ = ros::NodeHandle("~");
        int frame_rate;
        std::string resolution;
        // 读取帧率和分辨率参数
        nh_.param("frame_rate", frame_rate, 30);  // 默认30fps
        nh_.param<std::string>("resolution", resolution, "1920x1536");  // 默认1920x1080
        int width, height;
        sscanf(resolution.c_str(), "%dx%d", &width, &height);

        // 打开摄像头
        cap_.open(0);
        if (cap_.isOpened()) {
            // 在打开摄像头后再设置参数
            cap_.set(cv::CAP_PROP_FRAME_WIDTH, width);
            cap_.set(cv::CAP_PROP_FRAME_HEIGHT, height);
            cap_.set(cv::CAP_PROP_FPS, frame_rate);
            cap_.set(cv::CAP_PROP_CONVERT_RGB, false);  // 捕获原始格式
        } else {
            ROS_ERROR("Could not open the camera.");
            ros::shutdown();
        }

        image_pub_ = nh_.advertise<sensor_msgs::Image>("camera/image", 1);
        frame_rate_ = frame_rate;  // 存储帧率到成员变量
    }

    ~CameraNode() {
        if (cap_.isOpened()) {
            cap_.release();
            ROS_INFO("Camera released.");
        }
    }

    void captureAndPublish() {
        cv::Mat frame;
        ros::Rate loop_rate(frame_rate_);  // 使用存储的帧率
        
        // 添加帧率计算变量
        int frame_count = 0;
        ros::Time last_time = ros::Time::now();
        double actual_fps = 0.0;
    
        while (ros::ok()) {
            // 捕获图像
            cap_ >> frame;
            if (frame.empty()) {
                ROS_WARN("Captured empty frame.");
                continue;
            }
    
            // 计算帧率
            frame_count++;
            ros::Time current_time = ros::Time::now();
            double time_diff = (current_time - last_time).toSec();
            
            // 大约每秒打印一次帧率和分辨率
            if (time_diff >= 1.0) {
                actual_fps = frame_count / time_diff;
                
                // 获取并打印实际分辨率
                int actual_width = frame.cols;
                int actual_height = frame.rows;
                
                // 获取摄像头实际设置的帧率(可能与请求的不同)
                double cap_fps = cap_.get(cv::CAP_PROP_FPS);
                
                ROS_INFO("Camera Stats - Resolution: %dx%d, Actual FPS: %.2f, Set FPS: %.2f",
                         actual_width, actual_height, actual_fps, cap_fps);
                         
                // 重置计数器
                frame_count = 0;
                last_time = current_time;
            }
    
            // 检查图像格式
            ROS_INFO("Captured frame: channels=%d, type=%d", frame.channels(), frame.type());
    
            // 其余处理代码保持不变...
            cv::Mat processed_frame;
            if (frame.channels() == 2) {
                // 2通道（YUV，例如UYVY）
                cv::cvtColor(frame, processed_frame, cv::COLOR_YUV2RGB_UYVY);
            } else if (frame.channels() == 3) {
                // 3通道（BGR）
                cv::cvtColor(frame, processed_frame, cv::COLOR_BGR2RGB);
            } else {
                ROS_ERROR("Unsupported number of channels: %d", frame.channels());
                continue;
            }
    
            // 创建消息头并发布图像
            std_msgs::Header header;
            header.stamp = ros::Time::now();
            header.frame_id = "camera_frame";
            sensor_msgs::ImagePtr msg = cv_bridge::CvImage(header, "rgb8", processed_frame).toImageMsg();
            image_pub_.publish(msg);
    
            ros::spinOnce();
            loop_rate.sleep();
        }
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher image_pub_;
    cv::VideoCapture cap_;
    int frame_rate_;  // 存储帧率
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "camera_node");
    CameraNode camera_node;
    camera_node.captureAndPublish();
    return 0;
}