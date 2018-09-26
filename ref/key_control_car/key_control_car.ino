const int Motor1Pin1 = 2;  
const int Motor1Pin2 = 3;

const int Motor2Pin2 =4;   
const int Motor2Pin1 = 5;

char data; 

void setup() {
  
  Serial.begin(9600);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
  moveStop();
}

void loop() {
  
  if (Serial.available() > 0) {    
    data = Serial.read();
    Serial.println(data);
    }

 if(data == 'f'){ moveForward(); }
 
 if(data == 'b'){   moveBackward();  }
 
 if(data == 'l'){    moveLeft(); }
 
 if(data == 'r'){   moveRight();  }
 
 else if(data == 'n'){ moveStop(); }
 
}


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

