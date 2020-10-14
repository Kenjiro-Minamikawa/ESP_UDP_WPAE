#ifndef rec_UDP_LIB_h
#define rec_UDP_LIB_h

#include <WiFi.h> //Wifi library
#include <esp_wpa2.h> //wpa2 library for connections to Enterprise networks
#include <WiFiUdp.h>
namespace ARRC{
    class UDP{
        public:
            void Init(const char* id, const char* pwd);
            double read();
            int available();
        private:
            WiFiUDP rec_udp;
            const char* EAP_IDENTITY="NO";
            const char* EAP_USERNAME;
            const char* EAP_PASSWORD;
            const char* ssid = "ANCT-K";
            const char* hostAddr = "172.16.18.113";

    };
};

#endif