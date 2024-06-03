#include <ros/ros.h>  
#include "send_goal_helper.h"  
#include <move_base_msgs/MoveBaseAction.h>  
  
int main(int argc, char** argv) {  
    ros::init(argc, argv, "send_goals_node");  
  
    ros::NodeHandle nh;  
  
    // 设置目标  
    move_base_msgs::MoveBaseGoal goal;  
    goal.target_pose.header.frame_id = "map";  
    goal.target_pose.header.stamp = ros::Time::now();  
    goal.target_pose.pose.position.x = 2;  
    goal.target_pose.pose.position.y = 0;  
    goal.target_pose.pose.position.z = 0; // 注意：对于平面移动，z通常为0  
    goal.target_pose.pose.orientation.w = 1.0;  
  
    // 调用封装好的函数  
    bool success = sendMoveToGoal(nh, "move_base", goal);  
  
    return 0;  
}
