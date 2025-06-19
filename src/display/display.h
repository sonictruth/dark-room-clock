#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <pins.h>
#include <TFT_eSPI.h>
#include <Preferences.h>
#include <font1.h>
#include <font2.h>

extern TFT_eSPI tft;
extern Preferences prefs;

void setBrightnessPercent(int percent);
void showSplash();
void showText(const String &text, const String &toptitle = "DarkRoomClock");

#endif