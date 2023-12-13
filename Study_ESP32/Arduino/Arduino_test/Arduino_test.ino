#define LED_BOARD   2

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BOARD, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BOARD, HIGH);         // 点亮 LED
  delay(1000);                           // 延时 1s
  digitalWrite(LED_BOARD, LOW);          // 熄灭 LED
  delay(1000);                           // 延时 1s
}
