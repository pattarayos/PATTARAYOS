#include <Arduino.h>
const int potentiometerPin = 36;  // ขาอ่านค่าจาก potentiometer
const int ledPins[] = {23, 19, 18, 5, 17, 16, 4, 0}; // ขาเชื่อมต่อกับ LED
const int numLeds = 8; // จำนวนหลอด LED

void setup() {
  // ตั้งค่าขา LED เป็น OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // ปิด LED เริ่มต้น
  }

  Serial.begin(115200); // สำหรับ Debug
}

void loop() {
  // อ่านค่าจาก potentiometer
  int potValue = analogRead(potentiometerPin);

  // แปลงค่า 0-4095 เป็น 0-100
  int mappedValue = map(potValue, 0, 4095, 0, 100);

  // คำนวณจำนวน LED ที่ต้องติด
  int ledsToLight = map(mappedValue, 0, 100, 0, numLeds);

  // ใช้ตรรกะแบบบูลีนเพื่อควบคุม LED
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], i < ledsToLight); // จะเขียน HIGH ถ้า i < ledsToLight, LOW ถ้าไม่ใช่
  }

  // Debug แสดงผลใน Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | Mapped Value: ");
  Serial.print(mappedValue);
  Serial.print(" | LEDs On: ");
  Serial.println(ledsToLight);

  delay(100); // หน่วงเวลาเล็กน้อย
}