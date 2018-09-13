
int lm1 = 2;
int lm2 = 3;
int rm1 = 4;
int rm2 = 5;
int sensorPin = A0;
int sensorData;
boolean calibration, frizz;
int blackThreshold, whiteThreshold;
int mainThreshold;

int ENA = 10;
int ENB = 9;
int speed = 100;

void setup() {

  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  Serial.begin(9600);
}

void loop() {

  while (Serial.available() == 0 ) {
    //Serial.println(analogRead(sensorPin));
    digitalWrite(lm1, LOW);      digitalWrite(rm1, LOW);
    digitalWrite(lm2, LOW);       digitalWrite(rm2, LOW);
  }


  char val = Serial.read() ;//reads the signal
  //Serial.print(val);
  if (val == 'b') {
    blackThreshold  = analogRead(sensorPin);
    Serial.println(blackThreshold);

  }
  if (val == 'w') {
    whiteThreshold = analogRead(sensorPin);
    Serial.println(whiteThreshold);
  }

  if (val == 's') {
    if ( blackThreshold > 0  && whiteThreshold > 0) {
      calibration = true;
      int diff = blackThreshold - whiteThreshold;
      mainThreshold = blackThreshold - (diff / 5);
      Serial.println(mainThreshold);
    }
  }
  if (val == 'u') {
    frizz = false;
  }


  if (calibration && !frizz) {
    sensorState();

    /*********For Forward *********/
    if (val == 'F') {
      Serial.println("FORWARD");
      digitalWrite(lm1, HIGH);      digitalWrite(rm1, HIGH);
      digitalWrite(lm2, LOW);      digitalWrite(rm2, LOW);

    }


    /*********For Backward *********/
    else if (val == 'B')
    {
      Serial.println("BACK");
      digitalWrite(lm2, HIGH);   digitalWrite(rm2, HIGH);
      digitalWrite(lm1, LOW);  digitalWrite(rm1, LOW);

    }
    /*********Right*********/
    else if (val == 'R')
    {
      Serial.println("RIGHT");
      digitalWrite(lm1, HIGH);  digitalWrite(rm2, HIGH);
      digitalWrite(lm2, LOW);       digitalWrite(rm1, LOW);
    }
    /*********Left*********/
    else if (val == 'L')
    {
      Serial.println("LEFT");
      digitalWrite(lm2, HIGH);  digitalWrite(rm1, HIGH);
      digitalWrite(lm1, LOW);       digitalWrite(rm2, LOW);

    }

    /*********STOP*********/
    else  {
      Serial.println("stop!!!");
      digitalWrite(lm1, LOW);      digitalWrite(rm1, LOW);
      digitalWrite(lm2, LOW);       digitalWrite(rm2, LOW);

    }

  }

  if (frizz) {
    digitalWrite(lm1, LOW);      digitalWrite(rm1, LOW);
    digitalWrite(lm2, LOW);       digitalWrite(rm2, LOW);
  }
}


void sensorState() {
  sensorData = analogRead(sensorPin);
  if (sensorData >= mainThreshold) {
    frizz = true;
  }

}
