#include "FanController.h"
#include "FanSpeeds.h"
#include "CompressorMode.h"
FanController* _fanController;
LiquidCrystal* _lcd;
CompressorMode compressorMode = ON;


FanSpeeds::FanSpeeds(FanController* fanController, LiquidCrystal* lcd1){
  desiredTemp = 69;
  _fanController = fanController;
  _lcd = lcd1;
}


void FanSpeeds::LowFanLoop(){
  //fan always on in low
  _fanController->startfanRunningTimer();
  _fanController->setFanSpeed(1);
  if(tempF > (desiredTemp + 2.0) && compressorMode == ON){
    //turn compressor on
    _fanController->setCompressor(1);
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("1         ");
  }
  else{
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("1 - No AC");
  }
}
void FanSpeeds::MediumFanLoop(){
  //fan always on in low
  _fanController->startfanRunningTimer();
  _fanController->setFanSpeed(2);
  if(tempF > (desiredTemp + 2.0) && compressorMode == ON){
    //turn compressor on
    _fanController->setCompressor(1);
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("2         ");
  }
  else{
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("2 - No AC");
  }
}
void FanSpeeds::HighFanLoop(){
  //fan always on in low
  _fanController->startfanRunningTimer();
  _fanController->setFanSpeed(3);
  if(tempF > (desiredTemp + 2.0) && compressorMode == ON){
    //turn compressor on
    _fanController->setCompressor(1);
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("3         ");
  }
  else{
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("3 - No AC");
  }
}

void FanSpeeds::AutoFanLoop(){
  // Auto Fan control loop
  if(tempF > (desiredTemp - 4) && tempF < (desiredTemp + 0.9)){
    //turn fan on
    _fanController->startfanRunningTimer();
    _fanController->setFanSpeed(1);
    _fanController->setCompressor(0);
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("1 - No AC");

  }else if(tempF > (desiredTemp + 1.0) && tempF < (desiredTemp + 2.9)){
    //turn fan on
    _fanController->startfanRunningTimer();
    _fanController->setFanSpeed(1);
    _fanController->setCompressor(1);
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("1         ");
  }
  else if(tempF > (desiredTemp + 3.0) && tempF < (desiredTemp + 4.9)){
    _fanController->startfanRunningTimer();
    _fanController->setFanSpeed(2);
    _fanController->setCompressor(1);
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("2         ");
  }
  else if(tempF > (desiredTemp + 5.0)){
    _fanController->startfanRunningTimer();
    _fanController->setFanSpeed(3);
    _fanController->setCompressor(1);
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("3         ");
  }
  else{
    //turn everything off
    _fanController->setFanSpeed(0);
    _fanController->setCompressor(0);
    _lcd->setCursor(0,1);
    _lcd->print("Speed: ");
    _lcd->print("0         ");
  }
}