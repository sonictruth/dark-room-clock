# DARK ROOM CLOCK
Using Geek Magic ESP8266 clone. Added a speaker and a button using the only available GPIO.


Replace setup after installing the libs:
.pio/libdeps/esp8266/TFT_eSPI/User_Setup_Select.h
```#include <User_Setup.h>``` 
with
```#include <tft.h>```


