#ifndef _WiFiConsts_
#define _WiFiConsts_

#include <ESP8266WiFi.h>

/* change it with your ssid-password */
const char* ssid = "239193 Info-Lan";
const char* password = "83435276";
IPAddress ip(192,168,0,230);  //статический IP
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

const byte DNS_PORT = 53;

//http://www.hivemq.com/demos/websocket-client
//http://www.hivemq.com

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

/* Not used yet*/
const char *mqtt_user = "Login"; // Логи от сервер
const char *mqtt_pass = "Pass";  // Пароль от сервера

 
/* topics */
#define LAMP_TOPIC     "cvtirer"

#endif