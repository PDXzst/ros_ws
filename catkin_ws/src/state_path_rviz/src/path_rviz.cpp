#include<stdio.h>
#include<ros/ros.h>
#include<nav_msgs/Path.h>
#include<nav_msgs/Odometry.h>

ros::Publisher path_pub_imu;    //发布path的节点
ros::Publisher path_pub_uwb;    //发布path的节点
ros::Subscriber odom_sub_imu;   //接收odometry的节点
ros::Subscriber odom_sub_uwb;   //接收odometry的节点
nav_msgs::Path path;        //发布的路径
bool init_flag=1;             //path初始化标记位

void odom_imu_Callback(const nav_msgs::Odometry::ConstPtr& odom_imu){
    if(init_flag){
        path.header=odom_imu->header;
        init_flag=0;
    }

    geometry_msgs::PoseStamped pose_stamped_this;
    pose_stamped_this.header=odom_imu->header;
    pose_stamped_this.pose=odom_imu->pose.pose;

    path.poses.push_back(pose_stamped_this);
    path_pub_imu.publish(path);
}

void odom_uwb_Callback(const nav_msgs::Odometry::ConstPtr& odom_uwb){
    if(init_flag){
        path.header=odom_uwb->header;
        init_flag=0;
    }

    geometry_msgs::PoseStamped pose_stamped_this;
    pose_stamped_this.header=odom_uwb->header;
    pose_stamped_this.pose=odom_uwb->pose.pose;

    path.poses.push_back(pose_stamped_this);
    path_pub_uwb.publish(path);
}

int main (int argc, char **argv)
{
    ros::init (argc, argv, "odometry2path");
    ros::NodeHandle nh;
    
 //       记得在此处更改odometry消息topic名称     //
    odom_sub_imu  = nh.subscribe<nav_msgs::Odometry>("/imu_odometry", 10, odom_imu_Callback);
    odom_sub_uwb  = nh.subscribe<nav_msgs::Odometry>("/uwb_odometry", 10, odom_uwb_Callback);
    path_pub_imu = nh.advertise<nav_msgs::Path>("/imu_path",10, true);
    path_pub_uwb = nh.advertise<nav_msgs::Path>("/uwb_path",10, true);

    
    ros::spin();
    // ros::Rate loop_rate(50);
    // loop_rate.sleep();
    return 0;
}
