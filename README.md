# ROS Practice

* [ROS.org](http://www.ros.org/)
* [ROS Discourse](https://discourse.ros.org/)
* [ROS机器人俱乐部](http://www.rosclub.cn/)
* [eros](http://wiki.ros.org/eros)
* [ros2](https://index.ros.org/doc/ros2/)

------

[TOC]

## ROS Tutorials

* [the Construct](http://www.theconstructsim.com/): Learn to Develop for Robots with ROS
* [ros_tutorials (ROS Wiki)](http://wiki.ros.org/ros_tutorials)
* [ROS Tutorials (ClearPath)](http://www.clearpathrobotics.com/assets/guides/ros/index.html)
* [机器人操作系统入门](http://www.icourse163.org/course/ISCAS-1002580008)


### Code

* [Learning_ROS_for_Robotics_Programming_2nd_edition](https://github.com/AaronMR/Learning_ROS_for_Robotics_Programming_2nd_edition)
* [ROS by Example](http://wiki.ros.org/Books/ROSbyExample)
  - install rbx1
    ```bash
    git clone https://github.com/pirobot/rbx1.git
    git clone https://github.com/vanadiumlabs/arbotix_ros.git
    ```


## ROS Tips

### rosdep
* Install dependency of all packages in the workspace
  ```bash
  rosdep install --from-paths src --ignore-src -r -y
  ```

### rospack
```
rospack plugins --attrib=plugin costmap_2d
```
