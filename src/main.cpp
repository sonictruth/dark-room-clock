#include "main.h"

TFT_eSPI tft = TFT_eSPI();

String defaultAP = "DarkRoomClock";
String defaultAPPassword = "photo1234";

char defaultTimezone[40] = "CET-1CEST,M3.5.0,M10.5.0/3";
char defaultBrightness[10] = "20";

#define TIMEZONE_SETTINGS_KEY "timezone"
#define BRIGHTNESS_SETTINGS_KEY "brightness"

Preferences prefs;
extern const char *songs[];

void configModeCallback(WiFiManager *myWiFiManager)
{
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
  String apInfo = "Setup Wifi: " + defaultAP + " Password: " + defaultAPPassword;
  showText(apInfo);
}

void setupWifi()
{
  WiFiManager wm;
  bool res;

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  bool isResetRequested = digitalRead(BUTTON_PIN) == LOW;
  if (isResetRequested)
  {
    wm.erase();
    prefs.clear();
  }

  wm.setBreakAfterConfig(true);
  wm.setEnableConfigPortal(false);
  wm.setConfigPortalTimeout(280);
  wm.setAPCallback(configModeCallback);

  if (prefs.getString(TIMEZONE_SETTINGS_KEY, "").isEmpty())
  {
    Serial.println("Setting default tz.");
    prefs.putString(TIMEZONE_SETTINGS_KEY, defaultTimezone);
  }
  if (prefs.getString(BRIGHTNESS_SETTINGS_KEY, "").isEmpty())
  {
    Serial.println("Setting default brightness.");
    prefs.putString(BRIGHTNESS_SETTINGS_KEY, defaultBrightness);
  }

  WiFiManagerParameter timezoneSetting(TIMEZONE_SETTINGS_KEY, "Timezone (Example: CET-1CEST,M3.5.0,M10.5.0/3)", prefs.getString(TIMEZONE_SETTINGS_KEY, "").c_str(), sizeof(defaultTimezone));
  WiFiManagerParameter brightnessSetting(BRIGHTNESS_SETTINGS_KEY, "Brightness (2-100)", prefs.getString(BRIGHTNESS_SETTINGS_KEY, "").c_str(), sizeof(defaultBrightness));

  wm.addParameter(&timezoneSetting);
  wm.addParameter(&brightnessSetting);

  if (isResetRequested)
  {
    wm.startConfigPortal(defaultAP.c_str(), defaultAPPassword.c_str());
    Serial.println("Save settings...");
    prefs.putString(TIMEZONE_SETTINGS_KEY, timezoneSetting.getValue());
    prefs.putString(BRIGHTNESS_SETTINGS_KEY, brightnessSetting.getValue());
    wm.reboot();
  }

  res = wm.autoConnect(defaultAP.c_str(), defaultAPPassword.c_str());

  if (!res)
  {
    showText("WiFi failed. Hold the button on power on to configure.");
    delay(5000);
    return;
  }
  else
  {
    showText("Connected!");
  }


  String timezone = prefs.getString(TIMEZONE_SETTINGS_KEY, "");
  Serial.printf("Timezone: %s\n", timezone.c_str());
  configTime(timezone.c_str(), "pool.ntp.org", "time.nist.gov");
  time_t now = time(nullptr);

  int retries = 0;

  while (now < 8 * 3600 * 2 && retries < 10)
  {
    delay(500);
    showText("Sync");
    now = time(nullptr);
    retries++;
  }
}

void setup()
{

  Serial.begin(115200);
  Serial.println("Starting...");

  prefs.begin("drt", false);

  pinMode(BACKLIGHT_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  setBrightnessPercent(0);

  analogWriteRange(255);
  analogWriteFreq(1000);

  tft.init();
  tft.setRotation(0);

  int brightness = atoi(prefs.getString(BRIGHTNESS_SETTINGS_KEY, "20").c_str());
  if (brightness < 2 || brightness > 100)
  {
    Serial.println("Invalid brightness value, using default 20");
    brightness = 20;
  }
  setBrightnessPercent(brightness);

  showText("Starting...");

  setupWifi();

  showText("Hello!");

  playStartSound();

  tft.fillScreen(TFT_BLACK);
}

void loop()
{
  mainLoop();
}
