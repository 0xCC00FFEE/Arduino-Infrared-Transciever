/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
int i,z=1;
unsigned int rawdata[60];
void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    Serial.print(z++);Serial.println(" - New Entry: ");
    Serial.print("Data Value: ");Serial.println(results.value,HEX);
    Serial.print("Data Length: ");Serial.println(results.rawlen);
    Serial.println("Data Raw Contents:");
    for(i=0;i<results.rawlen;i++)
    {
      if(i%2)
        rawdata[i]=results.rawbuf[i+1]*USECPERTICK-MARK_EXCESS;
      else
        rawdata[i]=results.rawbuf[i+1]*USECPERTICK+MARK_EXCESS;
      
      Serial.print(rawdata[i]);
      if(i != (results.rawlen)-1)
        Serial.print(" , ");
    }
    Serial.println("\n#########################################################################");
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
