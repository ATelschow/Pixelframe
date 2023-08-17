void lauflichtvoll() {
  

g = random(255);
b = random(255);

r=random(100);

for (i=0; i<1024; i++){
 leds[i] =CRGB( r, g, b);
 
 if (i>3) {
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

 }
 FastLED.show();
/*Serial.print(i);
        Serial.print("[]");
        Serial.print(k);
        Serial.print("[]");
         Serial.println(r);*/
}

}
