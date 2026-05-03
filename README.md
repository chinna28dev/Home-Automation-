# Home-Automation-

# 🏠 Smart Home Automation using ESP32  
### Control by Mobile App 📱 | Web Dashboard 🌐 | Google Assistant 🎙️ | Switches |
---
## 📌 Project Overview
This project is a complete **Smart Home Automation System** built using **ESP32** and a **4 Channel Relay Module**.
It allows users to control home appliances such as:
- 💡 Lights  
- 🌀 Fans  
- 🔌 Power sockets  
- 🚰 Water motor  
- 📺 Other electrical devices  
using multiple control methods:
✅ Mobile App  
✅ Web Browser  
✅ Google Assistant Voice Commands  
✅ Switches
---


## 🚀 Main Features
- 📱 Control appliances from anywhere using phone  
- 🌐 Browser-based dashboard access  
- 🎙️ Voice control with Google Assistant  
- ⚡ Real-time ON/OFF switching  
- 📶 Wi-Fi based automation  
- 🔌 Supports multiple appliances  
- 🧠 Expandable for AI / Voice Assistant integration  
- 🏠 Low-cost DIY smart home project
---


## 🧰 Components Required

| Component | Quantity |
| :--- | :--- |
| ESP32 Dev Board | 1 |
| 4 Channel Relay Module | 1 |
| 5V Power Adapter | 1 |
| Jumper Wires | As needed |
| Breadboard (Optional) | 1 |
| Bulbs / Loads | As needed |
| Wi-Fi Router | 1 |

---


## 🔌 Wiring Connections

| ESP32 Pin | Relay Module |
| :--- | :--- |
| VIN / 5V | VCC |
| GND | GND |
| GPIO23 | IN1 |
| GPIO22 | IN2 |
| GPIO21 | IN3 |
| GPIO19 | IN4 |

> Use **COM + NO** terminals for appliance control.
⚠️ Start testing with low-voltage devices first.
---


## 📲 Mobile App Control
This project uses **Blynk IoT Platform**.
### Controls:
- Button 1 → Light  
- Button 2 → Fan  
- Button 3 → Socket  
- Button 4 → Extra Device  
---
## 🌐 Web Dashboard Control
You can log in to Blynk Cloud and control all appliances using:
- Laptop  
- PC  
- Mobile Browser
---
## 🎙️ Google Assistant Control
Example Commands:
- Hey Google, Turn on bedroom light  
- Hey Google, Switch off fan  
- Hey Google, Turn off all lights  
---


## 🛠️ Installation Guide

### 1️⃣ Install Arduino IDE
Install Arduino IDE on your PC.
### 2️⃣ Add ESP32 Board URL
txt..👇
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

3️⃣ Install Libraries
Blynk
WiFi
4️⃣ Upload Code
Open:
code/esp32_home_automation.ino
Update:
YOUR_TEMPLATE_ID
YOUR_AUTH_TOKEN
YOUR_WIFI_NAME
YOUR_WIFI_PASSWORD
Then upload to ESP32.
---

🔮 Future Improvements
🌡️ Temperature Sensor
🚶 Motion Detection
💧 Water Level Sensor
📊 Power Monitoring
⏰ Scheduling System
📱 Custom Android App
🤖 AI JARVIS Assistant
---
⚠️ Safety Note
Be careful while using AC mains power.
Use proper insulation and adult supervision if required.
---
🙌 Author
Developed as a DIY learning project for smart home automation using ESP32.
---
⭐ Support
If you like this project:
⭐ Star this repository
🍴 Fork it
📢 Share it
---
