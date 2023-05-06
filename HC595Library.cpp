#include "HC595Library.h"


  SR_HC595::SR_HC595(uint8_t Pin1_ /*Data Pin*/,uint8_t Pin2_ /*Clock Pin*/,uint8_t Pin3_ /*Latch Pin*/){
    Pin1 = Pin1_;
    Pin2 = Pin2_;
    Pin3 = Pin3_;
    pinMode(Pin1, OUTPUT);
    pinMode(Pin2, OUTPUT);
    pinMode(Pin3, OUTPUT);
    Outputs = 0;
  }
  void SR_HC595::SetOutput(int i){
    bitSet(Outputs, i);
    updateShiftRegister();
  }
  void SR_HC595::ResetOutput(int i){
    byte tempByte = 0x00;
    bitSet(tempByte, i);
    tempByte = ~tempByte;
    Outputs = Outputs & tempByte;
    updateShiftRegister();

  }
  int SR_HC595::GetStatus(void){
    return Getstatus;

  }
  void SR_HC595::updateShiftRegister(void){
   digitalWrite(Pin3, LOW);
   shiftOut(Pin1, Pin2, MSBFIRST, Outputs);
   digitalWrite(Pin3, HIGH);
  }