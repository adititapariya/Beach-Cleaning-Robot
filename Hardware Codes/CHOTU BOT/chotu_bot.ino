#include <ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

int mpwm1 =5;
int mdir1 =4;
int mpwm2 =9;
int mdir2 =8;

ros::NodeHandle  nh;

float u,v,vel1,vel2;
void messageCb( const geometry_msgs::Twist &msg1){
    u=msg1.linear.x;
    v=msg1.angular.z;
    vel1=(u+v)*180.3;
    vel2=(u-v)*180.3;

     if(vel1>=0 && vel2>=0)    //upper
     {
      analogWrite(5,abs(vel1));
      digitalWrite(4,LOW);
      analogWrite(9,abs(vel2));
      digitalWrite(8,HIGH); 
     }

     else if(vel1>=0 && vel2<=0)   //right
     {
      analogWrite(5,abs(vel1));
      digitalWrite(4,LOW);
      analogWrite(9,abs(vel2));               //set according to hardware directions!!
      digitalWrite(8,LOW); 
     }

     else if(vel1<=0 && vel2>=0)    //left
     {
      analogWrite(5,abs(vel1));
      digitalWrite(4,HIGH);
      analogWrite(9,abs(vel2));
      digitalWrite(8,HIGH); 
     }

     else if(vel1<=0 && vel2<=0)    //lower
     {
      analogWrite(5,abs(vel1));
      digitalWrite(4,HIGH);
      analogWrite(9,abs(vel2));
      digitalWrite(8,LOW); 
     }
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );


void setup()
{
  pinMode(mpwm1,OUTPUT);
  pinMode(mdir1,OUTPUT);
  pinMode(mpwm2,OUTPUT);
  pinMode(mdir2,OUTPUT);
  nh.initNode();
  nh.getHardware()->setBaud(115200);
  Serial.begin(115200);
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(500);
}
