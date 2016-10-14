#include <IRremoteInt.h>
#include <IRremote.h>


/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */


IRsend irsend;

void setup()
{

}
int i;
void loop() {
  delay(5000);
  unsigned int irSignalTV[] = {4100 , 3850 , 600 , 1900 , 600 , 1900 , 600 , 1950 , 550 , 1950 , 600 , 900 , 650 , 850 , 650 , 1850 , 600 , 900 , 650 , 1850 , 650 , 900 , 600 , 1900 , 600 , 900 , 650 , 850 , 650 , 850 , 650 , 850 , 650 , 900 , 600 , 1900 , 550 , 1950 , 650 , 850 , 600 , 1900 , 600 , 900 , 650 , 1850 , 600 , 950 , 600 , 1900 , 500 , 65436};
  irsend.sendRaw(irSignalTV,52,38);
  delay(5000); //In this example, the signal will be repeated every 20 seconds, approximately.
}
