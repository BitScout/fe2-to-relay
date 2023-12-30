// ============
// FE2 to relay
// ============

#define OUTPUT_PIN 2        // Pin which will be set to 5V (high) after the serial command
#define LED_PIN 11 // Set to LED_BUILTIN for onboard LED
#define ON_DURATION_MS 3000 // Duration in milliseconds, for which OUTPUT_PIN will be set to high

int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(OUTPUT_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    
    if(incomingByte == 'x') {
      digitalWrite(OUTPUT_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      
      delay(ON_DURATION_MS);
      
      digitalWrite(OUTPUT_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
    }
  }
}
