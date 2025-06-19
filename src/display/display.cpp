#include "display.h"
#include "splash.h"

// https://notisrac.github.io/FileToCArray/ 8bit grayscale LE

void drawBmp(const byte *imagePROGMEM, int16_t width, int16_t height, int16_t x, int16_t y)
{
  Serial.printf("Drawing BMP: at (%d, %d)\n", x, y);
  tft.setSwapBytes(true);
  uint16_t *lineBuffer = new uint16_t[width];

  if (!lineBuffer)
  {
    Serial.println("Failed to allocate line buffer");
    return;
  }

  for (int16_t row = 0; row < height; row++)
  {
    int32_t rowOffset = row * width;

    for (int16_t col = 0; col < width; col++)
    {
      uint8_t gray = pgm_read_byte(&imagePROGMEM[rowOffset + col]);

      // Convert to red-only RGB565 (keep red channel, zero out G and B)
      uint16_t rgb565 = ((gray & 0xF8) << 8); // 5 bits R, G and B are 0

      lineBuffer[col] = rgb565;
    }

    tft.pushImage(x, y++, width, 1, lineBuffer);
  }

  delete[] lineBuffer;
}
void showSplash()
{
  drawBmp(SPLASH, SPLASH_HEIGHT, SPLASH_WIDTH, 0, 0);
}

void showText(const String &text, const String &toptitle)
{
  showSplash();
  tft.setTextColor(TFT_RED);

  tft.setFreeFont(&Roboto_Condensed_Bold_22);
  int16_t x = TFT_WIDTH / 2;
  int16_t lineHeight = tft.fontHeight();
  int16_t maxWidth = 230; 


  tft.setTextDatum(TC_DATUM); 
  tft.drawString(toptitle, TFT_WIDTH / 2, 5);
  tft.setTextDatum(MC_DATUM); 

  // Split text into words
  std::vector<String> words;
  int start = 0, end = 0;
  while ((end = text.indexOf(' ', start)) != -1)
  {
    words.push_back(text.substring(start, end));
    start = end + 1;
  }
  words.push_back(text.substring(start));

  // Build lines with word wrapping
  std::vector<String> lines;
  String line = "";
  for (size_t i = 0; i < words.size(); ++i)
  {
    String testLine = line;
    if (!line.isEmpty())
      testLine += " ";
    testLine += words[i];
    int16_t testWidth = tft.textWidth(testLine);
    if (testWidth > maxWidth && !line.isEmpty())
    {
      lines.push_back(line);
      line = words[i];
    }
    else
    {
      if (!line.isEmpty())
        line += " ";
      line += words[i];
    }
  }
  if (!line.isEmpty())
  {
    lines.push_back(line);
  }

  // Draw lines starting from the bottom
  int16_t totalHeight = lines.size() * lineHeight;
  int16_t startY = TFT_HEIGHT - 10 - totalHeight + lineHeight / 2;

  for (size_t i = 0; i < lines.size(); ++i)
  {
    tft.drawString(lines[i], x, startY + i * lineHeight);
  }
}


void setBrightnessPercent(int percent)
{
  percent = constrain(percent, 0, 100);
  int brightness = map(percent, 0, 100, 255, 0);
  Serial.printf("Setting brightness to %d%% (%d)\n", percent, brightness);
  analogWrite(BACKLIGHT_PIN, brightness);
}
