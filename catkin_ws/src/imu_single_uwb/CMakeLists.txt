cmake_minimum_required(VERSION 3.0.2)
project(imu_single_uwb)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  message_generation
  tf
)

add_subdirectory(extern/serial)
include_directories(extern/serial/include)

find_package(yaml-cpp REQUIRED)
find_package (GeographicLib REQUIRED)
## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   geometry_msgs#   sensor_msgs#   std_msgs
# )

add_message_files(
    FILES
    LinktrackAnchorframe0.msg
    LinktrackNode0.msg
    LinktrackNode1.msg
    LinktrackNode2.msg
    LinktrackNodeframe0.msg
    LinktrackNodeframe1.msg
    LinktrackNodeframe2.msg
    LinktrackNodeframe3.msg
    LinktrackTag.msg
    LinktrackTagframe0.msg
    TofsenseCascade.msg
    TofsenseFrame0.msg
    LinktrackAoaNode0.msg
    LinktrackAoaNodeframe0.msg
    LinktrackNode4Anchor.msg
    LinktrackNode4Tag.msg
    LinktrackNodeframe4.msg
    LinktrackNode5.msg
    LinktrackNodeframe5.msg
    LinktrackNode6.msg
    LinktrackNodeframe6.msg
    TofsenseMFrame0.msg
    TofsenseMFrame0Pixel.msg
    IotFrame0.msg
    IotFrame0Node.msg
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES imu_single_uwb
   CATKIN_DEPENDS geometry_msgs roscpp rospy sensor_msgs std_msgs message_runtime
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${YAML_CPP_INCLUDE_DIRS}
  ${GeographicLib_INCLUDE_DIRS}
  src/utils
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/imu_single_uwb.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/imu_single_uwb_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

set(nutils "nutils")
add_library(${nutils}
    src/utils/protocol_extracter/nprotocol_base.cpp
    src/utils/protocol_extracter/nprotocol_extracter.cpp
    src/utils/nlink_unpack/nlink_utils.c
    src/utils/nlink_unpack/nlink_linktrack_anchorframe0.c
    src/utils/nlink_unpack/nlink_linktrack_tagframe0.c
    src/utils/nlink_unpack/nlink_linktrack_nodeframe0.c
    src/utils/nlink_unpack/nlink_linktrack_nodeframe1.c
    src/utils/nlink_unpack/nlink_linktrack_nodeframe2.c
    src/utils/nlink_unpack/nlink_linktrack_nodeframe3.c
    src/utils/nlink_unpack/nlink_linktrack_nodeframe4.c
    src/utils/nlink_unpack/nlink_linktrack_nodeframe5.c
    src/utils/nlink_unpack/nlink_linktrack_nodeframe6.c
    src/utils/nlink_unpack/nlink_tofsense_frame0.c
    src/utils/nlink_unpack/nlink_tofsensem_frame0.c
    src/utils/nlink_unpack/nlink_linktrack_aoa_nodeframe0.c
    src/utils/nlink_unpack/nlink_iot_frame0.c
    src/utils/init_serial.cpp
    src/utils/nlink_protocol.cpp
    src/utils/nutils.cpp
)
target_link_libraries(${nutils}
    ${catkin_LIBRARIES}
    serial
)

set(LINKTRACK_NAME "linktrack")
add_executable(${LINKTRACK_NAME}
    src/linktrack/init.cpp
    src/linktrack/main.cpp
    src/linktrack/protocols.cpp
)
target_link_libraries(${LINKTRACK_NAME}

    # ${catkin_LIBRARIES}
    ${nutils}
)
add_dependencies(${LINKTRACK_NAME} ${PROJECT_NAME}_generate_messages_cpp)

set(LINKTRACK_RVIZ_NAME "linktrack_rviz_converter")
add_executable(${LINKTRACK_RVIZ_NAME}
    src/linktrack/main_rviz_converter.cpp
)
target_link_libraries(${LINKTRACK_RVIZ_NAME}
    ${nutils}
)
add_dependencies(${LINKTRACK_RVIZ_NAME} ${PROJECT_NAME}_generate_messages_cpp)

set(TOFSENSE_NAME "tofsense")
add_executable(${TOFSENSE_NAME}
    src/tofsense/init.cpp
    src/tofsense/main.cpp
)
target_link_libraries(${TOFSENSE_NAME}

    # ${catkin_LIBRARIES}
    ${nutils}
)
add_dependencies(${TOFSENSE_NAME} ${PROJECT_NAME}_generate_messages_cpp)

set(EXE_NAME "tofsensem")
add_executable(${EXE_NAME}
    src/tofsensem/init.cpp
    src/tofsensem/main.cpp
)
target_link_libraries(${EXE_NAME}
    ${nutils}
)
add_dependencies(${EXE_NAME} ${PROJECT_NAME}_generate_messages_cpp)

set(EXE_NAME "linktrack_aoa")
add_executable(${EXE_NAME}
    src/linktrack_aoa/init.cpp
    src/linktrack_aoa/main.cpp
    src/linktrack/protocols.cpp
)
target_link_libraries(${EXE_NAME}

    # ${catkin_LIBRARIES}
    ${nutils}
)
add_dependencies(${EXE_NAME} ${PROJECT_NAME}_generate_messages_cpp)

set(EXE_NAME "iot")
add_executable(${EXE_NAME}
    src/iot/init.cpp
    src/iot/main.cpp
)
target_link_libraries(${EXE_NAME}
    ${nutils}
)
add_dependencies(${EXE_NAME} ${PROJECT_NAME}_generate_messages_cpp)

add_executable(ins_eskf_start
  src/ins_eskf_node.cpp
  src/ins_eskf_ROS_wrapper.cpp
  src/ins_eskf.cpp)
target_link_libraries(ins_eskf_start
  ${catkin_LIBRARIES}
  -lglog
  ${GeographicLib_LIBRARIES}
  ${YAML_CPP_LIBRARIES}
)

add_executable(test_initialization_start
  src/test_initialization.cpp
)
target_link_libraries(test_initialization_start
  ${catkin_LIBRARIES}
  -lglog
)


add_executable(imu2tf
  src/imu2tf.cpp
)
target_link_libraries(imu2tf
  ${catkin_LIBRARIES}
  -lglog
)
add_dependencies(imu2tf ${PROJECT_NAME}_generate_messages_cpp)
#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_imu_single_uwb.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

if(${CATKIN_ENABLE_TESTING})
    find_package(rostest REQUIRED)

    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
    # # Add gtest based cpp test target and link libraries
    catkin_add_gtest(${PROJECT_NAME}_test
        src/linktrack/init.cpp
        src/linktrack/protocols.cpp
        src/tofsense/init.cpp
        src/linktrack_aoa/init.cpp
        test/test_nlink_parser.cpp
        src/tofsensem/init.cpp
        src/iot/init.cpp
    )
endif()

if(TARGET ${PROJECT_NAME}_test)
    target_link_libraries(${PROJECT_NAME}_test ${nutils})
endif()
