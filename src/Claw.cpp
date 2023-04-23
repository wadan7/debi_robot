#include "../include/debi_robot/Claw.h"


ros::NodeHandle* Claw::s_NodeHandle = nullptr;
std::pair<ros::Publisher*, ros::Publisher*> Claw::s_Publishers = {nullptr, nullptr};
std::pair<std_msgs::Float64, std_msgs::Float64> Claw::s_OpenAngles;
std::pair<std_msgs::Float64, std_msgs::Float64> Claw::s_CloseAngles;


void Claw::Init()
{
    
    s_NodeHandle = new ros::NodeHandle();
    s_Publishers.first = new ros::Publisher();
    *s_Publishers.first = s_NodeHandle->advertise<std_msgs::Float64>("right_hand_controller/command", 1000);
    s_Publishers.second = new ros::Publisher();
    *s_Publishers.second = s_NodeHandle->advertise<std_msgs::Float64>("left_hand_controller/command", 1000);

    s_OpenAngles.first.data = 0.0;
    s_OpenAngles.second.data = 0.0;

    s_CloseAngles.first.data = 1.25;
    s_CloseAngles.second.data = -1.25;

}
void Claw::Shutdown()
{
    delete s_NodeHandle;
    delete s_Publishers.first;
    delete s_Publishers.second;
}
void Claw::Open()
{
    s_Publishers.first->publish(s_OpenAngles.first);
    s_Publishers.second->publish(s_OpenAngles.second);
}

void Claw::Close()
{
    s_Publishers.first->publish(s_CloseAngles.first);
    s_Publishers.second->publish(s_CloseAngles.second);
}