#include "ControlButtons.h"

ControlButtons::ControlButtons(){
}

int ControlButtons::IncrementMode(int fanMode){
  //cycle mode
  if(fanMode < 3)
    fanMode++;
  else{
    fanMode = 0;
  }
  return fanMode;
}