void game()
{
while ((GPIO5 == 8) && (selected_game == gs_none))
   {
   if (Joy1_button_B_RE == 1)
      {
      if (game_select_menu < 2)
         {
         game_select_menu = 2;   
         }
      else if (game_select_menu > 1)
         {
         game_select_menu = 0;   
         }
      Joy1_button_B_RE = 0;
      }
   if (Joy1_button_A_RE == 1)
      {
     if (game_select_menu < 2)
         {
         selected_game = gs_breakout;  
         Ablaufsteuerung = 0;
         for (i=0; i<24; i++)
            {
            Blocks[i] = Blocks_full[i];
            }
         ballx=15;
         bally=15;
         ballmx=0;
         ballmy=1;
         ballxi=0;
         ballyi=0;
         ballxi_old=0;
         ballyi_old=0;
         score = 0;
         gamespeed = 100;
         }
      else if (game_select_menu > 1)
         {
         init_pong();
         selected_game = gs_pong;
         }
      Joy1_button_A_RE = 0;
      }

// Ausgabe
   EVERY_N_MILLISECONDS(100) 
      {
      if (game_select_menu == 0)
         {
         matrix->setTextColor(0xFFFF);
         matrix->fillScreen(0);
         matrix->setTextSize(1);
         matrix->setTextWrap(false);
         matrix->setCursor(0, 0);
         matrix->print(F("Break-"));
         matrix->setCursor(0, 10);
         matrix->print(F("out"));
         matrix->setCursor(0, 20);
         matrix->print(F("Pong"));
         matrix->show();
         game_select_menu = 1;
         }
      else if (game_select_menu == 1)
         {
         matrix->fillScreen(0);
         matrix->setTextSize(1);
         matrix->setTextWrap(false);
         matrix->setCursor(0, 20);
         matrix->print(F("Pong"));
         matrix->show();
         game_select_menu = 0;
         }
      else if (game_select_menu == 2)
         {
         matrix->fillScreen(0);
         matrix->setTextSize(1);
         matrix->setTextWrap(false);
         matrix->setCursor(0, 0);
         matrix->print(F("Break-"));
         matrix->setCursor(0, 10);
         matrix->print(F("out"));
         matrix->setCursor(0, 20);
         matrix->print(F("Pong"));
         matrix->show();
         game_select_menu = 3;
         }
      else if (game_select_menu == 3)
         {
         matrix->fillScreen(0);
         matrix->setTextSize(1);
         matrix->setTextWrap(false);
         matrix->setCursor(0, 0);
         matrix->print(F("Break-"));
         matrix->setCursor(0, 10);
         matrix->print(F("out"));
         matrix->show();
         game_select_menu = 2;
         }
      }
   }

while ((GPIO5 == 8))
   {
   if (selected_game == gs_breakout)
      {
      EVERY_N_MILLISECONDS(gamespeed) 
         {
         if (Ablaufsteuerung == 0)
            {
            Breakout_main();
            }
         else if (Ablaufsteuerung == 1)
            {
            Breakout_punkte();
            }
         }
      }
   if (selected_game == gs_pong)
      {
      EVERY_N_MILLISECONDS(gamespeed) 
         {
         pong_main();
         }
      }
   }
}


void Breakout_main()
{
      FastLED.clear();

      boat = read_Joy1_Analog();
      if (boat >28) (boat = 28);
      Joy1_Analog = 0;

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
               score = score + (1 * superscore);
               superscore = superscore * 2;
               }
            }
         }

      // wall collision detection
      if (ballxi == 31) (ballmx = ballmx * -1);
      if (ballxi == 0) (ballmx = ballmx * -1);
      if (ballyi == 0) (ballmy = ballmy * -1);

      // Boat collision detection
      if (ballyi == 31)
         {
         if ((ballxi == boat) && (ballxi == 0))
            {
            ballmx = 1.72;
            ballmy = -1;
            superscore = 1;
            }
         else if (ballxi == boat)
            {
            ballmx = -1.72;
            ballmy = -1;
            superscore = 1;
            }
         else if (ballxi == (boat+1))
            {
            ballmx = -0.58;
            ballmy = -1;
            superscore = 1;
            }
         else if (ballxi == (boat+2))
            {
            ballmx = 0.58;
            ballmy = -1;
            superscore = 1;
            }
         else if ((ballxi == (boat+3)) && (ballxi == 31))
            {
            ballmx = - 1.72;
            ballmy = -1;
            superscore = 1;
            }
         else if (ballxi == (boat+3))
            {
            ballmx = 1.72;
            ballmy = -1;
            superscore = 1;
            }
         }

// Ball im Aus
      if (ballyi > 31)
         {
         ballx = 15;
         bally = 15;
         ballmx = 0;
         ballmy = 1;
         score -= 10;
         superscore = 1;
         }

         // Serial.print ("ballx : ");
         // Serial.println (ballx);
         // Serial.print ("bally : ");
         // Serial.println (bally);
         // Serial.print ("ballmx : ");
         // Serial.println (ballmx);
         // Serial.print ("ballmy : ");
         // Serial.println (ballmy);
         // Serial.print ("ballxi : ");
         // Serial.println (ballxi);
         // Serial.print ("ballyi : ");
         // Serial.println (ballyi);
         // Serial.print ("gamespeed : ");
         // Serial.println (gamespeed);
         
//Alles Abgeraeumt?
      for (i=0; i<24; i++)
         {
         BlocksSum += Blocks[i];
         }
      if (BlocksSum == 0)
         {
         Ablaufsteuerung = 1;
         }
      BlocksSum = 0;

// Ausgabe
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

// Scrore

   // matrix->setTextSize(1);
   // matrix->setTextWrap(false);
   // matrix->setTextColor(2438);
   // matrix->setCursor(5, 18);
   // matrix->print(score);
font(score, 5, 18);

      // Ballausgabe
      matrix->drawPixel(ballxi, ballyi, CHSV(100, 130,200));
    

      // Boatausgabe
      matrix->drawPixel(boat, 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+1), 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+2), 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+3), 31, CHSV(255, 255,100));





      FastLED.show();       
}

void Breakout_punkte()
{
if (firstcall == 1)
   {
   starttime = millis();
   firstcall = 0;
   score += 10;
   }

   matrix->fillScreen(0);
   matrix->setTextSize(0);
   matrix->setTextWrap(false);
   matrix->setCursor(4, 4);
   matrix->fillScreen(0);
   matrix->print(score);
   matrix->show();


if ((millis() - starttime) >= 1500)
   {
   firstcall = 1;
   Breakout_nextlevel();
   }

}

void Breakout_nextlevel()
{
Ablaufsteuerung = 0;

for (i=0; i<24; i++)
   {
   Blocks[i] = Blocks_full[i];
   }
ballx=15;
bally=15;
ballmx=0;
ballmy=1;
ballxi=0;
ballyi=0;
ballxi_old=0;
ballyi_old=0;
gamespeed -= 10;
Breakout_main();
}

void pong_main()
{
int paddel_1 = 0;
int paddel_2 = 0;
FastLED.clear();
paddel_1 = read_Joy1_Analog();
paddel_2 = read_Joy2_Analog();
if (paddel_1 >28) (paddel_1 = 28);
if (paddel_2 >28) (paddel_2 = 28);

// move ball
ballx=ballx+ballmx;
bally=bally+ballmy;

ballxi_old = ballxi;
ballyi_old = ballyi; 

ballxi = (int) (ballx +0.5);
ballyi = (int) (bally +0.5);
if (ballyi > 31) (ballyi = 31);
if (ballyi < 0) (ballyi = 0);

// wall collision detection
if (ballyi == 0) (ballmy = ballmy * -1);
if (ballyi == 31) (ballmy = ballmy * -1);

// paddle_1 collision detection
if (ballxi == 0)
   {
   if ((ballyi == paddel_1) && (ballyi == 0))
      {
      ballmx = 1;
      ballmy = 1.72;
      }
   else if (ballyi == paddel_1)
      {
      ballmx = 1;
      ballmy = -1.72;
      }
   else if (ballyi == (paddel_1+1))
      {
      ballmx = 1;
      ballmy = -0.58;
      }
   else if (ballyi == (paddel_1+2))
      {
      ballmx = 1;
      ballmy = 0.58;
      }
   else if ((ballyi == (paddel_1+3)) && (ballyi == 31))
      {
      ballmx = 1;
      ballmy = -1.72;
      }
   else if (ballyi == (paddel_1+3))
      {
      ballmx = 1;
      ballmy = 1.72;
      }
   }

// paddle_2 collision detection
if (ballxi == 31)
   {
   if ((ballyi == paddel_2) && (ballyi == 0))
      {
      ballmx = -1;
      ballmy = 1.72;
      }
   else if (ballyi == paddel_2)
      {
      ballmx = -1;
      ballmy = -1.72;
      }
   else if (ballyi == (paddel_2+1))
      {
      ballmx = -1;
      ballmy = -0.58;
      }
   else if (ballyi == (paddel_2+2))
      {
      ballmx = -1;
      ballmy = 0.58;
      }
   else if ((ballyi == (paddel_2+3)) && (ballyi == 31))
      {
      ballmx = -1;
      ballmy = -1.72;
      }
   else if (ballyi == (paddel_2+3))
      {
      ballmx = -1;
      ballmy = 1.72;
      }
   }

if (ballxi < 0)
   {
   ballx = 30;
   bally = random(0,32);
   ballmx = -1;
   ballmy = 0;
   score_2 += 1;
   }

if (ballxi > 31)
   {
   ballx = 1;
   bally = random(0,32);
   ballmx = 1;
   ballmy = 0;
   score_1 += 1;
   }

// Ballausgabe
matrix->drawPixel(ballxi, ballyi, CHSV(100, 130,200));

font(score_1, 3, 1);
font(score_2, 22, 1);

// paddel ausgabe
matrix->drawPixel(0, (paddel_1), CHSV(255, 255,100));
matrix->drawPixel(0, (paddel_1+1), CHSV(255, 255,100));
matrix->drawPixel(0, (paddel_1+2), CHSV(255, 255,100));
matrix->drawPixel(0, (paddel_1+3), CHSV(255, 255,100));

matrix->drawPixel(31, (paddel_2), CHSV(255, 255,100));
matrix->drawPixel(31, (paddel_2+1), CHSV(255, 255,100));
matrix->drawPixel(31, (paddel_2+2), CHSV(255, 255,100));
matrix->drawPixel(31, (paddel_2+3), CHSV(255, 255,100));

FastLED.show();       



}


int read_Joy1_Analog()
{
      // read controller
      Joy1_Analog = 0;
      Joy1_Analog += analogRead(Joy1_Analog_inPin);      
      Joy1_Analog += analogRead(Joy1_Analog_inPin);
      Joy1_Analog += analogRead(Joy1_Analog_inPin);      
      Joy1_Analog += analogRead(Joy1_Analog_inPin);           
      Joy1_Analog += analogRead(Joy1_Analog_inPin);
      Joy1_Analog += analogRead(Joy1_Analog_inPin);      
      Joy1_Analog += analogRead(Joy1_Analog_inPin);
      return  (Joy1_Analog / 988);
}

int read_Joy2_Analog()
{
      // read controller
      Joy2_Analog = 0;
      Joy2_Analog += analogRead(Joy2_Analog_inPin);      
      Joy2_Analog += analogRead(Joy2_Analog_inPin);
      Joy2_Analog += analogRead(Joy2_Analog_inPin);      
      Joy2_Analog += analogRead(Joy2_Analog_inPin);           
      Joy2_Analog += analogRead(Joy2_Analog_inPin);
      Joy2_Analog += analogRead(Joy2_Analog_inPin);      
      Joy2_Analog += analogRead(Joy2_Analog_inPin);
      return  (Joy2_Analog / 988);
}

void init_pong()
{
score_1 = 0;
score_2 = 0;
ballmy = 0;
ballx=15;
bally=15;
ballxi=0;
ballyi=0;
ballxi_old=0;
ballyi_old=0;
gamespeed = 100;
ballmx = 0;
while (ballmx == 0)
   {
   ballmx = random (-1, 2);
   }
}