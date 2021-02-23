#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define LED_NUM 10  //LEDの数

Adafruit_NeoPixel ledtape = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);  
 
void setup() 
{
  ledtape.begin();
  ledtape.show();
}
 
void loop() 
{
  uint16_t i, j;
  for(j = 0; j < 256; j++) 
  {
    for(i = 0; i < ledtape.numPixels(); i++) 
    {
      ledtape.setPixelColor(i, rotateColor(
        ((i * 256 / ledtape.numPixels()) + j) & 255)
      );
    }
    ledtape.show();
    delay(20);
  }
}
 
//RGBの色の移り変わり関数
uint32_t rotateColor(byte WheelPos) 
{
  if(WheelPos < 85) 
  {
    return ledtape.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  else if(WheelPos < 170) 
  {
    WheelPos -= 85;
    return ledtape.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  else 
  {
    WheelPos -= 170;
    return ledtape.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
