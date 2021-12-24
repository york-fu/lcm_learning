#include <iostream>
#include <unistd.h>
#include <lcm/lcm-cpp.hpp>
#include "lcm_std_msgs/Float32.hpp"
#include "example_msgs/Test.hpp"

int main(int argv, char **argc)
{
  lcm::LCM lcm;
  if(!lcm.good())
  {
    return -1;
  }
  
  lcm_std_msgs::Float32 f32Msg;
  f32Msg.data = 1.23;

  example_msgs::Test msg;
  msg.flag = true;
  msg.num = 1;
  msg.str = "string";

  msg.vec3d[0] = 1.1;
  msg.vec3d[1] = 2.2;
  msg.vec3d[2] = 3.3;

  msg.size = 4;
  msg.vecXd.resize(msg.size);
  msg.vecXd[0] = 1.1;
  msg.vecXd[1] = 2.2;
  msg.vecXd[2] = 3.3;
  msg.vecXd[3] = 4.4;

  struct timespec tv;

  while (1)
  {
    clock_gettime(CLOCK_MONOTONIC, &tv);
    // std::cout << "sec:" << tv.tv_sec << ",nsec:" << tv.tv_nsec << "\n";
    msg.sec = tv.tv_sec;
    msg.nsec = tv.tv_nsec;
    lcm.publish("example", &msg);
    lcm.publish("float32", &f32Msg);
    sleep(1);
  }

  return 0;
}
