#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/OccupancyGrid.h>
#include <geometry_msgs/PoseStamped.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <iomanip>

ros::Publisher pub_path;

void map_cb(const nav_msgs::OccupancyGrid::ConstPtr& msg) {

    ROS_INFO("map size: (%d, %d)", msg->info.width, msg->info.height);

    int width  = msg->info.width;
    int height = msg->info.height;

    cv::Mat mat_map(height, width, CV_8UC1);

    for(int h=0; h<height; ++h) {
        for(int w=0; w<width; ++w) {
            int value = msg->data[h*width+w];
            if(value == -1) value = 128;
            mat_map.at<unsigned char>(h, w) = value;
        }
    }
    
    int threshold = 50;
    cv::Mat mat_edge;
    cv::Canny(mat_map, mat_edge, threshold, threshold*3, 3);


    nav_msgs::Path path_msg;

    path_msg.header.frame_id = "base_laser_link";
    path_msg.header.stamp    = ros::Time::now();

    geometry_msgs::PoseStamped pose_stamped;
    pose_stamped.pose.orientation.x = 0.0;
    pose_stamped.pose.orientation.y = 0.0;
    pose_stamped.pose.orientation.z = 0.0;
    pose_stamped.pose.orientation.w = 1.0;

    pose_stamped.pose.position.x = 0;
    pose_stamped.pose.position.y = 0;
    
    path_msg.poses.emplace_back(pose_stamped);

    pub_path.publish(path_msg);


    for(int h=0; h<height; h+=3) {
        for(int w=0; w<width; w+=3) 
            std::cout << std::setw(4) << std::left << (int)mat_map.at<unsigned char>(h, w);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    cv::imshow("", mat_edge);
    cv::waitKey(30);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "read_map");

    ros::NodeHandle nh;
    
    ros::Subscriber map_sub = nh.subscribe<nav_msgs::OccupancyGrid>("map", 1000, map_cb);

    pub_path = nh.advertise<nav_msgs::Path>("path", 1); 

    ros::Rate r(10);
    while (ros::ok()) {
        ros::spinOnce();
        r.sleep();
    }
}
