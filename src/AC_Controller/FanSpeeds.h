#ifndef FanSpeeds_h
#define FanSpeeds_h

#include <LiquidCrystal.h>
#include <Arduino.h>
#include <millisDelay.h>

class FanSpeeds{
  public:
    FanSpeeds(FanController* fanController, LiquidCrystal* lcd);
    void init();
    void LowFanLoop();
    void MediumFanLoop();
    void HighFanLoop();
    void AutoFanLoop();
    float tempF;
    int desiredTemp;
  private:
    LiquidCrystal* _lcd;
};
#endif