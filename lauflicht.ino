void lauflicht() {
  


r = random(255);
g = random(255);
b = random(255);

for (i=0; i<256; i++){
 leds[i] =CRGB( r, g, b);
 

 k=i-1;
 r1=r/2;
 g1=g/2;
 b1=b/2;
 leds[k] =CRGB( r, g, b);

 k=i-2;
  r1=r1/2;
 g1=g1/2;
 b1=b1/2;
 leds[k] =CRGB( r, g, b);

  k=i-3;
  r1=r1/2;
 g1=g1/2;
 b1=b1/2;
 leds[k] =CRGB( r, g, b);

  k=i-4;
  r1=r1/2;
 g1=g1/2;
 b1=b1/2;
 leds[k] =CRGB( r, g, b);


k=i-5;
leds[k] =CRGB( 0, 0, 0);

FastLED.show();
Serial.print(i);
        Serial.print("[]");
        Serial.print(k);
        Serial.print("[]");
         Serial.println(r);
}




 
 
 
 
 /*l=2;
  for (j=0; j<LED_COUNT; j++){
      j++;
      j++;
        j++;
      j++;
      i = 0;
     r = random(255);
      g = random(255);
      b = random(255);
      
      while(i <(260-j))
      {
      strip.setPixelColor(i, g, r, b);
      i1=i;

     if (i>4){
      for (k=1 ; k<5; k++) {
        r1=r/l;
        g1=g/l;
        b1=b/l;
        i1--;
         strip.setPixelColor(i1, g1, r1, b1);
        l=l*2;
      }
     }
      l=2;
      //if (i>4){
      z=i-5;
      strip.setPixelColor(z, 0, 0, 0);
      // }
       
        strip.show();
     
      //  strip.setPixelColor(60-j, g, r, b);   
       // strip.show();
      
       Serial.print(i);
        Serial.print("[]");
        Serial.print(j);
        Serial.print("[]");
         Serial.println(z);
           i++;
           
  //     delay(10);
       cycle=millis()-altmillis;
altmillis=millis();
Serial.print ("cycle:");
Serial.print (cycle);
Serial.println ("ms");
        }
  }

*/
}
