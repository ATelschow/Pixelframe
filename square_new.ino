void square_new() 
{
if (LED_COUNT == 256)
   {
   EVERY_N_MILLISECONDS(25)
      { 
      startloop=1;
      }
   }
else startloop=1;

if (startloop==1)
   {
   startloop=0;
   int ix,iy=0;
   int il_=31;

   for (int zlr=((kMatrixWidth/2)-1);zlr>=0;zlr--)
      {
      if (GPIO5==2)
         {
         if (color[zlr]>254) (Richtung=-1);
         if (color[zlr]<0) (Richtung=1);
         if (zlr>0) (color[zlr] = color[(zlr-1)]);
         else (color[zlr]=  color[(zlr)] + (random(100)*Richtung)/3);
         //Serial.println(color[zlr]);
         }

      if (GPIO5==4)
         {
         if (color[zlr]>254) (Richtung=-1);
         if (color[zlr]<0) (Richtung=1);
         if (zlr>0) (color[zlr] = color[(zlr-1)]);
         else
            {
            //(color[zlr]=  color[(zlr)] + (bandValues[0]*Richtung)/1000);
            (color[zlr]= (bandValues[GPIO7]/250));
            // Serial.print(GPIO7);
            // Serial.print(" ");
            // Serial.println(color[zlr]);
            }
         }
      if (GPIO5==5)
         {
         color[zlr]= ((bandValues[(zlr*2)]+bandValues[((zlr*2)+1)])/AdaptSquareValue);    
         AdaptSquareSum =  AdaptSquareSum + color[zlr];
         
         //Serial.print(bandValues[zlr]);
         // Serial.print("Hallo");
         // Serial.println(color[zlr]);
         }
      }
   AdaptSquareAvg = AdaptSquareAvg + (AdaptSquareSum / (kMatrixWidth / 2));
   AdaptSquareCounter++;
   if (AdaptSquareCounter == AdaptSquareCycles)
      {
      AdaptSquareAvg = AdaptSquareAvg / AdaptSquareCycles;
      if (AdaptSquareAvg < 5000 && AdaptSquareValue >= 35)  (AdaptSquareValue--);
      if (AdaptSquareAvg > 6000) (AdaptSquareValue++);
      Serial.print(AdaptSquareAvg);
      Serial.print(" : ");
      Serial.println(AdaptSquareValue);
      AdaptSquareCounter = 0;
      AdaptSquareAvg = 0;
      AdaptSquareSum = 0;
      }
   if (GPIO6 != GPIO6old)
      {
      AdaptSquareValue = GPIO6 / 4;
      GPIO6old = GPIO6;
      }

   for (int il=0; il<(kMatrixWidth/2); il++)
      {
      il_=(kMatrixWidth-1)-il;

      for (iy=0; iy<kMatrixHeight; iy++)
         {
         for (ix=0; ix<kMatrixWidth; ix++) 
            {
            if (GPIO5==4 || GPIO5==5)
               {
               if ( ((ix == il) && (iy >= il) && (iy <= il_)) 
                  || ((ix == il_) && (iy <= il_) && (iy >= il)) 
                  || ((iy == il) && (ix >= il) && (ix <= il_))  
                  || ((iy == il_)  && (ix >= il) && (ix <= il_)))   
                  (matrix->drawPixel(ix, iy, CHSV((color[il]), (color[il]),(color[il]))));       
               }
            if (GPIO5==2)
               {
               if ( ((ix == il) && (iy >= il) && (iy <= il_)) 
                     || ((ix == il_) && (iy <= il_) && (iy >= il)) 
                     || ((iy == il) && (ix >= il) && (ix <= il_))  
                     || ((iy == il_)  && (ix >= il) && (ix <= il_)))   
                     (matrix->drawPixel(ix, iy, CHSV((color[il]), 255,255)));       
               }
            }
         }
      }

   FastLED.show();   
   //delay(50);
   cycle=cycle + (millis()-altmillis);
   altmillis=millis();
   v++;
   if (v>100) 
      {
      cycle = cycle / 100;
      // Serial.print ("cycle:");
      // Serial.print (cycle);
      // Serial.println ("ms");
      cycle =0;
      v=0;
      }
   }
}