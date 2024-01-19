# CMake generated Testfile for 
# Source directory: /home/robot/ros_ws/catkin_ws/src/imu_single_uwb
# Build directory: /home/robot/ros_ws/catkin_ws/build/imu_single_uwb
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_imu_single_uwb_gtest_imu_single_uwb_test "/home/robot/ros_ws/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/robot/ros_ws/catkin_ws/build/test_results/imu_single_uwb/gtest-imu_single_uwb_test.xml" "--return-code" "/home/robot/ros_ws/catkin_ws/devel/lib/imu_single_uwb/imu_single_uwb_test --gtest_output=xml:/home/robot/ros_ws/catkin_ws/build/test_results/imu_single_uwb/gtest-imu_single_uwb_test.xml")
set_tests_properties(_ctest_imu_single_uwb_gtest_imu_single_uwb_test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;98;catkin_run_tests_target;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;37;_catkin_add_google_test;/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/CMakeLists.txt;381;catkin_add_gtest;/home/robot/ros_ws/catkin_ws/src/imu_single_uwb/CMakeLists.txt;0;")
subdirs("extern/serial")
