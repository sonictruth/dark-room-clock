#include "mainview.h"

#define DEBOUNCE_MS 50
#define DOUBLE_CLICK_MS 400
#define LONG_PRESS_MS 1500

#define TIME_VIEW_SCREEN 0
#define SET_TIMER1_SCREEN 1
#define SET_TIMER2_SCREEN 2
#define SET_TIMER3_SCREEN 3
#define SET_TIMER4_SCREEN 4

#define TOTAL_SCREENS 5

#define PREFS_TIMER_KEY "timer"

const char *funnyPhrases[][2] = {
    { "Ding!", "Masterpiece or mess." },
    { "Time's up!", "Develop feelings." },
    { "That's all, folks!", " Wash hands." },
    { "Surprise!", " Perfect or abstract." },
    { "Exposure done! ", "Light fumbling." },
    { "Avoided sun,", " get cookie!" },
    { "Time out!", " Not the cat." },
    { "Behold!", " Truth and light." },
    { "Done!", " Chemicals, hopefully." },
    { "Timer spoke!", " Hang art." },
    { "Secret mission ", "complete!" },
    { "Ta-da!", " Magic or mud?" },
    { "Time out!", " Door closed?" },
    { "Finished!", " Safely squint now." },
    { "And...", " that's a wrap!" },
    { "Over!", " No more dark fumbling." },
    { "Darkroom adventure ", "concluded!" },
    { "Alert!", " Eyes ready for sun." },
    { "Moment of truth...", " chuckle." },
    { "All clear!", " Spilled nothing?" },
    { "Congrats!", "Survived another session." },
    { "Light calls!", "Bladder too." },
    { "You're free!", "Develop good habits." },
    { "Done!", "Resist early peek." },
    { "Face light!", "And consequences." },
    { "Mission accomplished!", "Print reveal." },
    { "No more...", "darkness now!" },
    { "Darkroom giveth,", "taketh time." },
    { "Voila!", "Negative to positive." }
};

int currentScreen = TIME_VIEW_SCREEN;
static int padding = 5;

String timerMinutesAndSecondsString = "03:00";
int timerLeftSeconds = -1;
int timerTotal = 0;

unsigned long lastSecond = 0;
int16_t lastEndAngle = 0;

struct tm timeinfo;

#define TFT_RED1 ((24 << 11) | (0 << 5) | 0)
#define TFT_RED2 ((20 << 11) | (0 << 5) | 0)
#define TFT_RED3 ((17 << 11) | (0 << 5) | 0)
#define TFT_RED4 ((5 << 11) | (0 << 5) | 0)

void drawPie(int x, int y, int radius, int percent)
{
    percent = constrain(percent, 0, 100);

    // Calculate the end angle for the given percent
    int16_t endAngle = map(percent, 0, 100, 0, 360);

    // If percent is 0, just clear the pie and draw the outline
    if (percent == 0)
    {
        tft.fillCircle(x, y, radius, TFT_RED4);
        tft.drawCircle(x, y, radius, TFT_RED3);
        lastEndAngle = 0;
        return;
    }

    // Determine if we need to redraw the whole pie
    bool fullRedraw = (lastEndAngle == 0) || (endAngle < lastEndAngle);

    if (fullRedraw)
    {
        tft.fillCircle(x, y, radius, TFT_RED4);
        tft.drawCircle(x, y, radius, TFT_RED3);
    }

    // Draw the pie segments from the last angle to the new end angle
    int16_t startAngle = fullRedraw ? 0 : lastEndAngle;
    int innerradius = radius - 2;
    for (int16_t angle = startAngle; angle < endAngle; ++angle)
    {
        float rad1 = radians(angle - 90);
        float rad2 = radians(angle + 1 - 90);

        int x1 = x + innerradius * cos(rad1);
        int y1 = y + innerradius * sin(rad1);
        int x2 = x + innerradius * cos(rad2);
        int y2 = y + innerradius * sin(rad2);

        int color;
        if (angle < 90)
            color = TFT_RED1;
        else if (angle < 180)
            color = TFT_RED2;
        else if (angle < 270)
            color = TFT_RED1;
        else
            color = TFT_RED2;
        tft.fillTriangle(x, y, x1, y1, x2, y2, color);
    }

    lastEndAngle = endAngle;
}

void renderPie()
{
    int piePercent = 0;

    if (timerLeftSeconds >= 0)
    {
        if (timerTotal > 0)
        {
            piePercent = 100 - (timerLeftSeconds * 100) / timerTotal;
        }
        else
        {
            piePercent = 0;
        }
    }
    else
    {
        piePercent = (timeinfo.tm_sec * 100) / 60;
    }
    drawPie(tft.width() / 2, (tft.height() / 2) - 15, 80, piePercent);
}

void renderTimer()
{
    char timerStr[16];
    if (timerLeftSeconds >= 0)
    {
        tft.setTextColor(TFT_RED, TFT_BLACK);
        int minutes = timerLeftSeconds / 60;
        int seconds = timerLeftSeconds % 60;
        snprintf(timerStr, sizeof(timerStr), "%02d:%02d", minutes, seconds);
        timerLeftSeconds--;
    }
    else
    {
        tft.setTextColor(TFT_RED3, TFT_BLACK);
        strncpy(timerStr, timerMinutesAndSecondsString.c_str(), sizeof(timerStr) - 1);
        timerStr[sizeof(timerStr) - 1] = '\0';
    }

    static String lastDrawnStr = "";
    if (String(timerStr) != lastDrawnStr)
    {

        tft.fillRect(0, tft.height() - 43, tft.width(), 43, TFT_BLACK);
        tft.drawString(timerStr, tft.width() / 2, tft.height() - padding);
        lastDrawnStr = String(timerStr);
        Serial.printf("Timer: %d %s\n", timerLeftSeconds, timerStr);

        int elapsedSeconds = timerTotal - timerLeftSeconds;

        if (timerLeftSeconds >= 0 && elapsedSeconds > 0 && elapsedSeconds % 60 == 0)
        {
            playBeep2();
        }
        else if (timerLeftSeconds >= 0 && elapsedSeconds > 0 && elapsedSeconds % 15 == 0)
        {
            playBeep1();
        }
        else
        {
            playBeep();
        }
        if (timerLeftSeconds < 0 && String(timerStr) == "00:00")
        {
            int idx = random(0, sizeof(funnyPhrases) / sizeof(funnyPhrases[0]));
            showText(funnyPhrases[idx][1], funnyPhrases[idx][0]);
            
            playAlarm();
            tft.fillScreen(TFT_BLACK);
        }
    }
}

void renderTimeAndDate()
{

    char timeStr[10];
    char dateStr[32];

    snprintf(timeStr, sizeof(timeStr), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    snprintf(dateStr, sizeof(dateStr), "%02d/%02d/%04d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900);

    tft.setFreeFont(&Roboto_Condensed_Bold_22);

    tft.setTextSize(1);
    tft.setTextColor(TFT_RED1, TFT_BLACK);

    tft.setTextDatum(TL_DATUM);
    tft.drawString(timeStr, padding, 0);
    tft.setTextDatum(TR_DATUM);
    tft.drawString(dateStr, tft.width() - padding, 0);

    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.setTextDatum(BC_DATUM);
    tft.setFreeFont(&LCD24pt7b);
}

void startTimer()
{
    int minutes = timerMinutesAndSecondsString.substring(0, 2).toInt();
    int seconds = timerMinutesAndSecondsString.substring(3, 5).toInt();
    timerLeftSeconds = minutes * 60 + seconds;
    timerTotal = timerLeftSeconds;
    renderTimer();
}

void renderSetTimerScreen()
{
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    int pos = -1;
    if (currentScreen == SET_TIMER1_SCREEN)
    {
        pos = 0;
    }
    else if (currentScreen == SET_TIMER2_SCREEN)
    {
        pos = 1;
    }
    else if (currentScreen == SET_TIMER3_SCREEN)
    {
        pos = 3;
    }
    else if (currentScreen == SET_TIMER4_SCREEN)
    {
        pos = 4;
    }

    tft.setFreeFont(&Roboto_Condensed_Bold_22);
    tft.drawString("", tft.width() / 2, 10);
    tft.drawString("once to increase", tft.width() / 2, 50);
    tft.drawString("twice to advance", tft.width() / 2, 70);
    tft.setFreeFont(&LCD24pt7b);

    int strLen = timerMinutesAndSecondsString.length();
    int charWidth = tft.textWidth("0") + 10;
    int totalWidth = charWidth * 4;

    int startX = (tft.width() - totalWidth) / 2;
    int y = tft.height() / 2;

    int x = startX;
    for (int i = 0; i < strLen; ++i)
    {
        if (i == pos)
        {
            tft.setTextColor(TFT_RED, TFT_BLACK);
        }
        else
        {
            tft.setTextColor(TFT_RED3, TFT_BLACK);
        }
        String ch = String(timerMinutesAndSecondsString[i]);
        tft.drawString(ch, x, y);
        x += charWidth;
    }
}

void handlSetTimerPress()
{
    int timerValue;
    int pos = -1;
    int maxValue = 10;
    if (currentScreen == SET_TIMER1_SCREEN)
    {
        pos = 0;
        maxValue = 6;
    }
    else if (currentScreen == SET_TIMER2_SCREEN)
    {
        pos = 1;
        maxValue = 10;
    }
    else if (currentScreen == SET_TIMER3_SCREEN)
    {
        pos = 3;
        maxValue = 6;
    }
    else if (currentScreen == SET_TIMER4_SCREEN)
    {
        pos = 4;
        maxValue = 10;
    }

    if (pos != -1)
    {
        timerValue = timerMinutesAndSecondsString.substring(pos, pos + 1).toInt();
        timerValue = (timerValue + 1) % maxValue;
        timerMinutesAndSecondsString.setCharAt(pos, '0' + timerValue);
    }
    prefs.putString(PREFS_TIMER_KEY, timerMinutesAndSecondsString);
    renderSetTimerScreen();
}

void resetTimer()
{
    timerLeftSeconds = -1;
    lastEndAngle = 0;
}

void onePush()
{
    Serial.println("One push detected");
    if (currentScreen == TIME_VIEW_SCREEN)
    {
        if (timerLeftSeconds > 0)
        {
            Serial.println("Timer already running, resetting timer");
            resetTimer();
        }
        else
        {
            Serial.println("Starting timer");
            startTimer();
        }
    }
    else if (currentScreen >= SET_TIMER1_SCREEN && currentScreen <= SET_TIMER4_SCREEN)
    {
        Serial.println("handlSetTimer");
        handlSetTimerPress();
    }
    else
    {
        Serial.println("No action for this screen");
    }
}

void doublePush()
{
    Serial.println("Double push detected");
    resetTimer();
    tft.fillScreen(TFT_BLACK);
    currentScreen = (currentScreen + 1) % TOTAL_SCREENS;
    if (currentScreen >= SET_TIMER1_SCREEN && currentScreen <= SET_TIMER4_SCREEN)
    {
        renderSetTimerScreen();
    }
}

void longPush()
{
    Serial.println("Long push detected");
    if (currentScreen == TIME_VIEW_SCREEN)
    {
        resetTimer();
        renderTimer();
    }
}

void handleButton()
{
    static uint32_t lastDown = 0;
    static uint32_t lastUp = 0;
    static uint8_t state = 0;
    static bool longPressFired = false;
    static uint8_t clickCount = 0;

    bool pressed = digitalRead(BUTTON_PIN) == LOW;

    uint32_t now = millis();

    switch (state)
    {
    case 0: // Idle
        if (pressed)
        {
            lastDown = now;
            longPressFired = false;
            state = 1;
        }
        break;
    case 1: // Button down
        if (!pressed)
        {
            lastUp = now;
            clickCount++;
            state = 2;
        }
        else if (!longPressFired && (now - lastDown > LONG_PRESS_MS))
        {
            longPush();
            longPressFired = true;
            state = 3; // Wait for release
        }
        break;
    case 2: // Button up, waiting for possible double click
        if (pressed && (now - lastUp < DOUBLE_CLICK_MS))
        {
            lastDown = now;
            state = 1;
        }
        else if (now - lastUp >= DOUBLE_CLICK_MS)
        {
            if (!longPressFired)
            {
                if (clickCount == 1)
                    onePush();
                else if (clickCount == 2)
                    doublePush();
            }
            clickCount = 0;
            state = 0;
        }
        break;
    case 3: // After long press, wait for release
        if (!pressed)
        {
            state = 0;
            clickCount = 0;
        }
        break;
    }
}

void runEverySecond()
{
    time_t now = time(nullptr);
    localtime_r(&now, &timeinfo);
    if (now != lastSecond)
    {
        renderTimeAndDate();
        renderPie();
        renderTimer();
        lastSecond = now;
    }
}

void mainLoop()
{
    static bool firstRun = true;
    if (firstRun)
    {
        timerMinutesAndSecondsString = prefs.getString(PREFS_TIMER_KEY, "03:00");
        firstRun = false;
    }
    if (currentScreen == TIME_VIEW_SCREEN)
    {
        runEverySecond();
    }

    handleButton();
}
