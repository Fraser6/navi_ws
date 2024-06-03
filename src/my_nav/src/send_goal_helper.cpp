#include "send_goal_helper.h"  
  
// 实现函数  
bool sendMoveToGoal(ros::NodeHandle& nh, const std::string& action_server, const move_base_msgs::MoveBaseGoal& goal) {  
    MoveBaseClient ac(action_server, true);  
    // Wait 60 seconds for the action server to become available  
    ROS_INFO("Waiting for the move_base action server");  
    ac.waitForServer(ros::Duration(60.0));  
    ROS_INFO("Connected to move base server");  
  
    // Send a goal to move_base  
    ac.sendGoal(goal);  
    // Wait for the action to return  
    bool finished_before_timeout = ac.waitForResult(ros::Duration(300.0));  
  
    if (finished_before_timeout) {  
        if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {  
            ROS_INFO("You have reached the goal!");  
            return true;  
        } else {  
            ROS_INFO("The base failed to reach the goal for some reason");  
            return false;  
        }  
    } else {  
        ROS_INFO("Action server not available after waiting");  
        ac.cancelGoal();  
        return false;  
    }  
}
