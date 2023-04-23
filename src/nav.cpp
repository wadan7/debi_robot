#include "../include/debi_robot/Plan.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "simple_navigation_goals");
    Plan::Init();

    move_base_msgs::MoveBaseGoal baseGoal;
    baseGoal.target_pose.header.frame_id = "map";
    baseGoal.target_pose.header.stamp = ros::Time::now();   
    baseGoal.target_pose.pose.orientation.w = 1.0;  


    Plan greenBallPlan("greenBallPlan");
    move_base_msgs::MoveBaseGoal greenBallGoal;
    greenBallGoal.target_pose.header.frame_id = "map";
    greenBallGoal.target_pose.header.stamp = ros::Time::now();   
    greenBallGoal.target_pose.pose.position.x = 1.80;
    greenBallGoal.target_pose.pose.orientation.w = 1.0;
    greenBallPlan.SubmitGoal({-1, greenBallGoal});
    
    Plan redBallPlan("redBallPlan");
    move_base_msgs::MoveBaseGoal redBallOriginGoal;
    redBallOriginGoal.target_pose.header.frame_id = "map";
    redBallOriginGoal.target_pose.header.stamp = ros::Time::now();   
    redBallOriginGoal.target_pose.pose.position.y = 1.0;
    redBallOriginGoal.target_pose.pose.orientation.w = 1.0;
    move_base_msgs::MoveBaseGoal redBallSubGoal;
    redBallSubGoal.target_pose.header.frame_id = "map";
    redBallSubGoal.target_pose.header.stamp = ros::Time::now();   
    redBallSubGoal.target_pose.pose.position.y = 1.0;
    redBallSubGoal.target_pose.pose.position.x = 0.8;
    redBallSubGoal.target_pose.pose.orientation.w = 1.0;
    move_base_msgs::MoveBaseGoal redBallGoal;
    redBallGoal.target_pose.header.frame_id = "map";
    redBallGoal.target_pose.header.stamp = ros::Time::now();   
    redBallGoal.target_pose.pose.position.y = 1.0;
    redBallGoal.target_pose.pose.position.x = 1.80;
    redBallGoal.target_pose.pose.orientation.w = 1.0;
    redBallPlan.SubmitGoal({-1 , redBallOriginGoal});
    redBallPlan.SubmitGoal({-1 , redBallSubGoal});
    redBallPlan.SubmitGoal({-1 , redBallGoal});

    Plan blueBallPlan("blueBallPlan");
    move_base_msgs::MoveBaseGoal blueBallOriginGoal;
    blueBallOriginGoal.target_pose.header.frame_id = "map";
    blueBallOriginGoal.target_pose.header.stamp = ros::Time::now();   
    blueBallOriginGoal.target_pose.pose.position.y = -0.5;
    blueBallOriginGoal.target_pose.pose.orientation.w = 1.0;
    move_base_msgs::MoveBaseGoal blueBallSubGoal;
    blueBallSubGoal.target_pose.header.frame_id = "map";
    blueBallSubGoal.target_pose.header.stamp = ros::Time::now();   
    blueBallSubGoal.target_pose.pose.position.y = -0.5;
    blueBallSubGoal.target_pose.pose.position.x = 0.8;
    blueBallSubGoal.target_pose.pose.orientation.w = 1.0;
    move_base_msgs::MoveBaseGoal blueBallGoal;
    blueBallGoal.target_pose.header.frame_id = "map";
    blueBallGoal.target_pose.header.stamp = ros::Time::now();
    blueBallGoal.target_pose.pose.position.y = -0.5;
    blueBallGoal.target_pose.pose.position.x = 1.8;
    blueBallGoal.target_pose.pose.orientation.w = 1.0;
    blueBallPlan.SubmitGoal({-1 , blueBallOriginGoal});
    blueBallPlan.SubmitGoal({-1 , blueBallSubGoal});
    blueBallPlan.SubmitGoal({-1 , blueBallGoal});
    blueBallPlan.SubmitGoal({-1 , baseGoal});


    greenBallPlan.Run();
    redBallPlan.Run();
    blueBallPlan.Run();


    Plan::Shutdown();
    return 0;
}