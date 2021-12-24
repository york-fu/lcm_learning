#include <iostream>
#include <unistd.h>
#include <lcm/lcm-cpp.hpp>
#include "example_msgs/Test.hpp"

class MsgHandler
{
public:
  void exampleCallback(const lcm::ReceiveBuffer *rbuf, const std::string &channel, const example_msgs::Test *msg)
  {
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);
    // std::cout << "sec:" << tv.tv_sec << ",nsec:" << tv.tv_nsec << "\n";
    double time = (tv.tv_sec + tv.tv_nsec * 1e-9) - (msg->sec + msg->nsec * 1e-9);
    std::cout << "transmit time(ms):" << time * 1000.0 << "\n";
    std::cout << "flag:" << (int16_t)msg->flag << "\n";
    std::cout << "num:" << msg->num << "\n";
    std::cout << "str:" << msg->str << "\n";
    std::cout << "vec3d:" << msg->vec3d[0] << ", " << msg->vec3d[1] << ", " << msg->vec3d[2] << "\n";
    std::cout << "size:" << msg->size << "\n";
    std::cout << "vecXd:";
    for (uint32_t i = 0; i < msg->size; i++)
    {
      std::cout << "  " << msg->vecXd[i];
    }
    std::cout << "\n\n";
  }
};

int main(int argv, char **argc)
{
  lcm::LCM lcm;
  if (!lcm.good())
  {
    return -1;
  }

  MsgHandler handlerObj;
  lcm.subscribe("example", &MsgHandler::exampleCallback, &handlerObj);

  while (0 == lcm.handle())
  {
    usleep(1);
  }

  return 0;
}
