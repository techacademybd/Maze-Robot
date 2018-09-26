// ref: https://howtomechatronics.com/tutorials/arduino/arduino-color-sensing-tutorial-tcs230-tcs3200-color-sensor/
// General code for detecting RGB Values

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int frequency = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}

void loop() {

  //RED
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  frequency = pulseIn(sensorOut, LOW);
  
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);

  //GREEN 
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  frequency = pulseIn(sensorOut, LOW);
  
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);
  
  //BLUE
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  frequency = pulseIn(sensorOut, LOW);
  
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(100);
}
