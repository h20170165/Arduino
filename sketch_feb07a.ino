#include <VirtualWire.h>
char msg[3];
int duration;
int distance;
int count;
void setup()
{
pinMode(8,OUTPUT);
pinMode(3,INPUT);
Serial.begin(9600);
vw_setup(2000); // Bits per sec
count=0;
}
void loop()
{
digitalWrite(8,LOW);
delayMicroseconds(2);
digitalWrite(8,HIGH);
delayMicroseconds(10);
digitalWrite(8,LOW);

duration=pulseIn(3,HIGH);
distance=(duration*.0343)/2;
if(count==0)
{
    Serial.write(13);
txmit_distance(distance);
}
count=(count+1)%100;
}
void txmit_distance(int distance)
{
   Serial.println(distance);
   msg[2]=distance%10+48;
   distance/=10;
   msg[1]=distance%10+48;
   msg[0]=distance/10+48;
   vw_send((uint8_t *)msg, strlen(msg));
   //vw_wait_tx();
}
