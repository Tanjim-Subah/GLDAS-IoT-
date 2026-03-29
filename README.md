# GLDAS-IoT-
Gas Leakage Detection with NodeMCU ESP8266 integrated system.

## Introduction
Gas Leage Detection is an intgrated system made with NodeMCU ESP8266 that uses a gas sensor, buzzer and LEDs to create a simple configuration where all this components are combined to detect the gas.The sensor has a material that changes the resistance to the gas which is conected to a Firebase Real-time databaseto collect and store the messages, the buzzer is added to alert surronding.


## Main Components 
* **NodeMCU ESP8266 Microcontroller**
* **MQ-2 Gas Sensor**
* **Arduino IDE**
* **Firebase Realtime Database**

## Other Components
* **5V Buzzer**
* **LED**
* **Resistors (100-ohm, 220-ohm)**
* **Breadboard**
* **Jumper Wire (MALE TO MALE)**
* **Cable**


## Technology Platform

Arduino IDE is used to as the coding platform. The code was input to the ModeMCU microprocessor using NodeMCU SP8266 board and COM3 port.


## System Analysis
* **MQ-2 TO NodeMCU**
* **NodeMCU to Buzzer and Light**
* **NodeMCU to Firebase**

## Experiment & Result
When the MQ2 gas sensor monitors the gas concentration, it's actually operating on the 5V DC power suppy and sensing element that changes resistance when exposed to gas. The voltage values are read by the NodeMCU and it processes the data received from the sensor. If the microcontroller identifies abnormal gas levels indicative of gas leakage, then it activates the alert mechanism and ringing the buzzer and alerting its surronding. Then it sends the data to a centralized database, including gas levels and alert signals.

## Team and Credits

* **Tanjim Subah Alam – IoT integration; Hardware design**
* **Chadni Mandal – Arduino Programming; Hardware design; GitHub Repo**
* **Marion Moon – Project Management**
* **Rosely Mohammad - Documentation**
