#include <ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

int mpwm1 =5;
int mdir1 =4;
int mpwm2 =9;
int mdir2 =8;

ros::NodeHandle  nh;

float p,q,vel1,vel2;
void messageCb( const sensor_msgs::Joy &msg1){
    msg1.axes[0]=p;
    msg1.axes[3]=q;
    vel1=(p+q)*180.3;
    vel2=(p-q)*180.3;

     if(vel1>=0 && vel2>=0)    //upper
     {
      analogWrite(5,abs(vel1));4
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

ros::Subscriber<sensor_msgs::Joy> sub("joy", &messageCb );


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
