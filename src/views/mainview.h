#ifndef TIME_H
#define TIME_H

#include <Arduino.h>
#include <pins.h>
#include <TFT_eSPI.h>
#include <Preferences.h>
#include "display.h"
#include "audio.h"

extern TFT_eSPI tft;
extern Preferences prefs;

void mainLoop();

#endif