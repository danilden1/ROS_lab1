#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"
#include "lab_1/str3.h"
using namespace std;


ros::Publisher pub;

void recieve(const std_msgs::String& str)
{
    cout << str.data << endl;
    pub.publish(str);
    return;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "string_subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/str", 10, recieve);
    ros::init(argc, argv, "string_publisher");
    ros::NodeHandle k;
    pub = k.advertise<std_msgs::String>("/value", 10);

    ros::spin();

    return 0;
}