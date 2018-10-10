#include <EEPROM.h>

int lm1 = 2;
int lm2 = 3;
int rm1 = 4;
int rm2 = 5;

int laserPin = 8;
int LDRpin = A1;
int laseerThreshold = 450;
int sensorPin = A0;
int sensorData;
int laserValue;
boolean calibrated = false, freeze = false;
int blackThreshold = 0, whiteThreshold = 1023;
int mainThreshold;

int ENA = 9;
int ENB = 10;
int speed = 200;

int LED = 13;
bool LED_state = calibrated;
unsigned long last_blink = 0;

void setup() {

  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(laserPin, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LED_state);

  Serial.begin(9600);

  int a = EEPROM.read(0);
  if (a > 128 && a < 255) {
    mainThreshold = a * 4;
    calibrated = true;
  }
  Serial.println(a);

}

void loop() {

  while (!Serial.available()) {
    //Serial.println(analogRead(sensorPin));
    getLaserData();
  }
  getLaserData();
  sensorState();

  char val = Serial.read() ;  //reads the signal

  if (val == 'X') {
    calibrated = false;
  }

  if (val == 'x') {
    EEPROM.write(0, mainThreshold / 4);
    calibrated = true;
  }


  if (val == 'W' || val == 'w') {
    freeze = false;
  }


  if (!freeze) {
    Serial.println("r");
    /*********For Forward *********/
    if (val == 'F') {
      digitalWrite(lm1, HIGH);      digitalWrite(rm1, HIGH);
      digitalWrite(lm2, LOW);       digitalWrite(rm2, LOW);

    }


    /*********For Backward *********/
    else if (val == 'B') {
      digitalWrite(lm2, HIGH);      digitalWrite(rm2, HIGH);
      digitalWrite(lm1, LOW);       digitalWrite(rm1, LOW);

    }
    /*********Right*********/
    else if (val == 'R')   {
      digitalWrite(lm1, HIGH);      digitalWrite(rm2, HIGH);
      digitalWrite(lm2, LOW);       digitalWrite(rm1, LOW);
    }
    /*********Left*********/
    else if (val == 'L')  {
      digitalWrite(lm2, HIGH);      digitalWrite(rm1, HIGH);
      digitalWrite(lm1, LOW);       digitalWrite(rm2, LOW);

    }
    /*********Left*********/
    else if (val == 'G')  {
      digitalWrite(laserPin, HIGH);
    }

    /*********STOP*********/
    else  {
      digitalWrite(lm1, LOW);       digitalWrite(rm1, LOW);
      digitalWrite(lm2, LOW);       digitalWrite(rm2, LOW);
      digitalWrite(laserPin, LOW);
    }

    if (!calibrated)
    {
      if (millis() - last_blink > 300) {
        LED_state = !LED_state;
        digitalWrite(LED, LED_state);
        last_blink = millis();
      }

      if (sensorData > blackThreshold) {
        blackThreshold = sensorData;
      }

      else if (sensorData < whiteThreshold) {
        whiteThreshold = sensorData;
      }

      int diff = blackThreshold - whiteThreshold;
      mainThreshold = blackThreshold - (diff / 5);
    }
    else digitalWrite(LED, calibrated);

  } else Serial.println('f');

}

void sensorState() {
  sensorData = analogRead(sensorPin);
  if (sensorData >= mainThreshold) {
    freeze = true;
  }
  if (!calibrated) freeze = false;
}

void getLaserData() {
  laserValue = analogRead(laserPin);
  if (laserValue  > laseerThreshold) {
    Serial.println("l");
    freeze = true;
  }
}
