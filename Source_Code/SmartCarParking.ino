#define BLYNK_TEMPLATE_ID "TMPL3M8xZPrMr"
#define BLYNK_TEMPLATE_NAME "IoTT app"
#define BLYNK_AUTH_TOKEN "l-ColH3iKcKWoK0iSpxAN9iFrEmf4f4T"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Virtual pins
#define SLOT1 V0
#define SLOT2 V1
#define SLOT3 V2
#define SLOT4 V3

// IR sensor pins
#define IR1 32
#define IR2 33
#define IR3 25
#define IR4 26

// LED pins
#define LED1 14
#define LED2 27
#define LED3 12
#define LED4 13

LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;

void checkSlots() {
  int s1 = digitalRead(IR1);
  int s2 = digitalRead(IR2);
  int s3 = digitalRead(IR3);
  int s4 = digitalRead(IR4);

  // Update LED & Blynk for each slot
  digitalWrite(LED1, s1 == LOW ? HIGH : LOW);
  digitalWrite(LED2, s2 == LOW ? HIGH : LOW);
  digitalWrite(LED3, s3 == LOW ? HIGH : LOW);
  digitalWrite(LED4, s4 == LOW ? HIGH : LOW);

  Blynk.virtualWrite(SLOT1, s1 == LOW ? 1 : 0);
  Blynk.virtualWrite(SLOT2, s2 == LOW ? 1 : 0);
  Blynk.virtualWrite(SLOT3, s3 == LOW ? 1 : 0);
  Blynk.virtualWrite(SLOT4, s4 == LOW ? 1 : 0);

  // Update LCD clearly
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("P1:");
  lcd.print(s1 == LOW ? "Full " : "Empty");
  lcd.setCursor(8, 0);
  lcd.print("P2:");
  lcd.print(s2 == LOW ? "Full" : "Empty");

  lcd.setCursor(0, 1);
  lcd.print("P3:");
  lcd.print(s3 == LOW ? "Full " : "Empty");
  lcd.setCursor(8, 1);
  lcd.print("P4:");
  lcd.print(s4 == LOW ? "Full" : "Empty");

  Serial.print("Slot1: "); Serial.print(s1 == LOW ? "Full" : "Empty");
  Serial.print(" | Slot2: "); Serial.print(s2 == LOW ? "Full" : "Empty");
  Serial.print(" | Slot3: "); Serial.print(s3 == LOW ? "Full" : "Empty");
  Serial.print(" | Slot4: "); Serial.println(s4 == LOW ? "Full" : "Empty");
}

void setup() {
  Serial.begin(115200);
  Serial.println("Smart Parking System Starting...");

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");
  lcd.setCursor(0, 1);
  lcd.print("Connecting WiFi...");

  WiFi.begin(ssid, pass);
  Blynk.config(BLYNK_AUTH_TOKEN);

  timer.setInterval(1500L, checkSlots);
}

void loop() {
  Blynk.run();
  timer.run();
}
