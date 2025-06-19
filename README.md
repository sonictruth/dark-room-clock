#DARK ROOM CLOCK

Using Geek Magic espressif8266  clone

After installing/updating TFT libraries replace:

.pio/libdeps/esp8266/TFT_eSPI/User_Setup_Select.h
```#include <User_Setup.h>``` 
with
```#include <tft.h>```


