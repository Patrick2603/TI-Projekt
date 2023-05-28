#include <WiFi.h>
#include <ArduinoMqttClient.h> 

// ESP32 Pin VP, GPIO36? 
const int sensorPin = 36; 

// Setup for Wifi
#define SSID "WaltDisney"
#define PASS "44947573422887866577"

char ssid[] = SSID; 
char pass[] = PASS; 

WiFiClient wifiClient;  
MqttClient mqttClient(wifiClient); 

// Setup for MQTT 
const char broker[] = "test.mosquitto.org"; 
int port = 1883; 
const char topic1[] = "TIProject/rawSensorValue"; 
const char topic2[] = "TIProject/voltageValue"; 

// Set interval for sending messages
const long interval = 1000; 
unsigned long previousMillis = 0; 

void setup() {
   Serial.begin(9600); 
   while(!Serial) {
     ; 
   }

   // Attempt to connect to Wifi network
   while(WiFi.begin(ssid, pass) != WL_CONNECTED) {
     // Failed
     Serial.print("."); 
     delay(5000); 
   }

   Serial.println("Youre connected to the network"); 

   // Attempt to connect to MQTT Broker
  if(!mqttClient.connect(broker, port)) {
    // Failed
  }
}

void loop() {
  mqttClient.poll(); 
  unsigned long currentMillis = millis(); 

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 

    int rawMoistureValue = analogRead(sensorPin);
    // 12 Bit ADC 
    float voltageValue = (rawMoistureValue * 3.3) / 4095; 
    delay(500); 

    mqttClient.beginMessage(topic1); 
    mqttClient.print(rawMoistureValue); 
    mqttClient.endMessage(); 

    mqttClient.beginMessage(topic2); 
    mqttClient.print(voltageValue); 
    mqttClient.endMessage(); 
  }
}









