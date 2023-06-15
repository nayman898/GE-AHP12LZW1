#ifndef FanController_h
#define FanController_h


#include <Arduino.h>
#include <millisDelay.h>

class FanController{
  public:
    FanController();
    void init();
    void setFanSpeed(int speed);
    void setCompressor(int val);
    void startfanRunningTimer();
};
#endif