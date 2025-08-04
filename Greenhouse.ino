#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN A0
#define LDR_PIN A1

#define FAN_RELAY 3
#define PUMP_RELAY 4
#define BULB_RELAY 5

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {
  Serial.begin(9600); // UART to ESP32
  dht.begin();
  lcd.begin(16, 2);

  pinMode(FAN_RELAY, OUTPUT);
  pinMode(PUMP_RELAY, OUTPUT);
  pinMode(BULB_RELAY, OUTPUT);
  digitalWrite(FAN_RELAY, HIGH);
  digitalWrite(PUMP_RELAY, HIGH);
  digitalWrite(BULB_RELAY, HIGH);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soil = analogRead(SOIL_PIN);
  int ldr = analogRead(LDR_PIN);

  // Send data to ESP32
  Serial.print("T:"); Serial.print(temp);
  Serial.print(",H:"); Serial.print(hum);
  Serial.print(",S:"); Serial.print(soil);
  Serial.print(",L:"); Serial.println(ldr);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print(temp); lcd.print(" H:"); lcd.print(hum);
  lcd.setCursor(0, 1);
  lcd.print("S:"); lcd.print(soil); lcd.print(" L:"); lcd.print(ldr);

  // Receive control command from ESP32
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    if (cmd == "FAN_ON") digitalWrite(FAN_RELAY, LOW);
    else if (cmd == "FAN_OFF") digitalWrite(FAN_RELAY, HIGH);
    else if (cmd == "PUMP_ON") digitalWrite(PUMP_RELAY, LOW);
    else if (cmd == "PUMP_OFF") digitalWrite(PUMP_RELAY, HIGH);
    else if (cmd == "BULB_ON") digitalWrite(BULB_RELAY, LOW);
    else if (cmd == "BULB_OFF") digitalWrite(BULB_RELAY, HIGH);
  }

  delay(2000);
}
