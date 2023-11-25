// ============
// FE2 to relay
// ============

int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    if(incomingByte == 'x') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3000);
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
