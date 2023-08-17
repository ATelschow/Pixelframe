void Musik()
{
cycle=cycle + (millis()-altmillis);
altmillis=millis();
v++;
if (v>100)
   {
    cycle = cycle / 100;
    Serial.print ("cycle:");
   Serial.print (cycle);
   Serial.println ("ms");
   cycle =0;
   v=0;
   }

adaptsum=0;
for (int i = 0; i < 32; i++)
   {
   adaptsum = adaptsum + adapt[i];
   }



adaptzlr++;
if (adaptzlr > 100)
   {
   Serial.print(adaptcnt);
   Serial.print("::");
   Serial.print(adaptsum);
   Serial.print("::");
   Serial.println(AMPLITUDE);
   if (adaptcnt < 70 && adaptsum >50 && AMPLITUDE >200 && LED_COUNT == 1024) (AMPLITUDE = AMPLITUDE -20);
   if (adaptcnt > 400 && LED_COUNT == 1024) (AMPLITUDE = AMPLITUDE +20);
   if (adaptcnt < 70 && adaptsum >25 && AMPLITUDE >500 && LED_COUNT == 256) (AMPLITUDE = AMPLITUDE -20);
   if (adaptcnt > 250 && LED_COUNT == 256) (AMPLITUDE = AMPLITUDE +20);
   adaptcnt=0;
   adaptzlr=0;
   }

if (GPIO6 != GPIO6old)
   {
   AMPLITUDE = GPIO6;
   GPIO6old = GPIO6;
   }

FastLED.clear();

// Process the FFT data into bar heights

for (byte band = 0; band < NUM_BANDS; band++) 
   {
   // Scale the bars for the display
   if (NUM_BANDS == 32) (barHeight = bandValues[band] / AMPLITUDE);
   else if (NUM_BANDS == 16) (barHeight = (bandValues[(band*2)]+bandValues[((band*2)+1)]) / (2*AMPLITUDE));

   //Serial.printf("%ld\n", barHeight);
   if (barHeight > TOP) barHeight = TOP;
   if (barHeight >= (kMatrixHeight-(kMatrixHeight/16))) (adaptcnt++);


   adapt[band] = barHeight;

   // Small amount of averaging between frames
   //int barHeighttemp = ((oldBarHeights[band] * 2) + (1*barHeight)) / 3;
   int barHeighttemp = ((oldBarHeights[band] * 1) +(oldBarHeights1[band] * 1) + (1*barHeight)) / 3;
   oldBarHeights1[band] = oldBarHeights[band];
   oldBarHeights[band] = barHeight;
   barHeight = barHeighttemp;

   //Serial.printf("%ld\n", barHeight);
   // Move peak up
   if (barHeight > peak[band]) 
      {
      peak[band] = min(TOP, barHeight);
      }
  
   /*
   EVERY_N_SECONDS(30) 
      {
      if (r<3) (r++);
      else (r=0);
      }

   if (r==0) (rainbowBars(band, barHeight));
   if (r==1) (purpleBars(band, barHeight));
   if (r==2) (centerBars(band, barHeight));
   if (r==3) (changingBars(band, barHeight));
   if (r==4) (waterfall(band));
   */

   centerBars(band, barHeight);

   // Save oldBarHeights for averaging later

   }

// Decay peak
EVERY_N_MILLISECONDS(60)
   {
   for (byte band = 0; band < NUM_BANDS; band++)
   if (peak[band] > 0) peak[band] -= 1;
   colorTimer++;
   }

// Used in some of the patterns
EVERY_N_MILLISECONDS(10)
   {
   colorTimer++;
   }

 FastLED.show();
}



void rainbowBars(int band, int barHeight) {
  int xStart = BAR_WIDTH * band;
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) {
    for (int y = TOP; y >= TOP - barHeight; y--) {
      matrix->drawPixel(x, y, CHSV((x / BAR_WIDTH) * (255 / NUM_BANDS), 255, 255));
    }
  }
}

void purpleBars(int band, int barHeight) {
  int xStart = BAR_WIDTH * band;
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) {
    for (int y = TOP; y >= TOP - barHeight; y--) {
      matrix->drawPixel(x, y, ColorFromPalette(purplePal, y * (255 / (barHeight + 1))));
    }
  }
}

void changingBars(int band, int barHeight) {
  int xStart = BAR_WIDTH * band;
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) {
    for (int y = TOP; y >= TOP - barHeight; y--) {
      matrix->drawPixel(x, y, CHSV(y * (255 / kMatrixHeight) + colorTimer, 255, 255));
    }
  }
}

void centerBars(int band, int barHeight)
   {
   int xStart = BAR_WIDTH * band;
   for (int x = xStart; x < xStart + BAR_WIDTH; x++)
      {
      if ((barHeight % 2) == 0) barHeight--;
      int yStart = ((kMatrixHeight - barHeight) / 2 );
      for (int y = yStart; y <= (yStart + barHeight); y++) 
         {
         int colorIndex = constrain((y - yStart) * (255 / barHeight), 0, 255);
         //matrix->drawPixel(x, y, CHSV(y * (255 / kMatrixHeight) + colorTimer, 255, 255));
         matrix->drawPixel(x, y, ColorFromPalette(heatPal, colorIndex));
         }
      }
   }

void waterfall(int band) {
  int xStart = BAR_WIDTH * band;
  double highestBandValue = 10000;        // Set this to calibrate your waterfall

  // Draw bottom line
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) {
    matrix->drawPixel(x, 0, CHSV(constrain(map(bandValues[band],0,highestBandValue,160,0),0,160), 255, 255));
  }

  // Move screen up starting at 2nd row from top
  if (band == NUM_BANDS - 1){
    for (int y = kMatrixHeight - 2; y >= 0; y--) {
      for (int x = 0; x < kMatrixWidth; x++) {
        int pixelIndexY = matrix->XY(x, y + 1);
        int pixelIndex = matrix->XY(x, y);
        leds[pixelIndexY] = leds[pixelIndex];
      }
    }
  }
}