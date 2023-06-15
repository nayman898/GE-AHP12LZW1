#include <LiquidCrystal.h>
#include <DHT11.h>
#include <millisDelay.h>

// Create an instance of the DHT11 class and set the digital I/O pin.
DHT11 dht11(7);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

millisDelay compressorStartDelay;
millisDelay compressorRunDelay;
millisDelay fanTimer;
millisDelay fanRunningTimer;

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
  fanTimer.start(5000);
}

void loop(){
  float temperature = dht11.readTemperature();
  float tempF = (temperature *9/5) + 32;
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(tempF);
  lcd.print((char)223);
  lcd.print("F");

  if(tempF > 71.0 && tempF < 72.9){
    //turn fan on
    startfanRunningTimer();
    setSpeed(1);
    setCompressor(1);
    lcd.setCursor(0,1);
    lcd.print("Speed: ");
    lcd.print("1");
  }
  else if(tempF > 73.0 && tempF < 74.9){
    startfanRunningTimer();
    setSpeed(2);
    setCompressor(1);
    lcd.setCursor(0,1);
    lcd.print("Speed: ");
    lcd.print("2");
  }
  else if(tempF > 75.0){
    startfanRunningTimer();
    setSpeed(3);
    setCompressor(1);
    lcd.setCursor(0,1);
    lcd.print("Speed: ");
    lcd.print("3");
  }
  else{
    //turn everything off
    setSpeed(0);
    setCompressor(0);
    lcd.setCursor(0,1);
    lcd.print("Speed: ");
    lcd.print("0");
  }
}
void startfanRunningTimer(){
  if(!fanRunningTimer.remaining() == 0.0){
    fanRunningTimer.start(15000);
  }
}
void setCompressor(int val){
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
void setSpeed(int speed){
  if(speed == 0){
      if(fanRunningTimer.remaining() == 0.0){
        fanTimer.restart();
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
      }
  }if(speed == 1){
    if(fanTimer.remaining() == 0.0){
      digitalWrite(A1, HIGH);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
    }
  }if(speed == 2){
    if(fanTimer.remaining() == 0.0){
      digitalWrite(A1, LOW);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, LOW);
    }
  }if(speed == 3){
    if(fanTimer.remaining() == 0.0){
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, HIGH);
    }
  }
}
