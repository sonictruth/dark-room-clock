# DARK ROOM CLOCK
A clock and countdown timer that can be used in a dark room by only displaying shades of red.

Hardware: Geek Magic Small TV/Weather Station ESP8266 clone. Added a speaker and a button using the only available GPIO.


Replace setup after installing the libs:

.pio/libdeps/esp8266/TFT_eSPI/User_Setup_Select.h

```#include <User_Setup.h>```  with ```#include <tft.h>```


