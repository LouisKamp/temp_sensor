

Tutorial [link](https://github.com/espressif/ESP8266_RTOS_SDK/tree/83517ba1/examples)
Setup [link](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html#get-started-get-esp-idf)

Pins [link](https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/)
WIFI [link](https://esp32.com/viewtopic.php?t=9687)
WIFI2 [link](https://github.com/chmorgan/esphttpd-freertos/tree/master/main)

list all connected usb serial ports
```bash
ls /dev/tty.*
```

req server
```bash
curl -X POST 192.168.5.18:3500/test
```

build and monitor
```
make flash monitor
```