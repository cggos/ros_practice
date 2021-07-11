# ROS & Gazebo

* [ROS.org](http://www.ros.org/)
* [ROS Discourse](https://discourse.ros.org/)
* [ROS机器人俱乐部](http://www.rosclub.cn/)
* [eros](http://wiki.ros.org/eros)
* [ros2](https://index.ros.org/doc/ros2/)
* [ROS-Industrial](https://rosindustrial.org/)

------

[TOC]

## ROS Tutorials

* [the Construct](http://www.theconstructsim.com/): Learn to Develop for Robots with ROS
* [ros_tutorials (ROS Wiki)](http://wiki.ros.org/ros_tutorials)
* [ROS Tutorials (ClearPath)](http://www.clearpathrobotics.com/assets/guides/ros/index.html)
* [机器人操作系统入门](http://www.icourse163.org/course/ISCAS-1002580008)
* [古月居(CSDN)](https://blog.csdn.net/hcx25909)
* [ROS与navigation教程（创客智造）](https://www.ncnynl.com/category/ros-navigation/)


### Book & Code

* [Learning_ROS_for_Robotics_Programming_2nd_edition](https://github.com/AaronMR/Learning_ROS_for_Robotics_Programming_2nd_edition)

* [ROS by Example](http://wiki.ros.org/Books/ROSbyExample)
  - install rbx1
    ```sh
    git clone https://github.com/pirobot/rbx1.git
    git clone https://github.com/vanadiumlabs/arbotix_ros.git
    ```


## ROS Tips

### rosdep
* Install dependency of all packages in the workspace
  ```sh
  rosdep install --from-paths src --ignore-src -r -y
  ```

### rospack

```sh
rospack plugins --attrib=plugin costmap_2d
```

## Gazebo and ROS

### Files

* mesh files: .stl, .dae
* urdf files: .sdf, .urdf, .xacro
* world files: .world

### gazebo_ros

```sh
roslaunch gazebo_ros empty_world.launch
roslaunch gazebo_ros willowgarage_world.launch
roslaunch gazebo_ros mud_world.launch
```

### Simulations

* run gmapping with turtlebot on Gazebo
  ```sh
  roslaunch turtlebot_gazebo turtlebot_world.launch
  roslaunch turtlebot_gazebo gmapping_demo.launch
  roslaunch turtlebot_rviz_launchers view_navigation.launch

  roslaunch turtlebot_teleop keyboard_teleop.launch --screen
  ```

## ROS IDE

* CLion
  - [ROS Setup Tutorial](https://www.jetbrains.com/help/clion/ros-setup-tutorial.html)

* Qt Creator
  - [ROS Qt Creator Plug-in](https://ros-qtc-plugin.readthedocs.io)
