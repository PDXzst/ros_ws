# Install script for directory: /home/robot/ros_ws/catkin_ws/src/imu_single_uwb

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/robot/ros_ws/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/imu_single_uwb/msg" TYPE FILE FILES
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackAnchorframe0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNode0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNode1.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNode2.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNodeframe0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNodeframe1.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNodeframe2.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNodeframe3.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackTag.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackTagframe0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/TofsenseCascade.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/TofsenseFrame0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackAoaNode0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackAoaNodeframe0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNode4Anchor.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNode4Tag.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNodeframe4.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNode5.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNodeframe5.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNode6.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/LinktrackNodeframe6.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/TofsenseMFrame0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/TofsenseMFrame0Pixel.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/IotFrame0.msg"
    "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/msg/IotFrame0Node.msg"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/imu_single_uwb/cmake" TYPE FILE FILES "/home/robot/ros_ws/catkin_ws/build/imu_single_uwb/catkin_generated/installspace/imu_single_uwb-msg-paths.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/robot/ros_ws/catkin_ws/devel/include/imu_single_uwb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/robot/ros_ws/catkin_ws/devel/share/roseus/ros/imu_single_uwb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/robot/ros_ws/catkin_ws/devel/share/common-lisp/ros/imu_single_uwb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/robot/ros_ws/catkin_ws/devel/share/gennodejs/ros/imu_single_uwb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/robot/ros_ws/catkin_ws/devel/lib/python3/dist-packages/imu_single_uwb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/robot/ros_ws/catkin_ws/devel/lib/python3/dist-packages/imu_single_uwb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/robot/ros_ws/catkin_ws/build/imu_single_uwb/catkin_generated/installspace/imu_single_uwb.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/imu_single_uwb/cmake" TYPE FILE FILES "/home/robot/ros_ws/catkin_ws/build/imu_single_uwb/catkin_generated/installspace/imu_single_uwb-msg-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/imu_single_uwb/cmake" TYPE FILE FILES
    "/home/robot/ros_ws/catkin_ws/build/imu_single_uwb/catkin_generated/installspace/imu_single_uwbConfig.cmake"
    "/home/robot/ros_ws/catkin_ws/build/imu_single_uwb/catkin_generated/installspace/imu_single_uwbConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/imu_single_uwb" TYPE FILE FILES "/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/robot/ros_ws/catkin_ws/build/imu_single_uwb/extern/serial/cmake_install.cmake")

endif()
