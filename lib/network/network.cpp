#include <WiFi.h>
#include "network.h"

using namespace std;

Network::Network(char *ssid, char *password)
{
    this->ssid = ssid;
    this->password = password;
}

String Network::ConnectToWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 
  for(int count=0; count < 10; count++){
    if(isWifiConnected()){
      return "connected";
    }
    delay(500);
  }
  return "not connected";
}

bool Network::isWifiConnected()
{
  return WiFi.status() == WL_CONNECTED;
}