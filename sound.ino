#include <Adafruit_NeoPixel.h>
 
#define PIN 6       //信号端子のピン番号
#define LED_NUM 20  //LEDの数
 
Adafruit_NeoPixel ledtape = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);  //3つめのパラメータは使うLEDテープの制御ICがWS2812ならNEO_KHZ800 / WS2811ならNEO_KHZ400

void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  ledtape.begin();
  ledtape.show();   //一旦全てOFFの状態で反映
}
void loop()
{
  int val;
  uint16_t i, j;
  
  val=analogRead(0);   //connect mic sensor to Analog 0
  Serial.println(val,DEC);//print the sound value to serial
  
  if(val >= 255){
    val = 255;
  }
  
  for(i=0; i < ledtape.numPixels(); i++) {
    ledtape.setPixelColor(i, val, 255, 255);
  }

/*
  if(val > 255){
    ledtape.setBrightness(255);
  }
  else if(val <= 50){
    ledtape.setBrightness(50);   
  }
  else{
    ledtape.setBrightness(val);
  }
  */
   
  ledtape.show();
  delay(100);
}
