#!/usr/bin/env python
import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Pose, Point, Quaternion
from visualization_msgs.msg import Marker

def odom_callback(msg):
    # Extract position and orientation from Odometry message
    position = msg.pose.pose.position
    orientation = msg.pose.pose.orientation
    
    # Create a Marker message for visualization in RViz
    marker = Marker()
    marker.header.frame_id = "odom"
    marker.type = marker.SPHERE
    marker.action = marker.ADD
    marker.pose.position = position
    marker.pose.orientation = orientation
    marker.scale.x = 0.1
    marker.scale.y = 0.1
    marker.scale.z = 0.1
    marker.color.a = 1.0
    marker.color.r = red
    marker.color.g = green
    marker.color.b = blue
    marker.lifetime = rospy.Duration()

    # Publish the Marker message
    marker_publisher.publish(marker)

if __name__ == '__main__':
    rospy.init_node('odom_to_pose')
    
    # Get parameters for topics
    odom_topic = rospy.get_param('~odom_topic', 'odom')
    pose_topic = rospy.get_param('~pose_topic', 'pose')
    red = rospy.get_param('~red',1)
    green = rospy.get_param('~green',1)
    blue = rospy.get_param('~blue',1)
    rospy.Subscriber(odom_topic, Odometry, odom_callback)
    marker_publisher = rospy.Publisher(pose_topic, Marker, queue_size=10)
    
    rospy.spin()