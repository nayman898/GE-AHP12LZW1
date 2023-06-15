#include <LiquidCrystal.h>
#include <DHT11.h>
#include <millisDelay.h>
#include "FanMode.h"
#include "CompressorMode.h"
#include "FanController.h"
#include "FanSpeeds.h"
#include "ControlButtons.h"


// Create an instance of the DHT11 class and set the digital I/O pin.
DHT11 dht11(7);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int desiredTemp = 69.0;
float tempF;
FanMode fanMode = Auto;

FanController  fanController = FanController();
FanSpeeds fanSpeeds = FanSpeeds(&fanController, &lcd);
ControlButtons controlButtons = ControlButtons();

void setup(){
  lcd.begin(16, 2);
  //compressor
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  //low speed
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
  //medium speed
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  //high speed
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);

  //fan speed button
  pinMode(8, INPUT);
  
}

void loop(){
  float temperature = dht11.readTemperature();
  fanSpeeds.tempF = (temperature *9/5) + 32;
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(fanSpeeds.tempF);
  lcd.print((char)223);
  lcd.print("F");
  lcd.print(" ");
  lcd.print(fanSpeeds.desiredTemp);
  
  int modeBtn = digitalRead(8);
  if(modeBtn == HIGH){
    fanMode = controlButtons.IncrementMode(fanMode);
  }
  int tempUp = digitalRead(9);
  if(tempUp == HIGH){
    fanSpeeds.desiredTemp++;
  }
  int tempDown = digitalRead(10);
  if(tempDown == HIGH){
    fanSpeeds.desiredTemp--;
  }

  if(fanMode == Auto){
    fanSpeeds.AutoFanLoop();
  }
  else if(fanMode == Low){
    fanSpeeds.LowFanLoop();
  }
  else if(fanMode == Medium){
    fanSpeeds.MediumFanLoop();
  }
  else if(fanMode == High){
    fanSpeeds.HighFanLoop();
  }  
}

