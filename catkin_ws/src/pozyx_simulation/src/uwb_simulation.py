#!/usr/bin/env python
'''
__author__ = "Bekir Bostanci"
__license__ = "BSD"
__version__ = "0.0.1"
__maintainer__ = "Bekir Bostanci"
__email__ = "bekirbostanci@gmail.com"
'''

import rospy

from pozyx_simulation.msg import  uwb_data
from gazebo_msgs.msg import ModelStates
import tf 

import math
import numpy as np

import time
import threading
import os, sys
import random


global robot_pose_x,robot_pose_y,robot_pose_z
robot_pose_x =[0,0,0,0]
robot_pose_y =[0,0,0,0]
robot_pose_z =[0,0,0,0]

global counter
counter = 0 

rospy.init_node('uwb_simulation', anonymous=True)
#distances are publishing with uwb_data_topic
pub = rospy.Publisher('uwb_data_topic', uwb_data, queue_size=10)


def calculate_distance(uwb_pose):
    #pose comes in gazebo/model_states (real position)
    global robot_pose_x,robot_pose_y,robot_pose_z
    robot_pose = [robot_pose_x[0],robot_pose_y[0],robot_pose_z[0]]

    #describe 2 points
    p1 = np.array(uwb_pose)
    p2 = np.array(robot_pose)

    #difference between robot and uwb distance
    uwb_dist = np.sum((p1-p2)**2, axis=0)
    #add noise 
    uwb_dist=uwb_dist+np.random.normal(0, uwb_dist*0.015,1)  
    return np.sqrt(uwb_dist)


def uwb_simulate():
    global robot_pose_x,robot_pose_y,robot_pose_z

    while not rospy.is_shutdown():
        time.sleep(0.1)
        all_distance = [] 
        all_destination_id = []
        
        for i in range(1,ROBOT_NUMBER):
            #calculate distance uwb to robot for all anchors 
            uwb_pose = [robot_pose_x[i],robot_pose_y[i],robot_pose_z[i]]
            dist = calculate_distance(uwb_pose)   
            all_distance.append(dist) 
        
        #uwb_anchors_set.launch same order (not important for simulation)
        all_destination_id.append(0x0001)
        all_destination_id.append(0x0002)
        


        #publish data with ROS             
        publish_data(all_destination_id , all_distance)    


def publish_data(all_destination_id, all_distance):
    #uwb message type is a special message so that firstly describe this message 
    uwb_data_cell = uwb_data()
    uwb_data_cell.destination_id=all_destination_id
    uwb_data_cell.stamp = [rospy.Time.now(),rospy.Time.now(),rospy.Time.now()]
    uwb_data_cell.distance = all_distance
    pub.publish(uwb_data_cell)


def subscribe_data(ModelStates):
    #for the get real position of robot subscribe model states topic  
    global robot_pose_x,robot_pose_y,robot_pose_z
    global counter
    counter = counter +1 

    #gazebo/modelstate topic frequency is 100 hz. We descrese 10 hz with log method 
    if counter %100 ==  0:  
        counter = 0 
        #ModelStates.pose[2] = turtlebot3 model real position on modelstates   
        robot_pose_x[0] =ModelStates.pose[MODELSTATE_INDEX_0].position.x
        robot_pose_y[0] =ModelStates.pose[MODELSTATE_INDEX_0].position.y
        robot_pose_z[0] =ModelStates.pose[MODELSTATE_INDEX_0].position.z
        
        robot_pose_x[1] =ModelStates.pose[MODELSTATE_INDEX_1].position.x
        robot_pose_y[1] =ModelStates.pose[MODELSTATE_INDEX_1].position.y
        robot_pose_z[1] =ModelStates.pose[MODELSTATE_INDEX_1].position.z
        
        robot_pose_x[2] =ModelStates.pose[MODELSTATE_INDEX_2].position.x
        robot_pose_y[2] =ModelStates.pose[MODELSTATE_INDEX_2].position.y
        robot_pose_z[2] =ModelStates.pose[MODELSTATE_INDEX_2].position.z

        uwb_simulate()
        rospy.loginfo("%s is %s",ModelStates.twist[11].linear.x, ModelStates.twist[11].linear.y)

        

if __name__ == "__main__":
    #get uwb anchors postion
    

    MODELSTATE_INDEX_0 = rospy.get_param('/pozyx_simulation/modelstate_index_0',2)
    MODELSTATE_INDEX_1 = rospy.get_param('/pozyx_simulation/modelstate_index_1',3)
    MODELSTATE_INDEX_2 = rospy.get_param('/pozyx_simulation/modelstate_index_2',4)
    ROBOT_NUMBER = rospy.get_param('/pozyx_simulation/robot_number',3)

    time.sleep(0.5)

    #get robot real position => you can change ModelStates.pose[] different robot's
    rospy.Subscriber('gazebo/model_states', ModelStates, subscribe_data)

    #start the publish uwb data
    rospy.spin()
    
sys.exit()
