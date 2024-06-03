#ifndef SEND_GOAL_HELPER_H  
#define SEND_GOAL_HELPER_H  
  
#include <ros/ros.h>  
#include <move_base_msgs/MoveBaseAction.h>  
#include <actionlib/client/simple_action_client.h>  
  
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;  
  
// 声明函数  
bool sendMoveToGoal(ros::NodeHandle& nh, const std::string& action_server, const move_base_msgs::MoveBaseGoal& goal);  
  
#endif // SEND_GOAL_HELPER_H
