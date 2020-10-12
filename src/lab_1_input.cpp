#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"
#include "lab_1/str3.h"
using namespace std;


int main(int argc, char **argv)
{
    ros::init(argc, argv, "str_publisher");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::String>("/str", 10);
    ros::Rate loop_rate(1);
    std_msgs::String st;
    st.data = "Hi!";
    while(1)
    {
        cout << st << endl;
        pub.publish(st);
        loop_rate.sleep();
    }
    return 0;
}