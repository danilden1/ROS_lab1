#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"
#include "lab_1/str3.h"
using namespace std;


ros::Publisher pub;

void resultCallback(const lab_1::str3& str)
{
    cout << str.first_number << endl;
    cout << str.sign << endl;
    cout << str.second_number << endl;
    //pub.publish(str);
    return;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "str_subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/str3", 10, resultCallback);
    //ros::init(argc, argv, "result_publisher");
   // ros::NodeHandle k;
    //pub = k.advertise<lab_1::str3>("/value", 10);



    ros::spin();

    return 0;
}