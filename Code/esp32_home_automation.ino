#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi Credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Relay Pins
#define RELAY1 23   // Light
#define RELAY2 22   // Fan
#define RELAY3 21   // Socket
#define RELAY4 19   // Extra Device

// Change to false if your relay board is HIGH trigger
bool lowTriggerRelay = true;

// ---------- Relay Control ----------
void relayWrite(int pin, int state)
{
  if (lowTriggerRelay)
  {
    digitalWrite(pin, state ? LOW : HIGH);
  }
  else
  {
    digitalWrite(pin, state ? HIGH : LOW);
  }
}

// ---------- Blynk Virtual Buttons ----------
BLYNK_WRITE(V0)   // Light
{
  relayWrite(RELAY1, param.asInt());
}

BLYNK_WRITE(V1)   // Fan
{
  relayWrite(RELAY2, param.asInt());
}

BLYNK_WRITE(V2)   // Socket
{
  relayWrite(RELAY3, param.asInt());
}

BLYNK_WRITE(V3)   // Extra
{
  relayWrite(RELAY4, param.asInt());
}

// Sync states when reconnecting
BLYNK_CONNECTED()
{
  Blynk.syncAll();
}

// ---------- Setup ----------
void setup()
{
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // All OFF initially
  relayWrite(RELAY1, 0);
  relayWrite(RELAY2, 0);
  relayWrite(RELAY3, 0);
  relayWrite(RELAY4, 0);

  Serial.println("Connecting to WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Smart Home Automation Ready!");
}

// ---------- Main Loop ----------
void loop()
{
  Blynk.run();
}
