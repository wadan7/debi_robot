#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <utility>

class Claw
{
public:
    Claw() = delete;
    Claw(Claw&) = delete;
    void operator=(const Claw&) = delete;
    
    static void Init();
    static void Shutdown();
    static void Open();
    static void Close();

private:


private:
    static ros::NodeHandle* s_NodeHandle;
    static std::pair<ros::Publisher*, ros::Publisher*> s_Publishers;
    static std::pair<std_msgs::Float64, std_msgs::Float64> s_OpenAngles;
    static std::pair<std_msgs::Float64, std_msgs::Float64> s_CloseAngles;
};