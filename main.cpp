#include<rec_UDP.h>
  ARRC::UDP udp1;
void setup(){
  Serial.begin(115200);
  udp1.Init("exxxx","PASS");
}
void loop(){
  float a, b, c;
  udp1.read(&a, &b, &c);
}
