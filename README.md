# 本项目用于保存本人ros工程文件
### catkin_ws
* ros工作空间
* 功能包介绍如下：
#### ins_eskf_kitt
* 实现```uwb imu eskf```定位  
* 目前正在开发基于单个```uwb```进行点对点定位  
***
#### moving_filer
* 实现对含有噪声的```uwb```测距信号进行滤波  
***
#### offboard_pkg
* 实现```gazebo```仿真中基于```px4```实现无人机定高度控制 
* 结合[gazebo-px4](https://github.com/PDXzst/PX4-Autopilot)使用  
***
#### state_path_rviz
* 实现将```nav_msgs::Odometry```话题转化为```nav_msgs::Path```话题，用于```rviz```中显示

#### 后续计划
* 后续将更新```px4 gazebo```环境下无人机模拟```uwb```信号  
* 将```offboard_pkg```更加泛用化，用于多架无人机控制  
***
***
### dataset
* 存储数据  
***
***
### shells
* 存放bash脚本文件
#### gazebo_simulation_offboard_
* 用于gazebo仿真
#### imu_uwb_pkg
* imu uwb eskf项目所用  
* ```imu_single _start.sh```启动imu uwb eskf程序  
* ```bag_start.sh```启动imu uwb eskf程序并录制数据至```/dataset```文件夹  
* ```clear_dataset.sh```清除```bag _start.sh```录制的数据
