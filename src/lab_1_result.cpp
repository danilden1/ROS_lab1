#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"
#include "lab_1/str3.h"
using namespace std;

struct st
{
    double fn;
    double sn;
    char sign;
    double res;
};

st answer;
ros::Publisher pub;
//ros::NodeHandle n;
//ros::NodeHandle k;


void resultCallback(const lab_1::str3& str)
{
    cout << str.first_number << " ";
    cout << str.sign << " ";
    cout << str.second_number << " = ";

    int zeroFlag = 0;

    std_msgs::String resString;
    answer.fn = std::stod(str.first_number);
    answer.sn = std::stod(str.second_number);
    answer.sign = str.sign[0];
    answer.res = 0.0;
    switch (answer.sign)
    {
        case 0x2B:
        {
            answer.res = answer.fn + answer.sn;
            break;
        }
        case 0x2D:
        {
            answer.res = answer.fn - answer.sn;
            break;
        }
        case 0x2A:
        {
            answer.res = answer.fn * answer.sn;
            break;
        }
        case 0x2F:
        {
            if (answer.sn == 0.0)
            {
                zeroFlag = 1;
            }else
            {
                answer.res = answer.fn / answer.sn;
            }
            break;
        }
    }
    cout << answer.res << endl;
    if(zeroFlag)
    {
        resString.data = "Nan";
    }
    else
    {
        resString.data = std::to_string(answer.res);
    }
    pub.publish(resString);
    return;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "str_subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/input", 10, resultCallback);
    ros::init(argc, argv, "result_publisher");
    ros::NodeHandle k;
    //ros::Publisher pub;
    pub = k.advertise<std_msgs::String>("/result", 10);



    ros::spin();

    return 0;
}