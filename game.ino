void game()
{

int boat=0;
float ballx=15;
float bally=15;
float ballmx=0;
float ballmy=1;
int ballxi=0;
int ballyi=0;
int ballxi_old=0;
int ballyi_old=0;
int Blocks[]={1,2,6,2,11,2,16,2,21,2,26,2,1,5,6,5,11,5,16,5,21,5,26,5,1,8,6,8,11,8,16,8,21,8,26,8,1,11,6,11,11,11,16,11,21,11,26,11};

while (GPIO5==8)
   {
   EVERY_N_MILLISECONDS(100) 
      {
      FastLED.clear();
      Joy_in_Value += analogRead(JoyPin);      
      Joy_in_Value += analogRead(JoyPin);
      Joy_in_Value += analogRead(JoyPin);      
      Joy_in_Value += analogRead(JoyPin);           
      Joy_in_Value += analogRead(JoyPin);
      Joy_in_Value += analogRead(JoyPin);      
      Joy_in_Value += analogRead(JoyPin);
      boat = Joy_in_Value / 988;
      if (boat >28) (boat = 28);
      Joy_in_Value = 0;

      // move ball
      ballx=ballx+ballmx;
      bally=bally+ballmy;

      ballxi_old = ballxi;
      ballyi_old = ballyi; 

      ballxi = (int) (ballx +0.5);
      if (ballxi > 31) (ballxi = 31);
      if (ballxi < 0) (ballxi = 0);
      ballyi = (int) (bally +0.5);      
      // if (ballyi > 31) (ballyi = 31);
      if (ballyi < 0) (ballyi = 0);



      // Blocks Ausgabe
      for (i=0; i<24; i++)
         {
         if (i % 2 == 0) 
            {
            if (Blocks[i] != 0 )
               {
               matrix->drawPixel(Blocks[i], Blocks[i+1], CHSV(100, 180,200));
               matrix->drawPixel((Blocks[i] +1), Blocks[i+1], CHSV(100, 180,200));
               matrix->drawPixel((Blocks[i] +2), Blocks[i+1], CHSV(100, 180,200));
               matrix->drawPixel((Blocks[i] +3), Blocks[i+1], CHSV(100, 180,200));
               matrix->drawPixel(Blocks[i], (Blocks[i+1]+1), CHSV(100, 180,200));
               matrix->drawPixel((Blocks[i] +1), (Blocks[i+1]+1), CHSV(100, 180,200));
               matrix->drawPixel((Blocks[i] +2), (Blocks[i+1]+1), CHSV(100, 180,200));
               matrix->drawPixel((Blocks[i] +3), (Blocks[i+1]+1), CHSV(100, 180,200));
               }
            }
         }

      // Blocks Kollisionsdetektion
      for (i=0; i<24; i++)
         {
         if ( ( (i % 2 == 0) && (Blocks[i] != 0) )
              && (    ballxi == (Blocks[i]) 
                  || (ballxi == (Blocks[i]+1))
                  || (ballxi == (Blocks[i]+2))
                  || (ballxi == (Blocks[i]+3)) ) )
            {
            if ( (ballyi == (Blocks[i+1]) ) || (ballyi == (Blocks[i+1]+1) ) )
               {
               if (ballyi_old == (Blocks[i+1]+2)) (ballmy = ballmy * -1);
               else if (ballyi_old == (Blocks[i+1]-1)) (ballmy = ballmy * -1);
               else if (ballxi_old == (Blocks[i]+4)) (ballmx = ballmx * -1);
               else if (ballxi_old == (Blocks[i]-1)) (ballmx = ballmx * -1);                    

               Blocks[i] = 0;
               Blocks[i+1] = 0;
               }
            }
         }



      // wall collision detection
      if (ballxi == 31) (ballmx = ballmx * -1);
      if (ballxi == 0) (ballmx = ballmx * -1);
      if (ballyi == 0) (ballmy = ballmy * -1);

      // Boat collision detection
      if ((ballyi == 31) && (ballxi == boat))
         {
         ballmx = -1.72;
         ballmy = -1;
         }
      if ((ballyi == 31) && (ballxi == (boat+1)))
         {
         ballmx = -0.58;
         ballmy = -1;
         }
      if ((ballyi == 31) && (ballxi == (boat+2)))
         {
         ballmx = 1.72;
         ballmy = -1;
         }
      if ((ballyi == 31) && (ballxi == (boat+3)))
         {
         ballmx = 0.58;
         ballmy = -1;
         }

      if (ballyi > 31)
         {
         ballx = 15;
         bally = 15;
         ballmx = 0;
         ballmy = 1;
         }

         Serial.print ("ballx : ");
         Serial.println (ballx);
         Serial.print ("bally : ");
         Serial.println (bally);
         Serial.print ("ballmx : ");
         Serial.println (ballmx);
         Serial.print ("ballmy : ");
         Serial.println (ballmy);
         Serial.print ("ballxi : ");
         Serial.println (ballxi);
         Serial.print ("ballyi : ");
         Serial.println (ballyi);

      // Ballausgabe
      matrix->drawPixel(ballxi, ballyi, CHSV(100, 130,200));
    

      // Boatausgabe
      matrix->drawPixel(boat, 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+1), 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+2), 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+3), 31, CHSV(255, 255,100));
      FastLED.show();       
      }

   }
}