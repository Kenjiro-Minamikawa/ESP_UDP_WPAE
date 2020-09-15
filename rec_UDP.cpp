#include "rec_UDP.h"

namespace ARRC{
    void UDP::Init(const char* id, const char* pwd){
        EAP_USERNAME = id;
        EAP_PASSWORD = pwd;
        WiFi.disconnect(true);
        WiFi.mode(WIFI_STA);
        esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
        esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_USERNAME, strlen(EAP_USERNAME)); 
        esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); 
        esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
        esp_wifi_sta_wpa2_ent_enable(&config);
        WiFi.begin(ssid);
        delay(1000);
        int count=0;
        while(WiFi.status() != WL_CONNECTED){
            delay(500);
            Serial.print(".");
            count++;
            if(count>=30){
                Serial.println("Time out, ESP will restart.");
                ESP.restart();
            }
        }
        Serial.println("");
        Serial.println("Connection Established!");
        Serial.print("IP address set:  ");
        Serial.print(WiFi.localIP());
        rec_udp.begin(12345);
    }

    void UDP::read(){
        uint8_t buffer[50] = {0};
        //double data;
        rec_udp.parsePacket();
        if((rec_udp.read(buffer, 50)>0) && ((uint8_t)atoi((const char*)buffer)==0xff)){
            for(int i=0;i<3;i++){
                Serial.println("");
                Serial.print("Data ");
                Serial.print(i+1);
                Serial.print(": ");
                rec_udp.parsePacket();
                rec_udp.read(buffer, 50);
                Serial.print((char *)buffer);
            }
            Serial.println("");
            //data = atof(const char*)
            //return 
        }
    }
}