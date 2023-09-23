#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

#define DHTPIN 5       // Define the pin to which the DHT11 sensor is connected
#define DHTTYPE DHT11  // Define the type of DHT sensor
const int gasPin = A0; // Define the pin for the gas sensor
int gasVal = 0;
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Redmi";        // Replace with your network SSID
const char* password = "d2c321fbf48d"; // Replace with your network password

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);     // Initialize serial communication
  dht.begin();            // Initialize DHT sensor
  pinMode(gasPin, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Define web server routes
  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);

  // Start the web server
  server.begin();
}

void loop() {
  // Read temperature and humidity data from the sensor
  gasVal = analogRead(gasPin);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Handle web server requests
  server.handleClient();
  
  // Other sensor data handling goes here

  delay(2000); // Wait for 2 seconds before taking another reading
}

void handleRoot() {
  String html = "<!DOCTYPE html>\n";
html += "<html lang=\"en\">\n";
html += "  <head>\n";
html += "    <meta charset=\"UTF-8\" />\n";
html += "    <title>SymbiTech</title>\n";
html += "    <style>\n";
html += "      body {\n";
html += "        background: -webkit-linear-gradient(to right, #a7bfe8, #6190e8);\n";
html += "        background: linear-gradient(to right, #a7bfe8, #6190e8);\n";
html += "        width: 100%;\n";
html += "        height: 100%;\n";
html += "        margin: 0;\n";
html += "        padding: 80px 0;\n";
html += "        font-family: \"Source Sans Pro\", sans-serif;\n";
html += "        font-weight: 200;\n";
html += "      }\n";
html += "\n";
html += "      #card {\n";
html += "        width: 700px;\n";
html += "        background: #fff;\n";
html += "        position: relative;\n";
html += "        margin-left: 22%;\n";
html += "        margin-top: 6%;\n";
html += "      }\n";
html += "\n";
html += "      .title {\n";
html += "        display: flex;\n";
html += "        justify-content: center;\n";
html += "        color: #e9ecfb;\n";
html += "        font-size: x-large;\n";
html += "      }\n";
html += "\n";
html += "      .title h1 {\n";
html += "        margin-top: 0px;\n";
html += "        margin-bottom: 0px;\n";
html += "      }\n";
html += "\n";
html += "      .city-selected {\n";
html += "        color: #fff;\n";
html += "        padding: 20px;\n";
html += "        padding-bottom: 0;\n";
html += "        font-size: 25px;\n";
html += "        position: relative;\n";
html += "        overflow: hidden;\n";
html += "        height: 50px;\n";
html += "        background: #042d4b;\n";
html += "        font-weight: 500;\n";
html += "        display: flex;\n";
html += "        justify-content: center;\n";
html += "      }\n";
html += "\n";
html += "      .info {\n";
html += "        position: relative;\n";
html += "        z-index: 2;\n";
html += "        color: #fff;\n";
html += "        padding: 20px;\n";
html += "        display: flex;\n";
html += "        flex-direction: column;\n";
html += "        align-items: flex-start;\n";
html += "      }\n";
html += "\n";
html += "      .temp {\n";
html += "        display: flex;\n";
html += "        align-items: center;\n";
html += "      }\n";
html += "\n";
html += "      .temp-value {\n";
html += "        font-size: 60px;\n";
html += "        font-weight: bold;\n";
html += "        margin-left: 80px;\n";
html += "        margin-bottom: 30px;\n";
html += "      }\n";
html += "\n";
html += "      .temp-icon img {\n";
html += "        margin-left: 150px;\n";
html += "        margin-bottom: 26px;\n";
html += "      }\n";
html += "\n";
html += "      .wind {\n";
html += "        font-size: 18px;\n";
html += "        font-weight: 600;\n";
html += "        text-transform: uppercase;\n";
html += "        margin-left: 280px;\n";
html += "        margin-top: 5px;\n";
html += "      }\n";
html += "\n";
html += "      .heading {\n";
html += "        background: #042d4b;\n";
html += "        padding: 4px;\n";
html += "        padding-bottom: 0px;\n";
html += "        color: #fff;\n";
html += "      }\n";
html += "\n";
html += "      .temp-heading {\n";
html += "        margin-top: 0px;\n";
html += "        margin-bottom: 0px;\n";
html += "        margin-left: 150px;\n";
html += "        font-size: 13px;\n";
html += "        text-transform: uppercase;\n";
html += "      }\n";
html += "\n";
html += "      .invisible {\n";
html += "        color: #042d4b;\n";
html += "      }\n";
html += "\n";
html += "      article {\n";
html += "        position: relative;\n";
html += "        z-index: 2;\n";
html += "        color: #fff;\n";
html += "        padding: 10px;\n";
html += "        position: relative;\n";
html += "        overflow: hidden;\n";
html += "        height: 200px;\n";
html += "        background: #042d4b;\n";
html += "      }\n";
html += "\n";
html += "      .humidity {\n";
html += "        padding: 25px 0px;\n";
html += "        text-align: center;\n";
html += "        font-weight: 500;\n";
html += "        height: 100px;\n";
html += "        background-color: #c2d7f3;\n";
html += "        border: 1px solid #6190e88b;\n";
html += "      }\n";
html += "\n";
html += "      .gas {\n";
html += "        padding: 25px 0px;\n";
html += "        text-align: center;\n";
html += "        font-weight: 500;\n";
html += "        height: 100px;\n";
html += "        background-color: #c2d7f3;\n";
html += "        border: 1px solid #6190e88b;\n";
html += "      }\n";
html += "\n";
html += "      .day span {\n";
html += "        font-size: 17px;\n";
html += "        font-weight: bold;\n";
html += "        text-transform: uppercase;\n";
html += "        margin-top: 10px;\n";
html += "      }\n";
html += "\n";
html += "      .col-md-6 {\n";
html += "        width: 50%;\n";
html += "        float: left; /* This helps in achieving side-by-side layout */\n";
html += "      }\n";
html += "\n";
html += "      .gas-icon {\n";
html += "        height: 25px;\n";
html += "        width: 25px;\n";
html += "      }\n";
html += "    </style>\n";
html += "  </head>\n";
html += "  <body>\n";
html += "    <div class=\"title\">\n";
html += "      <h1>SymbiTech Station</h1>\n";
html += "    </div>\n";
html += "    <div class=\"container\">\n";
html += "      <div class=\"col-sm-4\">\n";
html += "        <div id=\"card\">\n";
html += "          <div class=\"city-selected\">\n";
html += "            <div class=\"city\">Pune</div>\n";
html += "          </div>\n";
html += "          <div class=\"heading\">\n";
html += "            <p class=\"temp-heading\">\n";
html += "              Temperature\n";
html += "              <span class=\"invisible\">\n";
html += "                ----------------------------------------------.\n";
html += "              </span>\n";
html += "              <span> Forecast </span>\n";
html += "            </p>\n";
html += "          </div>\n";
html += "          <article>\n";
html += "            <div class=\"info\">\n";
html += "              <div class=\"temp\">\n";
html += "                <div class=\"temp-value\">" + String(dht.readTemperature()) + " C</div>";
html += "                <div class=\"temp-icon\">\n";
html += "                  <img\n";
html += "                    src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAFAAAABQCAYAAACOEfKtAAAACXBIWXMAAAsTAAALEwEAmpwYAAAEeUlEQVR4nO2cXYhWRRjHRzNtVcTsa02xG73IPi4iMEpCTZJN3YRSaq8iSc1lRdCo6EKQUsQLFVK3utDESEShtLXSiyD6MG+MCtcitQiiD/zYtd1qV/3JsI94eD3neD5m3vPOO+cHB15235nnmf/OOfPM88xZpUpKSkpKSmoN4CFgG7AdeLhof5wCeBD4n6v0AVOK9ssZgHau5e2i/XIGYHeIgLuL9ssZKAXMLeCukBm4S/kGcDuwEHgKGJai3aoQAVelaN8AtIjtO5SLAPcApwMCHAUaE7a9DegMtP0eGJOwbSPwXaDtGeBe5RrAeyGzqDOFiEOBJ4DZSWeviBcU/go7lWsAhwjnB2CEBXsjZKaG8alyDWAJ0Txvwd5zMfYWK9cABgFvRQxopQV7yyNsaR8GKRcRESt3Fb3ARAu2JgL/VNhqd1a8ChGXAV8DnwBTEz7P7gOa5NKfhydoNwU4AHwhNt0WLy3Ak8A+maWV9Mrvmov2s+YAJsmsScrnNh4DTgLMkGA3LTpIn6Z8BpgMdJGd88D9ykdkv3qS/PwM3KR8A3gFc7ykfAK4AfjLoIB/6D6Vq+iUkYQg8+Vq1qmsmO8/inmmKheRjElPyID0z5oi2rxmQcBXlYsAp2IGdTKizWYLAr6pXAS4GDOoC2HPJp2fsyDgTgN76WeB14GtUlbQdemNwFLgEeDGXGKlzPtpDka02WRBwI0ZfL8LWA38lCLu1H/86UbEEyfuBD4C/gsY0p/3A2Mj2rRaEHBhykVvS0XxPi2HC1u4gLsNCHYW2CNZl5nAyIS2FwB/Y4ZLkjJrsK/atQM5nNHpL4Fn0lT5Amm19djhW30n2lMrfEDNKZ08AczNaEuL9y520dHIBPNKxQ/s/YTOvZP0Fo2ws47qcAwYbVal+IGNAr6JcUiHSMtz2nia6rK3qplw4GZJ9YexNEH7sbrKJ/HbNrnWyJZysuE9d1JaqqOeAAwG2oA/A06sUzEAj0sWW6+EtcbvSWo4WeLFUQmKSS3ABmBIxHduBT6m9llmSjh93OIr6bQfeCPneZtfcINOU+KFnVV5LENf44DfcIsH8og3JkK81KknBp6RR3CPl/MIGJcwmJmyr0W4yQd5BPwsotPNKfsZIquaixzPI+BaEwd9gFm4y9k8Ao4EPpQ47V+9+maJ0Al/5cEV+jMLGBBgdNrMSRA5xuEq3apIGAiai9iKmULnHW8pSrj2iFNartEr2e/qCAnMNZgxriX0mGbbFm+xVPLqFT22F2wW6C9Q/+gc5zzT4jVKkcgXzhmtoQA78I/tJvOEffiHHvM4EwKuxF9WmBCwA3/ZZ0LAX/GXUyYE7MVfekwI2I2/dJkQ8Ef8xUjh6QD+0mFCwFb85UUTAo73ZA9cia6Rj88toEZOX/lGuzIFA9s5n1bjrqjjz3lEbPIonZXpoGgSEduu89qE6+ixtVkRryKl312nt+0cVQ0Y+M9Fm2SlqodZt8P4My9FiNMqwXanvOhS65wXXzvkDSczoUpJSUlJSUlJSYmqJy4DUByvz1Kes54AAAAASUVORK5CYII=\"\n";
html += "                  />\n";
html += "                </div>\n";
html += "              </div>\n";
"\n";
html += "              <div class=\"wind\">\n";
html += "                <img\n";
html += "                  src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAUCAYAAACNiR0NAAAACXBIWXMAAAsTAAALEwEAmpwYAAAA7UlEQVR4nNXUvUpDQRCG4YMY0VoL7bT2DoTUacTOPmhpIba5BBu9AMUUqSwlBHITCkqwUtBKOyVWNo8c3OJ43HA2P4V+MLDLsC8zu/Ntlv07YQd3eEcX69MCX3CGPVxjgIVCfhPHuMABlqqAc4X1hm9thf02PvGAPt5wj5XUasvABlqYD/vVAG/HDtexW4gmbsotR84d5pXGEk9+aoirqkcxCjiJsIbH/IFiyVNcjhG9MFoDLMeAJ2MCOzjC4kzaTbmPZ2n6SHKQ32MzKpoxB02l8sBPJNRmDXzFOfZTHJQlAPNv7TZ8CJUO+rv6ApN33Tivyxi1AAAAAElFTkSuQmCC\"\n";
html += "                /><span> 5 km/h</span>\n";
html += "              </div>\n";
html += "            </div>\n";
html += "          </article>\n";
"\n";
html += "          <div class=\"days\">\n";
html += "            <div class=\"row row-no-gutter\">\n";
html += "              <div class=\"col-md-6\">\n";
html += "                <div class=\"humidity\">\n";
html += "                  <?xml version=\"1.0\" ?><svg\n";
html += "                    fill=\"none\"\n";
html += "                    height=\"24\"\n";
html += "                    viewBox=\"0 0 24 24\"\n";
html += "                    width=\"24\"\n";
html += "                    xmlns=\"http://www.w3.org/2000/svg\"\n";
html += "                  >\n";
html += "                    <path\n";
html += "                      clip-rule=\"evenodd\"\n";
html += "                      d=\"M15.9451 21.9559C12.5884 23.5927 8.42477 23.0167 5.63598 20.2279C2.12126 16.7132 2.12126 11.0147 5.63598 7.49995L11.9999 1.13599L18.3639 7.49995C19.2521 8.38814 19.9158 9.41578 20.3551 10.5124C21.6543 13.7553 20.9906 17.6012 18.364 20.2278C17.6381 20.9538 16.8189 21.5298 15.9451 21.9559ZM7.05019 8.91416L11.9999 3.96441L16.9497 8.91416C18.274 10.2385 18.9568 11.9615 18.998 13.6968H5.00192C5.04309 11.9615 5.72585 10.2385 7.05019 8.91416Z\"\n";
html += "                      fill=\"currentColor\"\n";
html += "                      fill-rule=\"evenodd\"\n";
html += "                    /></svg\n";
html += "                  ><span> Humidity </span>\n";
html += "                  <h1>" + String(dht.readHumidity()) + "%</h1>\n";
html += "                </div>\n";
html += "              </div>\n";
"\n";
html += "              <div class=\"col-md-6\">\n";
html += "                <div class=\"gas\">\n";
html += "                  <?xml version=\"1.0\" ?><svg\n";
html += "                    class=\"gas-icon\"\n";
html += "                    style=\"enable-background: new 0 0 64 64\"\n";
html += "                    version=\"1.1\"\n";
html += "                    viewBox=\"0 0 64 64\"\n";
html += "                    xml:space=\"preserve\"\n";
html += "                    xmlns=\"http://www.w3.org/2000/svg\"\n";
html += "                    xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n";
html += "                  >\n";
html += "                    <g id=\"cloudy_sunny\" />\n";
html += "                    <g id=\"bright\" />\n";
html += "                    <g id=\"cloudy\" />\n";
html += "                    <g id=\"high_rainfall\" />\n";
html += "                    <g id=\"windy\" />\n";
html += "                    <g id=\"rain_with_thunder\" />\n";
html += "                    <g id=\"clear_night\" />\n";
html += "                    <g id=\"cloudy_night\" />\n";
html += "                    <g id=\"moon\" />\n";
html += "                    <g id=\"sun\" />\n";
html += "                    <g id=\"rainy_night\" />\n";
html += "                    <g id=\"windy_night\" />\n";
html += "                    <g id=\"night_rain_thunder\" />\n";
html += "                    <g id=\"windy_rain\" />\n";
html += "                    <g id=\"temperature\" />\n";
html += "                    <g id=\"humidity\" />\n";
html += "                    <g id=\"air_pressure\">\n";
html += "                      <g>\n";
html += "                        <path\n";
html += "                          d=\"M40.9,27.2l-7.6,12.9C32.9,40.1,32.5,40,32,40c-2.8,0-5,2.2-5,5s2.2,5,5,5s5-2.2,5-5c0-1.6-0.8-3-1.9-3.9l7.3-12.4    c2,2.3,3.3,5.2,3.5,8.4c0,0.5,0.5,0.9,1,0.9h3.4c0.5,0,0.8-0.3,1-0.7c0.5-1.7,0.7-3.5,0.7-5.3c0-11-9-20-20-20s-20,9-20,20    c0,1.8,0.2,3.6,0.7,5.3c0.1,0.4,0.5,0.7,1,0.7H17c0.5,0,1-0.4,1-0.9C18.5,29.7,24.6,24,32,24C35.4,24,38.5,25.2,40.9,27.2z M32,48    c-1.7,0-3-1.3-3-3s1.3-3,3-3s3,1.3,3,3S33.7,48,32,48z M25.8,23.3l-2.9-6.7c0,0,0-0.1-0.1-0.1c2.4-1.4,5.2-2.3,8.1-2.5v8    C29.2,22.2,27.4,22.6,25.8,23.3z M33,22v-8c3,0.2,5.7,1,8.1,2.5c0,0,0,0.1-0.1,0.1l-2.9,6.7C36.6,22.6,34.8,22.2,33,22z M49.6,36    h-1.7c-0.3-2.3-1.1-4.4-2.2-6.3l3.6-2.7c0.5,1.6,0.7,3.2,0.7,5C50,33.4,49.8,34.7,49.6,36z M48.6,25.1c-0.1,0-0.2,0.1-0.2,0.1    l-3.9,2.9c-0.3-0.4-0.7-0.8-1.1-1.2l1.4-2.4c0.3-0.5,0.1-1.1-0.4-1.4c-0.5-0.3-1.1-0.1-1.4,0.4l-1.2,2c-0.6-0.5-1.3-0.9-1.9-1.3    l2.8-6.5C45.4,19.6,47.4,22.1,48.6,25.1z M16.1,36h-1.7c-0.3-1.3-0.4-2.6-0.4-4c0-1.7,0.3-3.4,0.7-5l3.6,2.7    C17.2,31.6,16.4,33.7,16.1,36z M19.5,28.1l-3.9-2.9c-0.1-0.1-0.1-0.1-0.2-0.1c1.2-3,3.3-5.5,5.8-7.5l2.8,6.5    C22.2,25.2,20.7,26.5,19.5,28.1z\"\n";
html += "                        />\n";
html += "                        <path\n";
html += "                          d=\"M56,51h-6.3c5.1-4.7,8.3-11.5,8.3-19C58,17.7,46.3,6,32,6c-1.1,0-2.2,0.1-3.3,0.2C27.9,4.3,26.1,3,24,3h-1    c-2.2,0-4,1.8-4,4c0,0.8,0.3,1.5,0.8,2c-1.1,0.6-2.1,1.2-3.1,2H4c-0.6,0-1,0.4-1,1s0.4,1,1,1h10.3C9.2,17.7,6,24.5,6,32    c0,14.3,11.7,26,26,26c5.7,0,11-1.9,15.3-5H56c1.7,0,3,1.3,3,3s-1.3,3-3,3h-1c-1.1,0-2-0.9-2-2c0-0.6,0.4-1,1-1c0.6,0,1-0.4,1-1    s-0.4-1-1-1c-1.7,0-3,1.3-3,3c0,2.2,1.8,4,4,4h1c2.8,0,5-2.2,5-5S58.8,51,56,51z M22,8c-0.6,0-1-0.4-1-1c0-1.1,0.9-2,2-2h1    c1.1,0,2.1,0.6,2.6,1.6C25,6.9,23.5,7.4,22,8C22,8,22,8,22,8z M26.9,8.5C26.7,9.9,25.5,11,24,11h-3.6C22.4,9.9,24.6,9,26.9,8.5z     M32,56C18.8,56,8,45.2,8,32c0-7.7,3.7-14.6,9.4-19H24c2.7,0,4.9-2.1,5-4.8C30,8.1,31,8,32,8c13.2,0,24,10.8,24,24    c0,7.7-3.7,14.6-9.4,19H28c-0.6,0-1,0.4-1,1s0.4,1,1,1h15.6C40.2,54.9,36.2,56,32,56z\"\n";
html += "                        />\n";
html += "                      </g>\n";
html += "                    </g>\n";
html += "                  </g>\n";
html += "                  </svg\n";
html += "                  ><span> Gas Concentration </span>\n";
html += "                  <h1>" + String(gasVal)+ " ppm</h1>\n";
html += "                </div>\n";
html += "              </div>\n";
html += "            </div>\n";
html += "          </div>\n";
html += "        </div>\n";
html += "      </div>\n";
html += "    </div>\n";
html += "  </body>\n";
html += "</html>\n";

  server.send(200, "text/html", html);
}

void handleNotFound() {
  server.send(404, "text/plain", "Not Found");
}
