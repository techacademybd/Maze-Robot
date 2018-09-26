// condition for two sensors
// sensor 1
#define S0_1 4
#define S1_1 5
#define S2_1 6
#define S3_1 7
#define sensorOut_1 8

// sensor 2
#define S0_2 2
#define S1_2 3
#define S2_2 9
#define S3_2 10
#define sensorOut_2 11

int red_1 = 0;
int red_2 = 0;

void setup() {
  
  //setup sensor 1 pins
  pinMode(S0_1, OUTPUT);
  pinMode(S1_1, OUTPUT);
  pinMode(S2_1, OUTPUT);
  pinMode(S3_1, OUTPUT);
  pinMode(sensorOut_1, INPUT);
  
  digitalWrite(S0_1,HIGH);
  digitalWrite(S1_1,LOW);

  //setup sensor 2 pins
  pinMode(S0_2, OUTPUT);
  pinMode(S1_2, OUTPUT);
  pinMode(S2_2, OUTPUT);
  pinMode(S3_2, OUTPUT);
  pinMode(sensorOut_2, INPUT);
  
  digitalWrite(S0_2,HIGH);
  digitalWrite(S1_2,LOW);
  Serial.begin(9600);
}

void loop() {
  
  //red pins for sensor 1
  digitalWrite(S2_1,LOW);
  digitalWrite(S3_1,LOW);
  red_1 = pulseIn(sensorOut_1, LOW);

  //red pins for sensor 1
  digitalWrite(S2_2,LOW);
  digitalWrite(S3_2,LOW);
  red_2 = pulseIn(sensorOut_2, LOW);

  // red_x>=200 -----> blue
  // red_x<200  -----> red

  //blue and blue
  if (red_1>=200 && red_2>=200){
    Serial.println("MOVING1");
  }
  
  //blue and red
  if (red_1>=200 && red_2<200){
    Serial.println("MOVING2");
  }

  //red and red
  if (red_1<200 && red_2<200){
    Serial.println("FREEZE");
  }

  //red and blue
  if (red_1<200 && red_2>=200){
    Serial.println("MOVING3");
  }

  delay(100);
}


