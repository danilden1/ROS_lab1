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
    //lab_1::str3;
   // lab_1::str3 str;
   // str.first_number = "10";
   // str.second_number = "20";
    //str.sign = "+";
    std_msgs::String st;
    st.data = "Hi!";
    while(1)
    {
        //cout << str.first_number << endl;
        //cout << str.sign << endl;
        //cout << str.second_number << endl;
        pub.publish(st);
        loop_rate.sleep();
    }
    return 0;
}