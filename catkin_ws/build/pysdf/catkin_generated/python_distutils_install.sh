#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/robot/ros_ws/catkin_ws/src/pysdf"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/robot/ros_ws/catkin_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/robot/ros_ws/catkin_ws/install/lib/python3/dist-packages:/home/robot/ros_ws/catkin_ws/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/robot/ros_ws/catkin_ws/build" \
    "/usr/bin/python3" \
    "/home/robot/ros_ws/catkin_ws/src/pysdf/setup.py" \
     \
    build --build-base "/home/robot/ros_ws/catkin_ws/build/pysdf" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/robot/ros_ws/catkin_ws/install" --install-scripts="/home/robot/ros_ws/catkin_ws/install/bin"