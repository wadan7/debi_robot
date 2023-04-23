#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node");
    ros::NodeHandle nodeHandle;

    ros::Publisher rightHandPublisher = nodeHandle.advertise<std_msgs::Float64>("right_hand_controller/command", 1000);
    ros::Publisher leftHandPublisher = nodeHandle.advertise<std_msgs::Float64>("left_hand_controller/command", 1000);

    ros::Rate loop_rate(30);
    int counter = 0;

    std_msgs::Float64 openAngles[2];
    openAngles[0].data = 0.0;
    openAngles[1].data = 0.0;

    std_msgs::Float64 closeAngles[2];
    closeAngles[0].data = 1.2;
    closeAngles[1].data = -1.2;

    bool state = 0;

    while (ros::ok())
    {
        if(counter % 30 == 0)
            state = !state;
        
        if(state)
        {
            rightHandPublisher.publish(openAngles[0]);
            leftHandPublisher.publish(openAngles[1]);
        }
        else if (!state)
        {
            rightHandPublisher.publish(closeAngles[0]);
            leftHandPublisher.publish(closeAngles[1]);
        }

        ros::spinOnce();
        loop_rate.sleep();
        counter++;
    }


    return 0;
}