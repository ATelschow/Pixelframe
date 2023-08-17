void allebunt() {
  for (i=0;i<256;i++) {
 //ar[i]=random(255);
 //ag[i]=random(255);
 //ab[i]=random(255);
 r = random(255);
 g = random(255);
 b = random(255);
 leds[i] =CRGB( g, r, b);
}
FastLED.show();
delay(50);
cycle=millis()-altmillis;
altmillis=millis();
Serial.print ("cycle:");
Serial.print (cycle);
Serial.println ("ms");
}
