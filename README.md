# Technische Informatik Projekt 
## IoT Datenüberwachung einer Pflanzenbewässerung mit MQTT, InfluxDB und Grafana

Dieses Repository beinhaltet ein [docker-compose](https://docs.docker.com/compose/) und [ESP32 8266](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/index.html#) zur Datenüberwachung eines BME280 und Feuchtigkeitssensor. Zudem findet eine automatisierte Pflanzenbewässerung statt. 
Der ESP32 sendet die Daten an einen MQTT-Broker welcher auf einem Server gehostet ist. Dort findet eine Konvertierung der Daten in InfluxDB statt um sie dann der Benutzeroberfläche bereitzustellen. 