/**
 * @file mqtt.cpp
 * @author Patrick Schöttle (patrick.p.schoettle@gmail.com)
 * @brief Publisher client
 * @version 0.1
 * @date 2023-05-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include "mosquitto.h"

int main()
{
    int rc;
    struct mosquitto *mosq;

    mosquitto_lib_init();
    mosq = mosquitto_new("publisher-test", true, NULL);
    rc = mosquitto_connect(mosq, "localhost", 1883, 60);

    if (rc != 0)
    {
        printf("Client could not connect to broker! Error Code: %d\n", rc);
        mosquitto_destroy(mosq);
        return -1;
    }
    printf("We are now connected to the broker!\n");

    mosquitto_publish(mosq, NULL, "test/t1", 6, "Hello", 0, false);
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);

    mosquitto_lib_cleanup();
    return 0;
}
