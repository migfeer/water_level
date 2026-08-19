## Water level system

### Status:

- 

### Work in progress:

- Send data constanly after susbscribe a topic, also add a topic for errors.

### Next:

- [x] Create code for mesaure water level and print on serial port with Arduino nano.
- [x] Create schemme for PCB.
- [x] Buy 3 octocuplers PC817C.
- [] Build code to send data via MQTT with Mosquitto en Rasberry pi as a local server.
    - [x] Install mosquitto on rasberrypi, send and receive data
    - [x] Connect esp32 to wifi
    - [x] Send data via mqtt from esp32 to mosquitto.
    - [x] Send data of sensors to mosquitto constantly.
- [] Build web app back-end.
- [] Build web app front-end.
- [] Test wifi signal on the 4 floor.
- [] Build PCB with ESP32. Consider the size of a box.
- [] Build structure for sensors.
- [] Test it before to install.
- [] Install in water tank.


## Decisiones de diseño:

- Alimentacion 9V.
- Uso de octoacopladores PC817C para aislamiento galvanico.
- Tamaño de PCB: 700x700mm maximo.
- Caja: 800x800mm: [caja_pase](https://www.sodimac.com.pe/sodimac-pe/articulo/113536589/caja-de-pase-ip54-800x800x35mm/113536593)
- 

## Materiales:

- ESP32 DevKit V1 micro usb
- 04 leds rojos.
- 04 PC817C.
- 04 sensores de nivel horizontal.


### Bugs:


### References:
- [Uso basico kicad](https://www.youtube.com/watch?v=EPH23zhPg50)
- [MQTT with ESP32 tutorial](https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/)
- [Install mosquitto on rasberrypi](https://randomnerdtutorials.com/how-to-install-mosquitto-broker-on-raspberry-pi/)
- [Doc pub subclient](https://github.com/knolleary/pubsubclient/tree/master)
