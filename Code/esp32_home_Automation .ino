#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ---------------- WiFi ----------------
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// ---------------- Relay Pins ----------------
#define RELAY1 23   // Light
#define RELAY2 22   // Fan
#define RELAY3 21   // Socket
#define RELAY4 19   // Extra

// ---------------- Switch Pins ----------------
// One side switch to GPIO, other side to GND
#define SW1 13
#define SW2 26
#define SW3 14
#define SW4 27

// LOW trigger relay board?
bool lowTriggerRelay = true;

// Device states
bool state1 = false;
bool state2 = false;
bool state3 = false;
bool state4 = false;

// Debounce timing
unsigned long lastPress1 = 0;
unsigned long lastPress2 = 0;
unsigned long lastPress3 = 0;
unsigned long lastPress4 = 0;

const int debounceDelay = 250;

// ---------------- Relay Write ----------------
void relayWrite(int pin, bool state)
{
  if (lowTriggerRelay)
    digitalWrite(pin, state ? LOW : HIGH);
  else
    digitalWrite(pin, state ? HIGH : LOW);
}

// ---------------- Update Outputs ----------------
void applyStates()
{
  relayWrite(RELAY1, state1);
  relayWrite(RELAY2, state2);
  relayWrite(RELAY3, state3);
  relayWrite(RELAY4, state4);

  Blynk.virtualWrite(V0, state1);
  Blynk.virtualWrite(V1, state2);
  Blynk.virtualWrite(V2, state3);
  Blynk.virtualWrite(V3, state4);
}

// ---------------- Blynk Buttons ----------------
BLYNK_WRITE(V0) { state1 = param.asInt(); applyStates(); }
BLYNK_WRITE(V1) { state2 = param.asInt(); applyStates(); }
BLYNK_WRITE(V2) { state3 = param.asInt(); applyStates(); }
BLYNK_WRITE(V3) { state4 = param.asInt(); applyStates(); }

BLYNK_CONNECTED()
{
  Blynk.syncAll();
}

// ---------------- Read Manual Switches ----------------
void checkSwitches()
{
  if (digitalRead(SW1) == LOW && millis() - lastPress1 > debounceDelay)
  {
    state1 = !state1;
    applyStates();
    lastPress1 = millis();
  }

  if (digitalRead(SW2) == LOW && millis() - lastPress2 > debounceDelay)
  {
    state2 = !state2;
    applyStates();
    lastPress2 = millis();
  }

  if (digitalRead(SW3) == LOW && millis() - lastPress3 > debounceDelay)
  {
    state3 = !state3;
    applyStates();
    lastPress3 = millis();
  }

  if (digitalRead(SW4) == LOW && millis() - lastPress4 > debounceDelay)
  {
    state4 = !state4;
    applyStates();
    lastPress4 = millis();
  }
}

// ---------------- Setup ----------------
void setup()
{
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);

  applyStates();   // all OFF initially

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Smart Home Automation with Switches Ready");
}

// ---------------- Loop ----------------
void loop()
{
  Blynk.run();
  checkSwitches();
}
