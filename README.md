# SymbiAirQuality

![image](https://github.com/onkar69483/SymbiAirQuality/assets/61963755/38f68328-7134-49e3-b08c-0fbea8ca4280)

SymbiAirQuality is an ESP8266 NodeMCU-based project that measures air quality and temperature using a DHT11 sensor and a gas sensor. This project hosts a stylish and informative webpage that displays real-time sensor data. You can check out a live preview of the hosted webpage [here](https://onkar69483.github.io/SymbiAirQuality/).

## Features

- Measures temperature and air quality.
- Provides real-time data visualization on a beautifully designed webpage.
- Two operational modes:
  - **AP Mode:** Creates its own WiFi network with a captive portal for easy access.
  - **Station Mode:** Connects to an existing WiFi network.

## Installation

### Hardware Required

- ESP8266 NodeMCU
- DHT11 Sensor
- Gas Sensor (provide details of the gas sensor)
- (Optional) Additional components as per your specific setup

### Software Dependencies

Before uploading the code to your ESP8266 NodeMCU, make sure you have the following libraries installed:

- ESP8266WiFi.h
- ESP8266WebServer.h
- DHT.h
- DNSServer.h

### Wiring

Connect your sensors to the ESP8266 NodeMCU according to your setup and update pin configurations in the code if necessary.

### Uploading the Code

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/onkar69483/SymbiAirQuality.git
   ```

2. Open the Arduino IDE and load one of the following code files:

   - **SymbiAirQuality-APMode.ino:** Upload this code to the ESP8266 to create an access point (AP) mode.
   - **SymbiAirQuality-StationMode.ino:** Upload this code to the ESP8266 to connect to an existing WiFi network.

3. Modify the code to set your WiFi credentials and adjust any other configurations as needed.

4. Upload the code to your ESP8266 NodeMCU.

### Accessing the Webpage

#### AP Mode

1. Power on your ESP8266 NodeMCU.

2. It will create its own WiFi network (SSID: "SymbiAirQuality"). Connect your device to this network.

3. Open a web browser and navigate to any website. You will be redirected to the SymbiAirQuality webpage automatically.

#### Station Mode

1. After uploading the Station Mode code, the ESP8266 will connect to your specified WiFi network.

2. Find the IP address assigned to your ESP8266 in your router's admin interface or use mDNS.

3. Access the webpage by entering the IP address in the serial monitor in your browser's address bar.

## Screenshots

![image](https://github.com/onkar69483/SymbiAirQuality/assets/61963755/30ee02ce-9ef4-41cc-9f1a-cf3c77ab4f37)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to the [DNS server library](https://github.com/esp8266/Arduino/tree/master/libraries/DNSServer) for making captive portal functionality possible.

Feel free to contribute, report issues, or provide feedback. Enjoy monitoring air quality with SymbiAirQuality!
