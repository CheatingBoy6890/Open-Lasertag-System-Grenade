#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>

#define NUMLEDS 8
#define LEDPIN 7
#define RECEIVERPIN 6
#define Button 5
#define IRPIN 9
#define dammage 15
int teamColor [4]{
0xff0000,
0x0000ff,
0xffff00,
0x00ff00


};

uint8_t team;
uint8_t playerID;
decode_results results;

bool volatile  goBooom;

Adafruit_NeoPixel pixels(NUMLEDS,LEDPIN,NEO_GRB +NEO_KHZ800);
IRrecv receiver(RECEIVERPIN);
IRsend transmitter(IRPIN);

 void  IRAM_ATTR   buttonInterrupt();
 void booom ();


 

// put function declarations here:
int myFunction(int, int);


void setup() {
pixels.begin();
pixels.fill(0xffffff);
pixels.show();
receiver.enableIRIn();
attachInterrupt(digitalPinToInterrupt(Button),buttonInterrupt,FALLING);
}

void loop() {
  delay(1);
 while (team==NULL||playerID==NULL)
 {
  if(receiver.decode(&results)){
if(results.decode_type==MILESTAG2){
team=results.command >> 4;
playerID=results.address;
pixels.setBrightness(50);
pixels.fill(teamColor[team]);
pixels.show();

}
  }
 }





}

void IRAM_ATTR buttonInterrupt(){
goBooom=1;

}
void booom(){
if(goBooom){
  pixels.setBrightness(255);
for(int i =200;i>0; i--){
pixels.fill(teamColor[team]);
pixels.show();
delay(i);
pixels.fill();
pixels.show();
delay(i);



}
pixels.fill(teamColor[team]);
pixels.show();
  uint32_t data = 0;
  data = playerID;
  data = data << 2;
  data = data + team;
  data = data << 4;
  data = data + dammage;
  // transmitter.sendMilestag2(data);
  transmitter.sendMilestag2(data, 14, 0);

goBooom=0;
pixels.fill();
pixels.show();


}
}