#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class CameraTest:
    def __init__(self):
        rospy.init_node('camera_test', anonymous=True)
        self.image_sub = rospy.Subscriber('/camera/image', Image, self.image_callback)
        self.bridge = CvBridge()

    def image_callback(self, data):
        try:
            # Convert the ROS Image message to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
            cv2.imshow("Camera Feed", cv_image)
            cv2.waitKey(30)
        except Exception as e:
            rospy.logerr("Error converting image: {}".format(e))

    def run(self):
        rospy.spin()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    camera_test = CameraTest()
    camera_test.run()