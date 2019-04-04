#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

std_msgs::Int16 int16;
ros::Publisher lwheel("lwheel", &int16);
ros::Publisher rwheel("rwheel", &int16);


void setup()
{
  nh.initNode();
  nh.advertise(lwheel);
  nh.advertise(rwheel);
}

void loop()
{
  int16.data = 1234;
  lwheel.publish( &int16 );
  int16.data = 4321;
  rwheel.publish( &int16 );
  nh.spinOnce();
  delay(1000);
}
