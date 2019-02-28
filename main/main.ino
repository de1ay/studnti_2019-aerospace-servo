#include <Servo.h> 
#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle  nh;

Servo servo;

void servo_cb( const std_msgs::Int32& cmd_msg){
  servo.write(cmd_msg.data);
}


ros::Subscriber<std_msgs::Int32> sub("servo_cmd", servo_cb);

void setup(){

  nh.initNode();
  nh.subscribe(sub);
  
  servo.attach(9); //attach it to pin 9
  servo.write(90);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
