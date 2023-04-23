#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <vector>
#include <utility>
#include <string>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class Plan
{
public:
    Plan(const std::string&& name);
    ~Plan();
    
    inline void SubmitGoal( std::pair<int, move_base_msgs::MoveBaseGoal> goal) { m_Plan.push_back(goal);};
    inline const std::string& GetName() const { return m_Name; }

    static void Init();
    static void Shutdown();

    void Run();

private:
    std::vector<std::pair<int, move_base_msgs::MoveBaseGoal>> m_Plan;
    std::string m_Name;
    static MoveBaseClient* s_ActionClient;

};