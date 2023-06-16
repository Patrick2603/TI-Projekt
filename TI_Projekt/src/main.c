#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"

#define SSID "WaltDisney"
#define PASSWORD "44947573422887866577"

void app_main(void)
{
    xTaskCreate(&wifi_init, "wifi_init_sta", 2048, NULL, 5, NULL);
}

void wifi_init(void)
{
    // Create an LwIP core task and initialize the LwIP related work
    esp_netif_init();
    // Create a system Event task and initialize an application event callback funtion
    esp_event_loop_create_default();
    // Create a default network interface instance binding station with TCP/IP stack
    esp_netif_create_default_wifi_sta();
    // Create Wifi driver task and initialize the Wifi driver
    esp_wifi_init();

    // Configure the Wifi driver sta mode
    esp_wifi_set_mode(WIFI_MODE_STA);

    // Configure Wifi driver SSID and password
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = "ssid",
            .password = "password",
        },
    };

    // Wifi Start phase
    esp_wifi_start();
    // Wifi Connect phase -> WIFI_EVENT_STA_CONNECTED will be generated, it starts the DHCP client
    esp_wifi_connect();
    // If Wifi connection fails -> WIFI_EVENT_STA_DISCONNECTED
}
