#include "HC595Library.h"

SR_HC595 sr_hc595(D1, D2, D3);
String str;

void setup() {
  Serial.begin(9600);
  Serial.println("Shift register Start...");
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i < 8; i++){
    str = "Output " + String(i) + " is set...!";
    sr_hc595.SetOutput(i);
    Serial.println(str);
    delay(1000);
  }
  for(int i = 7; i >=0 ; i--){
    str = "Output " + String(i) + " is reset...!";
    sr_hc595.ResetOutput(i);
    Serial.println(str);
    delay(1000);
  }
}
