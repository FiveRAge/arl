#include <ros.h>
#include <geometry_msgs/Twist.h>

double x_speed;
double z_speed;
ros::NodeHandle  nh;

void handle_cmd( const geometry_msgs::Twist& cmd_msg) {
  x_speed = cmd_msg.linear.x;
  z_speed = cmd_msg.angular.z;
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", handle_cmd);

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{ 
  analogWrite(11, x_speed);
  analogWrite(12, z_speed);
  nh.spinOnce();
  delay(1);
}


