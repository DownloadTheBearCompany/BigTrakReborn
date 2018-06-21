// IGNORE THESE 5 LINES
#include <Servo.h>
Servo servol;           // Controls steering
Servo esc;              // Controls power train
bool DEBUG              = true;

//
//  ______     ______        ______     ______     __   __     ______   __     ______
// /\  == \   /\  ___\      /\  ___\   /\  __ \   /\ "-.\ \   /\  ___\ /\ \   /\  ___\
// \ \  __<   \ \ \____     \ \ \____  \ \ \/\ \  \ \ \-.  \  \ \  __\ \ \ \  \ \ \__ \
//  \ \_\ \_\  \ \_____\     \ \_____\  \ \_____\  \ \_\\"\_\  \ \_\    \ \_\  \ \_____\
//   \/_/ /_/   \/_____/      \/_____/   \/_____/   \/_/ \/_/   \/_/     \/_/   \/_____/
//
//
//
//
//
// Modify servol.write(XXX) and esc.write(XXX) value(XXX) to your RC Craft configuration.
// Most likely, you won't need to change anything. Test it out!
//
//
//
//
void processData(bool cha, bool chb, bool chc, bool chd) {
    if (!cha) {
        servol.write(100);                              // Center position
        if (DEBUG) Serial.print("Center");
    } else {
      // left and right
      if (chb) {
          servol.write(150);                            // Right position
          if (DEBUG) Serial.print("Right");
      } else {
          servol.write(65);                             // Left position
          if (DEBUG) Serial.print("Left");
      }
    }

    if (!chc) {
      esc.write(80);                                    // Stop
      if (DEBUG) Serial.print(" Stop");
    } else {
      // Forward and Reverse
      if (chd) {
        esc.write(65);                                  // Forward
        if (DEBUG) Serial.print(" Forward");
      } else {
        esc.write(100);                                 // Reverse
        if (DEBUG) Serial.print(" Reverse");
      }
    }
}





//
//  ______   ______     __     __     ______     ______        __  __     ______     ______     ______
// /\  == \ /\  __ \   /\ \  _ \ \   /\  ___\   /\  == \      /\ \/\ \   /\  ___\   /\  ___\   /\  == \
// \ \  _-/ \ \ \/\ \  \ \ \/ ".\ \  \ \  __\   \ \  __<      \ \ \_\ \  \ \___  \  \ \  __\   \ \  __<
//  \ \_\    \ \_____\  \ \__/".~\_\  \ \_____\  \ \_\ \_\     \ \_____\  \/\_____\  \ \_____\  \ \_\ \_\
//   \/_/     \/_____/   \/_/   \/_/   \/_____/   \/_/ /_/      \/_____/   \/_____/   \/_____/   \/_/ /_/
//
// Better have a good reason for changing the code below!

int SpectrumLeft[7];    // 7 frequencies
int SpectrumRight[7];   // 7 frequencies
int SpectrumBand;
int SpectrumStrobe = 9; // Strobe for the MSGEQ7 chip
int SpectrumReset  = 10;// Reset for the MSGEQ7 chip

int threshold      = 700;

int car_cha_a      = 0;
int car_cha_b      = 0;
int car_cha_c      = 0;
int car_cha_d      = 0;


void setup ()
{
  Serial.begin(9600);
  pinMode(SpectrumReset, OUTPUT);
  pinMode(SpectrumStrobe, OUTPUT);
  servol.attach(3);
  esc.attach(5);
}

void loop ()
{
  // Read in the data from MSGEQ7
  digitalWrite(SpectrumReset, HIGH);
  digitalWrite(SpectrumReset, LOW);
  delayMicroseconds(30);
  for(SpectrumBand = 0; SpectrumBand < 7; SpectrumBand++)
  {
    digitalWrite(SpectrumStrobe, HIGH);
    digitalWrite(SpectrumStrobe, LOW);
    delayMicroseconds(30);
    SpectrumLeft[SpectrumBand] = analogRead(4);
    SpectrumRight[SpectrumBand] = analogRead(5);
  }

  for(SpectrumBand = 0; SpectrumBand < 2; SpectrumBand++)
  {
    if (DEBUG) {
        Serial.print(SpectrumLeft[SpectrumBand]);
        Serial.print(" ");
        Serial.print(SpectrumRight[SpectrumBand]);
        Serial.print("|");
    }
    if (SpectrumBand == 0) {
       car_cha_a = SpectrumLeft[SpectrumBand];
       car_cha_b = SpectrumRight[SpectrumBand];
    } else if (SpectrumBand == 1) {
       car_cha_c = SpectrumLeft[SpectrumBand];
       car_cha_d = SpectrumRight[SpectrumBand];
    }
  }
  processData(  car_cha_a > threshold,
                car_cha_b > threshold,
                car_cha_c > threshold,
                car_cha_d > threshold);
  if (DEBUG) Serial.println("");
  delay(1);
}
