#include "FanController.h"

FanController::FanController(){

}

millisDelay fanTimer;
millisDelay fanRunningTimer;
millisDelay fanSwitchTimer;
millisDelay compressorStartDelay;
millisDelay compressorRunDelay;
void FanController::init(){}
void FanController::setFanSpeed(int speed)
{
  if(speed == 0){
      if(fanRunningTimer.remaining() == 0.0 && digitalRead(A0) == LOW){
        fanTimer.restart();
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
      }
  }if(speed == 1){
    if(fanTimer.remaining() == 0.0 && fanSwitchTimer.remaining() == 0.0){
      fanSwitchTimer.start(2000);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
    }
  }if(speed == 2){
    if(fanTimer.remaining() == 0.0 && fanSwitchTimer.remaining() == 0.0){
      fanSwitchTimer.start(2000);
      digitalWrite(A1, LOW);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, LOW);
    }
  }if(speed == 3){
    if(fanTimer.remaining() == 0.0 && fanSwitchTimer.remaining() == 0.0){
      fanSwitchTimer.start(2000);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, HIGH);
    }
  }
}
//Fan and Compressor controllers
void FanController::setCompressor(int val){
  switch(val){
    case 0: 
      if(compressorRunDelay.remaining() == 0.0){
        digitalWrite(A0,LOW);
        compressorStartDelay.start(30000);
      }
    case 1:
      if(digitalRead(A0) == LOW && compressorStartDelay.remaining() == 0.0){
        digitalWrite(A0,HIGH);
        compressorRunDelay.start(15000);
      }
  }
}
void FanController::startfanRunningTimer(){
  if(!fanRunningTimer.remaining() == 0.0){
    fanRunningTimer.start(30000);
  }
}