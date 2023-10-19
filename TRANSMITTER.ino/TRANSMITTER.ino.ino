#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

// TRANSMITTER CODE
/* JOYSTICK CODE */

RF24 radio(8,9); // CE, CSN
const byte address[6] = "00001";
char xyData[32] = "";
String xAxis, yAxis;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  
  xAxis = analogRead(A1); // Read Joysticks
  yAxis = analogRead(A0); // Read Joysticks
  // Value X
  xAxis.toCharArray(xyData, 5); // Put the String (X Value) into a character array
  radio.write(&xyData, sizeof(xyData)); // Send the array data (X value) to the other NRF24L01 modile
  // Value Y
  yAxis.toCharArray(xyData, 5);
  radio.write(&xyData, sizeof(xyData));
  // Delay
  delay(20);
}
