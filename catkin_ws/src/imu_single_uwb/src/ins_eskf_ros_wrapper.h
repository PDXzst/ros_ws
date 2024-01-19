#ifndef INS_ESKF_INS_ESKF_ROS_WRAPPER_H
#define INS_ESKF_INS_ESKF_ROS_WRAPPER_H


#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>
#include <geometry_msgs/TwistStamped.h>
#include <nav_msgs/Odometry.h>
#include "ins_eskf.h"
#include <GeographicLib/LocalCartesian.hpp>
#include <std_msgs/Float64.h>

#include <glog/logging.h>
#include <string>
#include <deque>
#include <mutex>

#include "nlink_parser/LinktrackNodeframe2.h"

namespace ins_eskf{

class Ins_eskf_ROS_Wrapper{

public:
    Ins_eskf_ROS_Wrapper(ros::NodeHandle &_nh,YAML::Node& _node);

private:
    void imu_cb(const sensor_msgs::ImuConstPtr& imu_in);
    void gps_cb(const sensor_msgs::NavSatFixConstPtr& gps_in);
    void kitti_vel_cb(const geometry_msgs::TwistStampedConstPtr& twist_in);
    void register_sub_pub();
    void uwb_cb(const nlink_parser::LinktrackNodeframe2ConstPtr& uwb_in);
    void initialization_kitti();
    bool synce_measure();
    //将IMU和UWB时间戳关于初始时间戳对齐 单位转化为 s
    inline double uwb_stamp_synce(double uwb_stamp){return (uwb_stamp - initial_stamp_uwb)/1000;}   //ms转化为m
    inline double imu_stamp_synce(double imu_stamp){return (imu_stamp - initial_stamp_imu);}        //s

    Ins_eskf::UWB_data uwb_msg_2_data(nlink_parser::LinktrackNodeframe2 _imu_msg);
    Ins_eskf::IMU_data imu_msg_2_data(sensor_msgs::Imu _imu_msg); 
    Ins_eskf::GPS_data gps_msg_2_data(sensor_msgs::NavSatFix _gps_msg); 
    sensor_msgs::NavSatFix gps_data_2_msg(Ins_eskf::GPS_data& _gps_data);
    std_msgs::Float64 float_to_stdmsgs_Float64(float range);
    nav_msgs::Odometry state_to_odom_msg(Ins_eskf::State _state,double _stamp);//将状态转化为视觉里程计“消息”
    void visualize_res_and_kitti_gps_magnetormeter();
    void DEBUG_check_synce_measure();
private:
    ros::NodeHandle nh;
    ros::Subscriber sub_imu;
    ros::Subscriber sub_gps;
    ros::Subscriber sub_vel;
    ros::Subscriber sub_uwb;
    ros::Publisher pub_pos;
    ros::Publisher pub_uwb_dis;
    std::shared_ptr<Ins_eskf> p_ins_eskf;

    std::string dataset = "kitti";



    std::string imu_topic,gps_topic,uwb_topic;
    std::string kitti_vel_topic;
    bool initialized = false;
    std::mutex mtx;
    std::deque<sensor_msgs::NavSatFix> gps_buf;
    std::deque<sensor_msgs::Imu> imu_buf;
    std::deque<nlink_parser::LinktrackNodeframe2> uwb_buf;
    std::vector<geometry_msgs::TwistStamped> init_twist_buf;
    Ins_eskf::State init_state;
    Ins_eskf::Measure measure;
    double initialization_stamp = -1;
    double initial_stamp_imu = -1;
    double initial_stamp_uwb = -1;

    GeographicLib::LocalCartesian geo_converter_;
    nav_msgs::Odometry kitti_gps_odom_msg_;
    ros::Publisher pub_imu_odometrty_;
    ros::Publisher pub_imu_normal_odometrty;
    ros::Publisher pub_kitti_gps_odometrty_;

};


}



#endif