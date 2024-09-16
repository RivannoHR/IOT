#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>

WiFiClient net;
MQTTClient client;

const char wifi[] = "SkibidiSigma";
const char pass[] = "rizzOhio";
void connect();
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(wifi, pass);
  client.begin("broker.emqx.io", net);
  delay(2000);
  connect();
}

void loop()
{
  if (!client.connected())
  {
    connect();
  }
  delay(500);
}

void connect()
{
  Serial.println("in func");
  WiFi.begin(wifi, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Belum konek"); //when func called in loop its stuck in this while loop oof
    delay(1000);
  }
  Serial.println("Berhasil Wifi Yey");
  Serial.println("Connecting to mqtt");
  while (!client.connect("esp32-fraudHehe"))
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("Mqtt connected");
}
