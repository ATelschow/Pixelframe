void text() 
{


//Propeller 

if (textablauf == 0)
   {
   propix = 32 - propx;
   propiy = 32 - propy;  
   matrix->drawLine(propx, propy, propix, propiy, 256);
   FastLED.show();
   if (textzlr <32) (propx++);
   if (textzlr >=32) (propy++);
   FastLED.clear();
   textzlr++;
   if (textzlr>64)
      {
      textzlr=0;
      textablauf=1;
      propx=0;
      propy=0;
      }
   }




if (textablauf == 1)
   {
   matrix->drawCircle(0, 0, circle_r[0] , 512);
   matrix->fillCircle(0, 0, circle_r[0] , 512);
   matrix->drawCircle(31, 0, circle_r[0] , 512);
   matrix->fillCircle(31, 0, circle_r[0] , 512);
   matrix->drawCircle(0, 31, circle_r[0] , 512);
   matrix->fillCircle(0, 31, circle_r[0] , 16);
   matrix->drawCircle(31, 31, circle_r[0] , 512);
   matrix->fillCircle(31, 31, circle_r[0] , 5);
   circle_r[0]++;

   FastLED.show();
   FastLED.clear();
   
   textzlr++;
   if (textzlr>32)
      {
      textzlr=24;
      textablauf=2;
      circle_r[0]=0;
      }
   }

if (textablauf == 2)
   {
   
   matrix->fillScreen(0);
   matrix->setTextSize(2);
   matrix->setTextWrap(false);
   matrix->fillScreen(0);
   matrix->setTextColor(matrix->Color(0,0,0),matrix->Color((scroll*-1),(scroll*-1)+100,(scroll*-1)-80));
   scrollzlr++;
   if (scrollzlr >7) (scrollzlr = 0);
   matrix->setCursor(scroll, 8);
   matrix->print(F("       Das unglaubliche Lichtspektakel   "));
   matrix->show();
   scroll--;
   if (scroll < -500)
      {
      scroll = 32;
      textablauf = 3;
      }
   }

if (textablauf == 3)
   {
   if (textzlr % 24 == 0)
      {
      c1[index1]=random(0,32); 
      c2[index1]=random(0,32);
      circle_r[index1] =1;
      index1++;

      if (index1 > 7)
         {
         index1=0;
         }
      }
   if ( textzlr % 3 == 0)
      {
      matrix->drawCircle(c1[index1], c2[index1], circle_r[index1] , matrix->Color(c1[index1]*10,c2[index1]*5,c1[index1]*8));
      matrix->fillCircle(c1[index1], c2[index1], circle_r[index1] , matrix->Color(c1[index1]*10,c2[index1]*5,c1[index1]*8));

      //FastLED.clear();
      
      circle_r[index1]++;
      if (circle_r[index1] > 15) (circle_r[index1] =0 );
      }
      FastLED.show();
   textzlr++;
   if (textzlr>1000)
      {
      textzlr=0;
      textablauf=0;
      circle_r[0]=0;
      circle_r[1]=0;
      circle_r[2]=0;
      circle_r[3]=0;
      circle_r[4]=0;
      circle_r[5]=0;
      circle_r[6]=0;
      circle_r[7]=0;

      }
   }

// GPIO5=1;

// int c=0;

// for (zlr=0; zlr <254; zlr++)
// {
// matrix->fillScreen(matrix->Color(zlr,zlr*0.5,zlr*2));
// // matrix->drawPixel(0, 0, CHSV(zlr, zlr,zlr));   
// // c = CRGB(zlr, zlr,zlr);
// // Serial.print ("c:");
// // Serial.print (c);
// FastLED.show();
// delay(30);
// }


}