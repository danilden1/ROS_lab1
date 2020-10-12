#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"
#include "lab_1/str3.h"
using namespace std;


int main(int argc, char **argv)
{
    ros::init(argc, argv, "str_publisher");
    ros::NodeHandle n;
    //ros::Publisher pub = n.advertise<std_msgs::String>("/str", 10);
    ros::Publisher pub = n.advertise<lab_1::str3>("/input", 10);
    ros::Rate loop_rate(1);
    //lab_1::str3;
    lab_1::str3 str;

    //str.first_number = "10";
    //str.second_number = "20";
    //str.sign = "+";
    //std_msgs::String st;
   // st.data = "Hi!";

    int firs_value = 0;
    int last_value = 10000;
    while(1)
    {
        double random_number_first = (firs_value + rand() % last_value) / 100;
        double random_number_second = (firs_value + rand() % last_value) / 100;

        str.first_number = std::to_string(random_number_first);
        str.second_number = std::to_string(random_number_second);

        int random_number_sign = 1 + rand() % 4;
        switch (random_number_sign)
        {
            case 1:
            {
                str.sign = "+";
                break;
            }
            case 2:
            {
                str.sign = "-";
                break;
            }
            case 3:
            {
                str.sign = "*";
                break;
            }
            case 4:
            {
                str.sign = "/";
                break;
            }
        }
        cout << str.first_number << " ";
        cout << str.sign << " ";
        cout << str.second_number << endl;
        pub.publish(str);
        loop_rate.sleep();
    }
    return 0;
}