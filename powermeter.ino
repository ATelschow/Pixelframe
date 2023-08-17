void powermeter(){
  i=0;
  while (i<256){
    r = 90;
      g = 160;
      b = 0;

      a = random(15);
  for (j=0; j<16; j++){   
     leds[i] =CRGB( r, g, b);
     r=r+10;
     g=g-10; 
     
     if (a<j) (leds[i] =CRGB( 0, 0, 0));
     i++;
  
  }
  a = random(15);
  for (j=0; j<16; j++){   
     leds[i] =CRGB( r, g, b);
     r=r-10;
     g=g+10; 
     if (a>j) (leds[i] =CRGB( 0, 0, 0));
     i++;
  }
 

 
  Serial.print(r); 
    Serial.print("[]");
  Serial.print(g); 
    Serial.print("[]");
  Serial.println(b); 

  }
  FastLED.show();
  delay(100);
}
