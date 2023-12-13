/*
  该程序作用是通过 PS2 摇杆模块在串口监视器中打印读取到的数值
  在线文档：https://docs.geeksman.com/esp32/Arduino/21.esp32-arduino-ps2.html
*/
#define PS2_X   15
#define PS2_Y   2
#define SW      4
#define BEEP_PIN   22


void setup() {
  // 配置输入模式
  pinMode(PS2_X, INPUT);
  pinMode(PS2_Y, INPUT);
  pinMode(SW, INPUT_PULLUP);
  // 设定引脚为输出模式
  pinMode(BEEP_PIN, OUTPUT);
  digitalWrite(BEEP_PIN,HIGH);
  // 配置串口通信波特率
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    // 将数据重新发送到 UART
    Serial.write(data);
  }
  if(digitalRead(SW)==0)
  {
    //按下按钮了
    digitalWrite(BEEP_PIN, LOW);
    // 读取数值
    Serial.printf("X: %d, Y: %d, Z: %d\n", analogRead(PS2_X), analogRead(PS2_Y), digitalRead(SW));
    delay(500);
    digitalWrite(BEEP_PIN,HIGH);
  }
  else
  {
    Serial.printf("X: %d, Y: %d, Z: %d\n", analogRead(PS2_X), analogRead(PS2_Y), digitalRead(SW));
    delay(100);                           // 延时 1s
  }


}
