void Musik2()
{
cycle1 = cycle1 + (millis()-altmillis1);
altmillis1 = millis();
v1++;
if ( v1 > 100 ) 
   {
   cycle1 = cycle1 / 100;
   Serial.print ("cycle1:");
   Serial.print (cycle1);
   Serial.println ("ms");
   cycle1 =0;
   v1=0;
   }

// Sample the audio pin
// size_t bytes_read = 0;
// i2s_read(I2S_NUM_0, raw_samples, sizeof(int32_t) * SAMPLES, &bytes_read, portMAX_DELAY);
// int samples_read = bytes_read / sizeof(int32_t);
// for (int i = 0; i < SAMPLES; i++) 
//    {
//    vReal[i] =  raw_samples[i]/25000;      
//    vImag[i] = 0;
//    }

size_t bytes_read = 0;
i2s_read(I2S_NUM_0, raw_samples, sizeof(int32_t) * samples, &bytes_read, portMAX_DELAY);
int samples_read = bytes_read / sizeof(int32_t);
for (int i = 0; i < samples; i++) 
   {
   vReal[i] =  raw_samples[i]/25000;      
   vImag[i] = 0;
   }




// Compute FFT
// FFT.DCRemoval();
// FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
// FFT.Compute(FFT_FORWARD);
// FFT.ComplexToMagnitude();

    FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);	/* Weigh data */
    FFT.compute(FFTDirection::Forward); /* Compute FFT */
    FFT.complexToMagnitude(); /* Compute magnitudes */
   //  float x = FFT.majorPeak();

//Reset bandValues[]
for (int i = 0; i<32; i++)
   {
   bandValues[i] = 0;
   }

// Analyse FFT results
for (int i = 1; i < samples/2; i++)       // Don't use sample 0 and only first SAMPLES/2 are usable. Each array element represents a frequency bin and its value the amplitude.
   {
   if (vReal[i] > NOISE)                    // Add a crude noise filter
      {
      int b[32] = {1,2,3,4,5,6,7,8,10,13,17,22,30,45,60,70,80,90,100,110,120,130,140,150,165,178,190,203,218,235,243,248};
      if (i<=b[0]            )       bandValues[0]  += (int)vReal[i]/2;
      else if (i>b[0]  && i<=b[1] )  bandValues[1]  += (int)vReal[i]/4;
      else if(i>b[1]  && i<=b[2] )   bandValues[2]  += (int)vReal[i]/4;
      else if(i>b[2]  && i<=b[3] )   bandValues[3]  += (int)vReal[i]/4;
      else if(i>b[3]  && i<=b[4] )   bandValues[4]  += (int)vReal[i]/2;
      else if(i>b[4]  && i<=b[5] )   bandValues[5]  += (int)vReal[i];
      else if(i>b[5]  && i<=b[6] )   bandValues[6]  += (int)vReal[i];
      else if(i>b[6]  && i<=b[7] )   bandValues[7]  += (int)vReal[i];
      else if(i>b[7]  && i<=b[8] )   bandValues[8]  += (int)vReal[i];
      else if(i>b[8]  && i<=b[9] )   bandValues[9]  += (int)vReal[i];
      else if(i>b[9]  && i<=b[10] )  bandValues[10] += (int)vReal[i];
      else if(i>b[10] && i<=b[11] )  bandValues[11] += (int)vReal[i];
      else if(i>b[11] && i<=b[12] )  bandValues[12] += (int)vReal[i];
      else if(i>b[12] && i<=b[13] )  bandValues[13] += (int)vReal[i];
      else if(i>b[13] && i<=b[14] )  bandValues[14] += (int)vReal[i];
      else if(i>b[14] && i<=b[15] )  bandValues[15] += (int)vReal[i];
      else if(i>b[15] && i<=b[16] )  bandValues[16] += (int)vReal[i];
      else if(i>b[16] && i<=b[17] )  bandValues[17] += (int)vReal[i];
      else if(i>b[17] && i<=b[18] )  bandValues[18] += (int)vReal[i];
      else if(i>b[18] && i<=b[19] )  bandValues[19] += (int)vReal[i];
      else if(i>b[19] && i<=b[20] )  bandValues[20] += (int)vReal[i];
      else if(i>b[20] && i<=b[21] )  bandValues[21] += (int)vReal[i];
      else if(i>b[21] && i<=b[22] )  bandValues[22] += (int)vReal[i];
      else if(i>b[22] && i<=b[23] )  bandValues[23] += (int)vReal[i];
      else if(i>b[23] && i<=b[24] )  bandValues[24] += (int)vReal[i];
      else if(i>b[24] && i<=b[25] )  bandValues[25] += (int)vReal[i];
      else if(i>b[25] && i<=b[26] )  bandValues[26] += (int)vReal[i];
      else if(i>b[26] && i<=b[27] )  bandValues[27] += (int)vReal[i];
      else if(i>b[27] && i<=b[28] )  bandValues[28] += (int)vReal[i];
      else if(i>b[28] && i<=b[29] )  bandValues[29] += (int)vReal[i];
      else if(i>b[29] && i<=b[30] )  bandValues[30] += (int)vReal[i];
      else if(i>b[30]             )  bandValues[31] += (int)vReal[i];
      }
   }
}




// void Musik2(){

// cycle1=cycle1 + (millis()-altmillis1);
// altmillis1=millis();
//   v1++;
//   if (v1>100) {
//     cycle1 = cycle1 / 100;
//     Serial.print ("cycle1:");
// Serial.print (cycle1);
// Serial.println ("ms");
// cycle1 =0;
// v1=0;
//   }
  






//   // Sample the audio pin
// size_t bytes_read = 0;
// i2s_read(I2S_NUM_0, raw_samples, sizeof(int32_t) * SAMPLES, &bytes_read, portMAX_DELAY);
// int samples_read = bytes_read / sizeof(int32_t);
  
// for (int i = 0; i < SAMPLES; i++) {
//   vReal[i] =  raw_samples[i]/25000;      
//   vImag[i] = 0;
//   }

//   // Compute FFT
//   FFT.DCRemoval();
//   FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
//   FFT.Compute(FFT_FORWARD);
//   FFT.ComplexToMagnitude();

// //Reset bandValues[]
//  for (int i = 0; i<32; i++){
// bandValues[i] = 0;
//  }
//   // Analyse FFT results
//   for (int i = 1; i < SAMPLES/2; i++){       // Don't use sample 0 and only first SAMPLES/2 are usable. Each array element represents a frequency bin and its value the amplitude.
//     if (vReal[i] > NOISE) {                    // Add a crude noise filter

// int b[32] = {1,2,3,4,5,6,7,8,10,13,17,22,30,45,60,70,80,90,100,110,120,130,140,150,165,178,190,203,218,235,243,248};
//     //16 bands, 12kHz top band
//       if (i<=b[0]            ) bandValues[0]  += (int)vReal[i]/2;
//       if (i>b[0]  && i<=b[1] ) bandValues[1]  += (int)vReal[i]/4;
//       if (i>b[1]  && i<=b[2] ) bandValues[2]  += (int)vReal[i]/4;
//       if (i>b[2]  && i<=b[3] ) bandValues[3]  += (int)vReal[i]/4;
//       if (i>b[3]  && i<=b[4] ) bandValues[4]  += (int)vReal[i]/2;
//       if (i>b[4]  && i<=b[5] ) bandValues[5]  += (int)vReal[i];
//       if (i>b[5]  && i<=b[6] ) bandValues[6]  += (int)vReal[i];
//       if (i>b[6]  && i<=b[7] ) bandValues[7]  += (int)vReal[i];
//       if (i>b[7]  && i<=b[8] ) bandValues[8]  += (int)vReal[i];
//       if (i>b[8]  && i<=b[9] ) bandValues[9]  += (int)vReal[i];
//       if (i>b[9]  && i<=b[10]) bandValues[10] += (int)vReal[i];
//       if (i>b[10] && i<=b[11]) bandValues[11] += (int)vReal[i];
//       if (i>b[11] && i<=b[12]) bandValues[12] += (int)vReal[i];
//       if (i>b[12] && i<=b[13]) bandValues[13] += (int)vReal[i];
//       if (i>b[13] && i<=b[14]) bandValues[14] += (int)vReal[i];
//       if (i>b[14] && i<=b[15]) bandValues[15] += (int)vReal[i];
//       if (i>b[15] && i<=b[16]) bandValues[16]  += (int)vReal[i];
//       if (i>b[16]  && i<=b[17] ) bandValues[17]  += (int)vReal[i];
//       if (i>b[17]  && i<=b[18] ) bandValues[18]  += (int)vReal[i];
//       if (i>b[18]  && i<=b[19] ) bandValues[19]  += (int)vReal[i];
//       if (i>b[19]  && i<=b[20] ) bandValues[20]  += (int)vReal[i];
//       if (i>b[20]  && i<=b[21] ) bandValues[21]  += (int)vReal[i];
//       if (i>b[21]  && i<=b[22] ) bandValues[22]  += (int)vReal[i];
//       if (i>b[22]  && i<=b[23] ) bandValues[23]  += (int)vReal[i];
//       if (i>b[23]  && i<=b[24] ) bandValues[24]  += (int)vReal[i];
//       if (i>b[24]  && i<=b[25] ) bandValues[25]  += (int)vReal[i];
//       if (i>b[25]  && i<=b[26]) bandValues[26] += (int)vReal[i];
//       if (i>b[26] && i<=b[27]) bandValues[27] += (int)vReal[i];
//       if (i>b[27] && i<=b[28]) bandValues[28] += (int)vReal[i];
//       if (i>b[28] && i<=b[29]) bandValues[29] += (int)vReal[i];
//       if (i>b[29] && i<=b[30]) bandValues[30] += (int)vReal[i];
//       if (i>b[30]            ) bandValues[31] += (int)vReal[i];
//     }
//   }
 



// }