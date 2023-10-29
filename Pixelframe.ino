// DEVICETYPE1 = 1m x 1m
// DEVICETYPE2 = 1024 Ikea Frame
// DEVICETYPE3 = 256 Ikea Frame
#define DEVICETYPE2 true


#include <Adafruit_GFX.h>  
#include <Adafruit_NeoPixel.h>
#include <FastLED_NeoMatrix.h>
#include <arduinoFFT.h>
#include <driver/i2s.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
// #include <Update.h>


TaskHandle_t Task1;
TaskHandle_t Task2;

#include <inserts.h>
// inserts.h contains:
// if defined(DEVICETYPE1) ||  defined(DEVICETYPE2) || defined(DEVICETYPE3)
// const char* ssid = "your Wifi ssid";
// const char* password = "your Wifi password";  
// #endif




#include "variablen.h"
#include "wifiweb.h"
#include "gif.h"
#include "fft.h"
#include "led.h"
#include "gif2.h"
#include "fire.h"



 void setup() 
{
Serial.begin(115200);
setup_all();
}

int32_t raw_samples[SAMPLES];

void Task1code( void * pvParameters )
{
Serial.print("Task1 running on core ");
Serial.println(xPortGetCoreID());
for(;;)
   {
   read_buttons();
   if ((GPIO5 == 1) || (GPIO5 == 2) || (GPIO5 == 4)  || (GPIO5 == 5)) (Musik2());
   else delay(100);
   }
}


void Task2code( void * pvParameters )
{
Serial.print("Task2 running on core ");
Serial.println(xPortGetCoreID());
for(;;)
   {
   if (GPIO5 == 1) (Musik());
   if ((GPIO5 == 2) || (GPIO5 == 4) || (GPIO5 == 5))  (square_new());
   if (GPIO5 == 3) (make_fire());
   if (GPIO5 == 6) (text());
   if (GPIO5 == 7) (gif());
   if (GPIO5 == 8) (game());
   if (GPIO5 == 9) (zeigeIP());
   //if (GPIO1 == 0) (test());
      //else delay(100);
   }
}


void loop()
{
EVERY_N_MILLISECONDS(100) 
   {
   FastLED.setBrightness(GPIO4);

   // Joy1_button_A_FE = digitalRead(Joy1_button_A_inPin);
   // Joy1_button_B_FE = digitalRead(Joy1_button_B_inPin);
   // Serial.print ("Joy1_button_A_FE : ");
   // Serial.println (Joy1_button_A_FE);
   // Serial.print ("Joy1_button_B_FE : ");
   Serial.println (Joy1_button_B_FE);
   if ((Joy1_button_A_RE == 1) && (GPIO5 != 8))
      {
      if (GPIO5 == 9)
         {
         GPIO5 = 1;
         }
      else
         {
         GPIO5++;
         }
         Joy1_button_A_RE = 0;
      }
   if ((Joy1_button_B_RE == 1) && (GPIO5 != 8))
      {
      if (GPIO5 == 1)
         {
         GPIO5 = 9;
         }
      else
         {
         GPIO5--;
         }
      Joy1_button_B_RE = 0;
      }
   }
}
