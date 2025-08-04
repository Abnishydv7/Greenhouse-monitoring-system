#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

#define RXD2 16
#define TXD2 17

String incomingData = "";

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      client.subscribe("greenhouse/control");
    }
    delay(1000);
  }
}

void loop() {
  client.loop();

  while (Serial2.available()) {
    char c = Serial2.read();
    if (c == '\n') {
      client.publish("greenhouse/data", incomingData.c_str());
      incomingData = "";
    } else {
      incomingData += c;
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String command = "";
  for (int i = 0; i < length; i++) {
    command += (char)payload[i];
  }
  Serial.println("Received MQTT: " + command);
  Serial2.println(command); // Send to Arduino
}
