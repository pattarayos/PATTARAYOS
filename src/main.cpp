#include <Arduino.h>
const int ledPins[] = {23, 19, 18, 5, 17, 16, 4, 0}; // ขาเชื่อมต่อของ LED
const int potPin = 36; // ขาที่เชื่อมต่อกับ potentiometer

void setup() {
  // ตั้งค่าขา LED เป็น OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // ตั้งค่าขา potentiometer เป็น INPUT
  pinMode(potPin, INPUT);
}

void loop() {
  // อ่านค่าจาก potentiometer
  int potValue = analogRead(potPin);

  // ใช้ฟังก์ชัน map() เพื่อแปลงค่า 0-4095 เป็น 0-100
  int mappedValue = map(potValue, 0, 4095, 0, 100);

  // คำนวณจำนวนหลอด LED ที่ต้องการเปิด (จาก 0 ถึง 8)
  int numLedsOn = mappedValue / (100 / 8);

  // เปิด/ปิด LED โดยไม่ใช้ if-else
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], i < numLedsOn ? HIGH : LOW);
  }

  // หน่วงเวลาเล็กน้อยเพื่อความเสถียร
  delay(50);
}