void game()
{

int boat=0;
int ballx=0;
int bally=0;
int ballmx=1;
int ballmy=1;

while (GPIO5==8)
   {
   EVERY_N_MILLISECONDS(100) 
      {
      FastLED.clear();

      boat = GPIO8;

      // move ball
      ballx=ballx+ballmx;
      bally=bally+ballmy;

      // wall collision detection
      if (ballx == 31) (ballmx = ballmx *-1);
      if (ballx == 0) (ballmx = ballmx * 1);
      if (bally == 31) (ballmy = ballmy * -1);
      if (bally == 0) (ballmy = ballmy * 1);

      matrix->drawPixel(ballx, bally, CHSV(100, 130,200));


      matrix->drawPixel(boat, 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+1), 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+2), 31, CHSV(255, 255,100));
      matrix->drawPixel((boat+3), 31, CHSV(255, 255,100));
      FastLED.show();       
      }

   }
}