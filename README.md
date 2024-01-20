# 本项目用于保存本人ros工程文件
### catkin_ws
* ros工作空间  
* 功能包介绍如下：  
#### handsfree_ros_imu
* ```ros```中对```imu```数据进行获取并在```rviz```中可视化  
#### imu_single_uwb
* 实现```imu```融合```单个uwb```进行```eskf```  
* 定位效果不是很理想，等待进一步开发  
#### ins_eskf_kitt
* 实现```uwb imu eskf```定位  
#### moving_filer
* 实现对含有噪声的```uwb```测距信号进行滤波  
#### offboard_pkg
* 实现```gazebo```仿真中基于```px4```实现无人机定高度控制 
* 结合[gazebo-px4](https://github.com/PDXzst/PX4-Autopilot)使用  
#### state_path_rviz
* 实现将```nav_msgs::Odometry```话题转化为```nav_msgs::Path```话题，用于```rviz```中显示  
#### pozyx_simulation
* 在```gazebo```中对```uav models```之间建立```虚拟uwb```用于后续在```gazebo```中进行无人机```uwb imu eskf```融合定位研究  
***
### dataset
* 存储数据  
* 结合```shells```中```imu_uwb_pkg```中```bag_start.sh```使用  
***
### shells
* 存放```bash```脚本文件
* 脚本介绍：
#### gazebo_simulation_offboard_
* 用于```gazebo```仿真
#### imu_uwb_pkg
* ```imu uwb eskf```项目所用  
* ```imu_single _start.sh```启动imu uwb eskf程序  
* ```bag_start.sh```启动imu uwb eskf程序并录制数据至```/dataset```文件夹  
* ```clear_dataset.sh```清除```bag _start.sh```录制的数据
***
### 后续计划
* 后续将更新功能包```px4 gazebo```环境下无人机模拟```uwb```信号  
* 将```offboard_pkg```更加泛用化，用于多架无人机控制  
* 将```imu uwb eskf```项目搭建于多无人机仿真环境中  
