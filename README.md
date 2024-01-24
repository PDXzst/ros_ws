# 本项目用于保存本人ros工程文件
***
### catkin_ws
> **ros工作空间**

**功能包介绍如下：**  
#### 1.handsfree_ros_imu
> `ros`中对`imu`数据进行获取并在`rviz`中可视化  
#### 2.imu_single_uwb
> 实现`imu`融合`单个uwb`进行`eskf`  
* 定位效果不是很理想，等待进一步开发  
* 使用如下方法启动：

**方法一** 按部就班：  
1. 串口权限：
```
sudo chmod 777 /dev/ttyCH343USB0
sudo chmod 777 /dev/ttyUSB0
```
2. 启动`eskf`
```
roslaunch imu_single_uwb imu_single_uwb_start.launch
```
**方法二** `shell`脚本文件：  
1. 进入文件夹：  
```
cd ~/ros_ws/shells/imu_uwb_pkg
```
2. 运行`shell`脚本:  
```
bash imu_single_start.sh
```
**注**：该`shell`脚本包涵录入数据包过程 存放于`ros_ws/dataset`
#### 3.ins_eskf_kitt
> 实现`uwb imu eskf`定位  
#### 4.moving_filer
> 实现对含有噪声的`uwb`测距信号进行滤波  
```
rosrun moving_filer moving_filer
```
**注**：  
&emsp;&emsp;可通过修改`moving_filer.h`的`const float NUM`来改变`moving_filer`的步长  
&emsp;&emsp;移动动均值滤波利用当前以及前`NUM - 1`步的数据进行均值，对当前值进行滤波
#### 5.offboard_pkg
> 实现`gazebo`仿真中基于`px4`实现无人机定高度控制  
* 结合[gazebo-px4](https://github.com/PDXzst/PX4-Autopilot)使用  
* 实现定高飞行可运行：  
```
roslaunch px4 mavros_posix_sitl_cp.launch
rosrun offboard_pkg offboard_node
```
* 在多无人机中启用该程序  
更改`offboard_pkg/src/offboard_node.cpp`中的话题：  
``` cpp
ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_cb);
ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);
ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");
```
启动程序:  
```
roslaunch px4 multi_uav_mavros_sitl_cp.launch  
rosrun offboard_pkg offboard_node  

```
#### 6.state_path_rviz
> 实现将`nav_ msgs::Odometry`话题转化为`nav_ msgs::Path`话题，用于`rviz`中显示  
#### 7.pozyx_simulation
> 在`gazebo`中对`uav models`之间建立`虚拟uwb`用于后续在`gazebo`中进行无人机`uwb imu eskf`融合定位研究  
* 启动`虚拟uwb`:  
```
roslaunch pozyx_simulation uwb_manually_initializing.launch
```
**注**：  
1. `/gazebo/model_states`中`models`次序决定了`modelstate_index_'number'`的`value`，排序从`0`开始根据每架无人机对应的编号输入相应的`value`值进行对应  
2. 本程序采用`modelstate_index_0`作为母无人机  
***
***
### dataset
> **存储数据**  
* 结合`shells`中`imu_uwb_pkg`中`bag_start.sh`使用  
***
***
### shells
> **存放`shell`脚本文件**

**脚本介绍：**  
#### 1.gazebo_simulation_offboard_
> 用于`gazebo`仿真
#### 2.imu_uwb_pkg
> `imu uwb eskf`项目功能包  
* `imu_single_start.sh`启动`imu uwb eskf`程序  
* `bag_start.sh`启动`imu uwb eskf`程序并录制数据至`/dataset`文件夹  
* `clear_dataset.sh`清除`bag_start.sh`录制的数据
***
***
### 后续计划
- [ ] 后续将更新功能包`px4 gazebo`环境下无人机模拟`uwb`信号  
- [ ] 将`offboard_pkg`更加泛用化，用于多架无人机控制  
- [ ] 将`imu uwb eskf`项目搭建于多无人机仿真环境中  
***
***
