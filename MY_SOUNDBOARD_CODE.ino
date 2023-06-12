//David Luis Contreras
//SoundBoard Code
//March 29 2023

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#define ACTIVATED LOW
int buttonpin2 = 6;
int buttonpin3 = 5;
int buttonpin4 = 4;


static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 3; // Connects

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

DFRobotDFPlayerMini player;

void setup() {
pinMode(buttonpin2, INPUT);
digitalWrite(buttonpin2,HIGH);
pinMode(buttonpin3, INPUT);
digitalWrite(buttonpin3,HIGH);
pinMode(buttonpin4, INPUT);
digitalWrite(buttonpin4,HIGH);


  Serial.begin(9600);
 
  softwareSerial.begin(9600);



  if (player.begin(softwareSerial)) {
   Serial.println("OK");

  }
    player.volume(30); 
   
}

void loop() {
   
 if (digitalRead(buttonpin2) == ACTIVATED){
     player.play(1); //Here we are playing the first audio found in our Mp3 file
     delay(100);
  }
  else if (digitalRead(buttonpin3) == ACTIVATED){
    player.play(2);
    delay(100);
  }
  else if (digitalRead(buttonpin4) == ACTIVATED){
    player.play(3);
    delay(100);
  }
}
