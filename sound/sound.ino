#include <Adafruit_NeoPixel.h>
 
#define PIN 6       //信号端子のピン番号
#define LED_NUM 20  //LEDの数
#define DELAY 50  // 時間幅
 
Adafruit_NeoPixel ledtape = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);  //3つめのパラメータは使うLEDテープの制御ICがWS2812ならNEO_KHZ800 / WS2811ならNEO_KHZ400

int windows[] = {0, 0, 0, 0, 0};

void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  ledtape.begin();
  ledtape.show();   //一旦全てOFFの状態で反映
}

int smooth(int* win, int val) {
  for (int i = 1; i < sizeof(win) - 1; i++) {
    win[i] = win[i-1];
  }
  win[0] = val;

  int sum = 0;
  for (int i = 0; i < sizeof(win) - 1; i++) {
    sum += win[i];
  }
  return sum / sizeof(win);
}

void loop()
{
  int val;
  uint16_t i, j;
  
  val=analogRead(0);   //connect mic sensor to Analog 0
  //Serial.println(val,DEC);//print the sound value to serial

  int val2 = smooth(windows, val);
  
  if(val2 >= 255){
    val2 = 255;
  }
  Serial.println(val2,DEC);//print the sound value to serial

  for(i=0; i < ledtape.numPixels(); i++) {
    ledtape.setPixelColor(i, val, val, val);
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
  delay(DELAY);
}
