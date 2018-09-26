
// black--->> 900~
// white--->> 40~
void setup() {
 Serial.begin(9600);
}

void loop() {
 int val = analogRead(A0);
 Serial.println(val);
 delay(300);
}
