#include <Servo.h> 
#include <ros.h>
#include <std_msgs/Int32.h>

Servo servo;
std_msgs::Int32 angle_msg;

ros::NodeHandle  nh;
ros::Publisher cmd_echo("servo_cmd_echo", &angle_msg);

void servo_cb( const std_msgs::Int32& cmd_msg){
  servo.write(cmd_msg.data);
  angle_msg.data = cmd_msg.data;
  cmd_echo.publish(&angle_msg);
}

ros::Subscriber<std_msgs::Int32> cmd_subscribe("servo_cmd", servo_cb);

void setup(){
  nh.initNode();
  nh.advertise(cmd_echo);
  nh.subscribe(cmd_subscribe);
  
  servo.attach(9);
  servo.write(90);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
