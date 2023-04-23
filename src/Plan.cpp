#include "../include/debi_robot/Plan.h"
#include "../include/debi_robot/Claw.h"


MoveBaseClient* Plan::s_ActionClient = nullptr;

Plan::Plan(const std::string&& name)
    :m_Name(name)
{
}
Plan::~Plan()
{

}

void Plan::Init()
{
    Claw::Init();
    //tell the action client that we want to spin a thread by default
    Plan::s_ActionClient = new MoveBaseClient("move_base", true);   
    //wait for the action server to come up
    
    while(! Plan::s_ActionClient->waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
    }  
}
void Plan::Shutdown()
{
    delete Plan::s_ActionClient;
    Claw::Shutdown();
}

void Plan::Run()
{
    for(const auto& pair : m_Plan)
    {
        if(pair.first == 1)
        {
            Claw::Open();
            ros::Duration(1.0).sleep();
        }
        else if (pair.first == 0)
        {
            Claw::Close();
            ros::Duration(1.0).sleep();
        }


        ROS_INFO("Sending goal");
        Plan::s_ActionClient->sendGoal(pair.second);  
        Plan::s_ActionClient->waitForResult(); 
        
        if(Plan::s_ActionClient->getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
            ROS_INFO("Hooray, the base moved 1 meter forward");
        else
            ROS_INFO("The base failed to move forward 1 meter for some reason");  

    }

}