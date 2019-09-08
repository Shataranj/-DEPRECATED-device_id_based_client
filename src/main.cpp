#include <Arduino.h>
#include "network.h"
#include "ApiClient.h"

String is_connected;
String response;

void setup() {
  Serial.begin(9600);
  Network myConnection("Hogwarts2", "TheBoyWhoLived");
  is_connected = myConnection.ConnectToWiFi();
  ApiClient apiclient("https://chess-sever.herokuapp.com/");
  response = apiclient.createGame("create","y");
}

void loop() {
  Serial.println(response);
  delay(1000);
}