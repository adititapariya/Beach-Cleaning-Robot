#include<ros.h>
#include <HCSR04.h>
#include <std_msgs/Float32.h>
HCSR04 hc(5, 6); //initialisation class HCSR04 (trig pin , echo pin)

ros::NodeHandle  nh;
std_msgs::Float32 flt_msg;
ros::Publisher chatter("chatter", &flt_msg);

void setup()
{   
    Serial.begin(9600);
    nh.initNode();
    nh.advertise(chatter);
}

void loop()
{   

    flt_msg.data = hc.dist();
    chatter.publish(&flt_msg);
    nh.spinOnce();
    Serial.println(hc.dist()); // return curent distance in serial
    delay(60);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
}
