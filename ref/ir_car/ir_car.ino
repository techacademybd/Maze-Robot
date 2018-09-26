const int Motor1Pin1 = 2;  
const int Motor1Pin2 = 3;

const int Motor2Pin2 =4;
const int Motor2Pin1 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
  
}

void loop() {
  
 int val = analogRead(A0);

 
// black--->> 900~
// white--->> 40~
if(val<500){
  moveForward();
  Serial.println("Forward");
 }
 if(val>500){
  moveStop();
  Serial.println("Stop");
 }
 delay(300);
 
}

// motor functions
void moveBackward(){
  
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void moveForward(){
  
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void moveLeft(){
  
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor1Pin1, LOW);//
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2,LOW); 
}

void moveRight(){
  
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor2Pin1, LOW); //
  digitalWrite(Motor2Pin2, HIGH);
}


void moveStop(){
  
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}
