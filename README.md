首先下载本仓库，但不要直接使用，把**20.04-5.4.36、CameraCalibration、cam_test三个文件夹都分别放在/home/scjy目录下**。

# 一、相机驱动及板卡驱动安装

1、把相机连上工控机，最多可连8个；

2、终端打开`/home/scjy/20.04-5.4.36/pcie_v4l2_sdk/bash`文件夹，运行`sudo ./load_modules.sh`，加载驱动模块；

3、`sudo ./pcie_init_card0.sh`，用于初始化板卡0，因为工控机上只有一个板卡，所以就是板卡0；

4、相机在`/dev/video`，例如测试第0个相机，使用命令`guvcview -d /dev/video0`；

5、如果程序有报错，`cd pcie_v4l2_sdk`然后`make clean`再`make`。

参考：https://github.com/SENSING-Technology/CoaxCapture-CCG3

# 二、森云GMSL相机内参标定

## 1、内参标定

(1) `cd CameraCalibration/Tools`

(2) `python collect.py -type image -id 0 -name test` (示例命令，需要更改)

选择image模式进行图像采集，默认相机为YUV格式的鱼眼相机camera0，默认保存路径为`../IntrinsicCalibration/data/`，默认图像大小为1920✖1536(改图像大小最好与相机驱动一起改)，其他详细参数见Tools的readme。
之后按下空格键捕捉图片，此时第二个窗口会显示捕捉的图片，按Y确认，按N则丢弃，可以多次采集(每个摄像头最好采集上下左右、左旋右旋、前倾后倾共20~30张棋盘格图像)；

(3) `cd CameraCalibration/IntrinsicCalibration`

(4) `python intrinsicCalib.py -input image` (示例命令，需要更改)

选择image模式进行离线标定，默认相机为YUV格式的鱼眼相机camera0，默认标定图像输入路径为./data，默认图像命名格式为img_raw0.jpg、img_raw1.jpg以此类推，默认图像大小为1920✖1536(改图像大小最好与相机驱动一起改)，默认棋盘格角点数为11✖8、棋盘格大小为20mm²，其他详细参数见IntrinsicCalibration的readme
标定完成后会生成camera_0_D.npy和camera_0_K.npy在同一路径下，这就是camera0的相机内参；

(5) `cd CameraCalibration/Tools`

(6) `python undistort.py -width 1920 -height 1536 -path_k ../IntrinsicCalibration/camera_0_K.npy -path_d ../IntrinsicCalibration/camera_0_D.npy -path_read ../IntrinsicCalibration/data/ -path_save ../ -srcformat jpg -name undist_img -quality 95` (示例命令，需要更改)

使用undistort.py进行图像去畸变处理，单独拍一张img_src.jpg进行处理(也可以对文件夹进行批量处理，见undistort.py的注释)，其他详细参数见Tools的readme。
如果去畸变处理后的棋盘格线变直即说明标定正确。

## 2、外参标定

尚未进行。

## 3、BEV环视

尚未进行。

参考：https://github.com/dyfcalid/CameraCalibration

# 三、GMSL相机与ROS通讯

gmsl相机与普通rgb相机不同，无法直接读取图像到ros话题，因此使用V4L2驱动框架进行，驱动程序已经兼容了V4L2。正确安装驱动后每个相机都在/dev目录下生成了节点，如/dev/video0，再用ros读取图像，流程如下：

1、创建ros节点，实例化一个cv的cv::VideoCapture类cap_；

2、初始化cap_的参数，帧宽度cv::CAP_PROP_FRAME_WIDTH、帧高度cv::CAP_PROP_FRAME_HEIGHT、帧率cv::CAP_PROP_FPS等，最好与相机驱动的参数相同，意思是要改参数就相机采集卡驱动和cv::VideoCapture一起改，不然可能会出现分辨率问题。并且一定要设置cv::CAP_PROP_CONVERT_RGB为false来把cv的自动转换rgb关闭，因为cv会自动把捕获的帧转成三通道rgb图像，但是gmsl相机图像格式为YUV，使用cv的自动转换会导致图像乱码；

3、用cap_.open(0)打开并采集dev/video0设备的图像（如果采集其他摄像头就打开1、2、3等）；

4、手动使用cv::cvtColor的cv::COLOR_YUV2RGB_UYVY模式转换YUV图像为RGB，YUV图像到底是UYVY还是YUYV在板卡驱动程序中看，不要相信v4l2 -ctl -d /dev/video0 list-formats-ext显示的格式；

5、创建消息头，发布图像。

示例文件在`cam_test`中，进入`cam_test`后先确认没有使用conda环境，然后`catkin_make`，之后`source`，发布单个相机就`rosrun cam_test camera_node`，发布8个相机就`rosrun cam_test multi_camera_node`，然后打开rviz显示话题就可看到图像。

如果需要录制rosbag，示例命令：`rosbag record /multi_camera_node/camera0/image /multi_camera_node/camera1/image /multi_camera_node/camera2/image /multi_camera_node/camera3/image /multi_camera_node/camera4/image /multi_camera_node/camera5/image /multi_camera_node/camera6/image /multi_camera_node/camera7/image -O eight_cameras.bag`，

bag播放：`rosbag play src/cam_test/eight_cameras.bag`
