#include <WiFi.h>

using namespace std;
class Network{

public:
    const char *ssid;
    const char *password;

    Network(char *ssid, char *password);

    bool isWifiConnected();

    String ConnectToWiFi();
};