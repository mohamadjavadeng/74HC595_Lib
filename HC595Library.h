/*
74HC595 Library for shift register IC
Created by Mohammad.J Arab
*/

#ifndef HC595_h
#define HC595_h

#include "Arduino.h"

class SR_HC595
{
  public:
  SR_HC595(uint8_t Pin1_=1 /*Data Pin*/,uint8_t Pin2_=2 /*Clock Pin*/,uint8_t Pin3_=3/*Latch Pin*/);
  void SetOutput(int i);
  void ResetOutput(int i);
  int GetStatus(void);
  void updateShiftRegister(void);
  //void SetStatus();
  //void ResetStatus();

  private:
  uint8_t Pin1,Pin2,Pin3;
  byte Outputs;
};

#endif