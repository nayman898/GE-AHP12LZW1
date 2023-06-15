#ifndef ControlButtons_h
#define ControlButtons_h

#include <LiquidCrystal.h>
#include <Arduino.h>
#include <millisDelay.h>
#include "FanMode.h"

class ControlButtons{
  public:
    ControlButtons();
    void init();
    int IncrementMode(int fanMode);
  private:
    LiquidCrystal* _lcd;
};
#endif