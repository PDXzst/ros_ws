#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>

ros::Publisher path_pub;    // 发布path的节点
ros::Subscriber odom_sub;   // 接收odometry的节点

nav_msgs::Path path;        // 发布的路径
bool init_flag = true;      // path初始化标记位

void odomCallback(const nav_msgs::Odometry::ConstPtr& odom){
    if(init_flag){
        path.header = odom->header;
        path.header.frame_id = "odom";
        init_flag = false;
    }

    geometry_msgs::PoseStamped pose_stamped_this;
    pose_stamped_this.header = odom->header;
    pose_stamped_this.pose = odom->pose.pose;

    path.poses.push_back(pose_stamped_this);
    path_pub.publish(path);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "odom_to_path");

    // 创建节点句柄，并设置命名空间
    ros::NodeHandle nh;

    // 定义参数变量
    std::string odom_topic;
    std::string path_topic;
    ros::param::get("~odom_topic", odom_topic);
    ros::param::get("~path_topic", path_topic);
    
    // 订阅odometry消息
    odom_sub = nh.subscribe<nav_msgs::Odometry>(odom_topic, 100, odomCallback);
    // 发布path消息
    path_pub = nh.advertise<nav_msgs::Path>(path_topic, 100, true);

    ros::spin();
    return 0;
}
