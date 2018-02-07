#include <VirtualWire.h>
byte msg[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming message
byte len=VW_MAX_MESSAGE_LEN;
void setup()
{
Serial.begin(9600);
Serial.println("Device is ready");
// Initialize the IO and ISR
vw_setup(2000); // Bits per sec
vw_rx_start(); // Start the receiver
pinMode(2,OUTPUT);
digitalWrite(2,LOW);
}
void loop()
{
if (vw_get_message(msg, &len))
{
for(int i=0;i<len;++i)
Serial.print(char(msg[i]));
Serial.println();
if(msg[2]=='0' && msg[1]<'5')
  digitalWrite(2,HIGH);
else
 digitalWrite(2,LOW);   
}
}

