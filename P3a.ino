#include <Wire.h>
//Maestro
//Pin del botón1
const int botPin1 = 2;
//Pin del botón2
const int botPin2 = 7;
int buttonState1=0, buttonState2=0;
int st = 0;

void setup() {
  Serial.begin(9600);
 
  pinMode(botPin1, INPUT_PULLUP);
  pinMode(botPin2, INPUT_PULLUP);
  Wire.begin(8);
}

void loop() {
  buttonState1 = digitalRead(botPin1);
  buttonState2 = digitalRead(botPin2);
  Wire.beginTransmission(8);
  if((buttonState1 ==LOW)&&(buttonState2 ==LOW)){
    st = 1;
    Wire.write(st);
    Serial.println(st); 
  }else{
  if((buttonState1 ==LOW)&&(buttonState2 ==HIGH)){
    st = 2;
    Wire.write(st);
    Serial.println(st);
  }else{
    if((buttonState1 ==HIGH)&&(buttonState2 ==LOW)){
      st = 3;
      Wire.write(st);
      Serial.println(st);
    }else{
      if((buttonState1 ==HIGH)&&(buttonState2 ==HIGH)){
        st = 4;
        Wire.write(st);
        Serial.println(st);
      }
    }
  }
  }
  Wire.endTransmission();
  delay(2000);
}
