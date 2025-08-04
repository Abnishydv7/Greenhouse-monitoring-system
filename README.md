# Greenhouse-monitoring-system
IoT-based greenhouse monitoring system using Arduino and ESP32 and MQTT.

# 🌱 Greenhouse Monitoring and Control System (IoT Based)

This project is a smart greenhouse monitoring system built using **Arduino UNO** and **ESP32**, designed to collect environmental data and allow remote control of greenhouse devices using **MQTT (IoT)**.

---

## 🚀 Features

- 🌡️ Monitor temperature and humidity using DHT11
- 💧 Detect soil moisture levels
- ☀️ Measure light intensity using LDR
- 🖥️ Display data on an LCD screen
- 🔁 Automatically control:
  - Water pump (irrigation)
  - Fan (temperature control)
  - Light bulb (light control)
- 📤 Send sensor data to MQTT (via ESP32)
- 📥 Receive control commands from MQTT and act on them

---

## 🔧 Hardware Components

| Component         | Quantity |
|------------------|----------|
| Arduino UNO       | 1        |
| ESP32             | 1        |
| DHT11 Sensor      | 1        |
| Soil Moisture Sensor | 1     |
| LDR (Light Sensor)| 1        |
| LCD Display (I2C) | 1        |
| Relay Module      | 1–4 (depending on devices) |
| Water Pump        | 1        |
| Fan               | 1        |
| Light Bulb (small)| 1        |
| Battery or Adapter| 1        |
| Jumper Wires      | As needed |

---

## ⚙️ System Architecture

---

## 📁 Files in This Repository

| File               | Description                                  |
|--------------------|----------------------------------------------|
| `greenhouse.ino`   | Arduino code to read sensors, display on LCD, send data to ESP32, and control relays |
| `esp32_mqtt.ino`   | ESP32 code to connect to Wi-Fi and MQTT, communicate with Arduino via UART |
| `README.md`        | This file – explains the full project        |

---

## 🌐 MQTT Topics

| Topic Name            | Type     | Description                        |
|-----------------------|----------|------------------------------------|
| `greenhouse/data`     | Publish  | Sensor data from Arduino → MQTT    |
| `greenhouse/control`  | Subscribe| Commands from app → ESP32 → Arduino|

---

## 🧠 How It Works

1. **Arduino** reads:
   - Temperature & humidity (DHT11)
   - Soil moisture level
   - Light intensity (LDR)

2. Displays this data on an **LCD** and sends it to **ESP32** using UART.

3. **ESP32** connects to Wi-Fi and **publishes** sensor data to an MQTT topic.

4. The **user can control** pump, fan, and light remotely by sending MQTT commands.

5. **ESP32 receives** those commands and sends them back to **Arduino** via UART to turn ON/OFF devices.

---

## 📲 Compatible IoT Platforms

You can use any MQTT-supported platform to view data or send commands:
- [HiveMQ Web Client](http://www.hivemq.com/demos/websocket-client/)
- [Blynk IoT](https://blynk.io/)
- MQTT Dash (Android App)
- IoT MQTT Panel

---

## ✅ Setup Instructions

1. **Upload `greenhouse.ino`** to Arduino UNO
2. **Upload `esp32_mqtt.ino`** to ESP32
3. Connect all sensors and relays as per circuit diagram
4. Power the system and open MQTT dashboard to monitor and control

---

## 📸 Optional Additions

- Proteus simulation files (`.pdsprj`)
- Circuit diagrams or schematics
- Photos of working project setup
- Video demo

---

## 👤 Author

**Abnish Kumar Yadav**  
My teammate name:- Sushil Poudel, Himal Rawat, Pratham Adhikari 
Final Year Electronics & Communication Engineering Student  
Nepal 🇳🇵  

---

## 📌 License

This project is open source and free to use for educational purposes.
