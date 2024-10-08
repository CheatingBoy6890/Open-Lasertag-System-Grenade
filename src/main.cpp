#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
// #include <ESP8266Audio.h>
#include <AudioFileSourceLittleFS.h>
#include <AudioGeneratorWAV.h>
#include <AudioOutputI2SNoDAC.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>

#define NUMLEDS 8
#define LEDPIN D2
#define RECEIVERPIN D1
#define Button D3
#define IRPIN D4
#define dammage 15

uint32_t teamColor[4]{
    0xff0000,
    0x0000ff,
    0xffff00,
    0x00ff00

};

uint8_t team;
uint8_t playerID;
decode_results results;

bool volatile goBooom = 0;
bool isConnected = 0;

float voltage;
Adafruit_NeoPixel pixels(NUMLEDS, LEDPIN, NEO_GRB + NEO_KHZ800);
IRrecv receiver(RECEIVERPIN);
IRsend transmitter(IRPIN);
AudioFileSourceLittleFS *file;
AudioGeneratorWAV *decoder;
AudioOutputI2SNoDAC *output;

// void IRAM_ATTR buttonInterrupt();
void booom();

void setup()
{
  Serial.begin(115200);
  Serial.println("Seial has bagun");
  pixels.begin();
  pixels.fill(0xffffff);
  pixels.show();
  receiver.enableIRIn();
  // attachInterrupt(digitalPinToInterrupt(Button), buttonInterrupt, FALLING);
  pinMode(Button, INPUT_PULLUP);
  pinMode(A0, INPUT);
  transmitter.begin();
  LittleFS.begin();
  file = new AudioFileSourceLittleFS("/explode.wav");
  decoder = new AudioGeneratorWAV();
  output = new AudioOutputI2SNoDAC();
  pinMode(D7, INPUT); // On the first version PCB the sound is connected to D7 which is useless since only RX can be the AudioOutput. Setting D7 as an Input prevents a short, since it should have a very high input resistans
  decoder->begin(file, output);
  decoder->SetBufferSize(512);
  output->SetGain(1);
  output->SetOutputModeMono(true);
}

void loop()
{
  voltage = analogRead(A0) * 0.005394;

  delay(100);
  Serial.println(digitalRead(Button));
  while (!isConnected)
  {
    Serial.println("Connection loop");
    if (receiver.decode(&results))
    {

      if (results.decode_type == MILESTAG2)
      {
        team = results.command >> 4;
        playerID = results.address;
        pixels.setBrightness(50);
        pixels.fill(teamColor[team]);
        pixels.show();
        Serial.print("set id and team to");
        Serial.print("Team:");
        Serial.println(team);
        Serial.printf("PlayerID:%i\n", playerID);
        isConnected = true;
      }
      receiver.resume();
    }
    delay(100);
  }
  booom();
}

/*void IRAM_ATTR buttonInterrupt()
{
  goBooom = 1;
} */
void booom()
{
  if (digitalRead(Button) == 0)
  {
    pixels.setBrightness(255);
    for (int i = 200; i > 0; i -= 10)
    {
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
    decoder->stop();
    decoder->begin(file, output);
    decoder->loop();
    goBooom = 0;
    pixels.fill();
    pixels.show();
  }
  else if (voltage <= 2.8)
  {
    pixels.fill(0xff00ff);
    pixels.show();
  }
}