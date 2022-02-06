/* RGB web server with ESP8266
* analogWrite with values received from web page
*
* WiFi router that creates a fixed domain: http://rgb
* web page returns POST request with 3 RGB parameters http://192.168.1.5/
* web page inspired by https://github.com/dimsumlabs/nodemcu-httpd
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Web.h"
#include "WiFiConsts.h"
#include "Const.h"
#include "Settings.h"

ESP8266WebServer webServer(80);
Settings leds;

void fade(int pin);
void testRGB();
void blinking(int pin);
void black();

void handleRoot() {
    String red = webServer.arg(0); // read RGB arguments
    String green = webServer.arg(1);
    String blue = webServer.arg(2);
    String mode = webServer.arg(3);
    if((red != "") && (green != "") && (blue != "") && (mode != "") ) {
        leds.setAll(red.toInt(), green.toInt(), blue.toInt(), mode.toInt());
        
        Serial.print("RED: ");
        Serial.println(red.toInt(), DEC);
        Serial.print("GREEN: ");
        Serial.println(green.toInt(), DEC);
        Serial.print("BLUE: ");
        Serial.println(blue.toInt(), DEC);
        // Serial.println();
        // analogWrite(redLED, MAX - red.toInt());
        // analogWrite(greenLED, MAX - green.toInt());
        // analogWrite(blueLED, MAX - blue.toInt());
    }
    webServer.send(200, "text/html", WEB);
}

void setup() {
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    analogWrite(redLED, MAX);
    analogWrite(greenLED, MAX);
    analogWrite(blueLED, MAX);
    delay(100);
    Serial.begin(115200);
    Serial.println();
    WiFi.begin(ssid, password);
    WiFi.config(ip, gateway, subnet);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    webServer.on("/", handleRoot);
    webServer.begin();
    // testRGB();
}

void loop() {
    webServer.handleClient();
    leds.show();
}

void testRGB() { // fade in and out of Red, Green, Blue
    analogWrite(redLED, MAX); // R off
    analogWrite(greenLED, MAX); // G off
    analogWrite(blueLED, MAX); // B off

    blinking(redLED);
    // delay(1000);
    blinking(greenLED);
    // delay(1000);
    blinking(blueLED);

    // black();
    // fade(redLED); // R
    // black();
    // delay(1000);
    // fade(greenLED); // G
    // black();
    // delay(1000);
    // fade(blueLED); // B
    // black();
}

void blinking(int pin) {
    for(int i = 0; i < 10; i++) {
        analogWrite(pin, 0);
        delay(100);
        black();
        delay(100);
    }
}

void black() {
    analogWrite(redLED, MAX);
    analogWrite(greenLED, MAX);
    analogWrite(blueLED, MAX);
}

void fade(int pin) {
    for (int u = 0; u < MAX; u++) {
        analogWrite(pin, u);
        delay(10);
    }
    for (int u = 0; u < MAX; u++) {
        analogWrite(pin, MAX - u);
        delay(10);
    }
}