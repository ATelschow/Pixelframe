void haelftebunt() {
  for (i=0;i<1024;i++) {
 //ar[i]=random(255);
 //ag[i]=random(255);
 //ab[i]=random(255);
 r = random(255);
 g = random(255);
 b = random(255);
 if (a%2==1 && i%2==1){
 leds[i] =CRGB( g, r, b);
  }
   if (a%2==1 && i%2==0){
 leds[i] =CRGB( 0, 0, 0);
  }
   if (a%2==0 && i%2==0){
 leds[i] =CRGB( g, r, b);
  }
  if (a%2==0 && i%2==1){
 leds[i] =CRGB( 0, 0, 0);
  }
}
FastLED.show();
a++;
delay(100);
cycle=millis()-altmillis;
altmillis=millis();
Serial.print ("cycle:");
Serial.print (cycle);
Serial.println ("ms");
}


