#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>

void map_cb(const nav_msgs::OccupancyGrid::ConstPtr& msg) {
    ROS_INFO("I heard: %d, %d",msg->info.width, msg->data[0]);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "read_map");

    ros::NodeHandle n;
    
    ros::Subscriber map_sub = n.subscribe<nav_msgs::OccupancyGrid>("map", 1000, map_cb);

    ros::Rate r(10);
    while (ros::ok()) {
        ros::spinOnce();
        r.sleep();
    }
}
