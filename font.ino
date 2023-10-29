void font()
{


int font_thousand = 0;
int font_hundred = 0;
int font_ten = 0;
int font_one = 0;
int font_negativ = 12;
int font_score = 0;
int font_position_x = 5;


// int fontzaehler=0;

if (score < 0)
   {
   font_negativ = 11;
   font_score = score *-1;
   }
else
   {
   font_score = score;
   }

font_thousand = font_score / 1000;
font_hundred = (font_score - (font_thousand*1000))  / 100;
font_ten = (font_score - ((font_thousand*1000) + (font_hundred*100)))  / 10;
font_one = (font_score - ((font_thousand*1000) + (font_hundred*100) + (font_ten*10)));




if ((font_thousand == 0) && (font_hundred == 0) && (font_ten == 0))
   {
   font_ten = 12;
   }
if ((font_thousand == 0) && (font_hundred == 0))
   {
   font_hundred = 12;
   }
if (font_thousand == 0)
   {
   font_thousand = 12;
   }

         Serial.print ("thousand : ");
         Serial.println (font_thousand);
         Serial.print ("hundred : ");
         Serial.println (font_hundred);
         Serial.print ("ten : ");
         Serial.println (font_ten);
         Serial.print ("one : ");
         Serial.println (font_one);



//Zeichenauswahl
// fontzaehler = font_one;


font_position_x = drawnumber(font_negativ, font_position_x);

font_position_x = drawnumber(font_thousand, font_position_x);

font_position_x = drawnumber(font_hundred, font_position_x);

font_position_x = drawnumber(font_ten, font_position_x);

font_position_x = drawnumber(font_one, font_position_x);
}

int drawnumber(int fontzaehler, int font_pos_x )
{
int font_position_y = 18;
int font_a[28];
int font_1[] = {12,1,0,0,0,1,0,2,0,3,0,4};
int font_2[] = {24,3,0,0,0,2,0,3,0,4,1,0,1,2,1,4,2,0,2,1,2,2,2,4};
int font_3[] = {24,3,0,0,0,2,0,4,1,0,1,2,1,4,2,0,2,1,2,2,2,3,2,4};
int font_4[] = {20,3,0,0,0,1,0,2,1,2,2,0,2,1,2,2,2,3,2,4};
int font_5[] = {24,3,0,0,0,1,0,2,0,4,1,0,1,2,1,4,2,0,2,2,2,3,2,4};
int font_6[] = {26,3,0,0,0,1,0,2,0,3,0,4,1,0,1,2,1,4,2,0,2,2,2,3,2,4};
int font_7[] = {16,3,0,0,1,0,2,0,2,1,2,2,2,3,2,4};
int font_8[] = {28,3,0,0,0,1,0,2,0,3,0,4,1,0,1,2,1,4,2,0,2,2,1,2,2,3,2,4};
int font_9[] = {22,3,0,0,0,1,0,2,1,0,1,2,2,0,2,1,2,2,2,3,2,4};
int font_0[] = {26,3,0,0,0,1,0,2,0,3,0,4,1,0,1,4,2,0,2,1,2,2,2,3,2,4};
int font_11[] = {8,3,0,2,1,2,2,2};

if (fontzaehler == 1)
   {
   for (i=0; i < font_1[0]; i++)
      {
      font_a[i] = font_1[i];
      }
   }
if (fontzaehler == 2)
   {
   for (i=0; i < font_2[0]; i++)
      {
      font_a[i] = font_2[i];
      }
   }

if (fontzaehler == 3)
   {
   for (i=0; i < font_3[0]; i++)
      {
      font_a[i] = font_3[i];
      }
   }

if (fontzaehler == 4)
   {
   for (i=0; i < font_4[0]; i++)
      {
      font_a[i] = font_4[i];
      }
   }

if (fontzaehler == 5)
   {
   for (i=0; i < font_5[0]; i++)
      {
      font_a[i] = font_5[i];
      }
   }

if (fontzaehler == 6)
   {
   for (i=0; i < font_6[0]; i++)
      {
      font_a[i] = font_6[i];
      }
   }

if (fontzaehler == 7)
   {
   for (i=0; i < font_7[0]; i++)
      {
      font_a[i] = font_7[i];
      }
   }

if (fontzaehler == 8)
   {
   for (i=0; i < font_8[0]; i++)
      {
      font_a[i] = font_8[i];
      }
   }

if (fontzaehler == 9)
   {
   for (i=0; i < font_9[0]; i++)
      {
      font_a[i] = font_9[i];
      }
   }

if (fontzaehler == 0)
   {
   for (i=0; i < font_0[0]; i++)
      {
      font_a[i] = font_0[i];
      }
   }

if (fontzaehler == 11)
   {
   for (i=0; i < font_11[0]; i++)
      {
      font_a[i] = font_11[i];
      }
   }

if (fontzaehler == 12)
   {
   return font_pos_x;
   }

for (i=0; i<font_a[0]; i++)
   {
   if (( i % 2 == 0) && (i > 0))
      {
      matrix->drawPixel((font_a[i] + font_pos_x),(font_a[i+1] + font_position_y),(CHSV(100, 130,200)));
      }
   }
font_pos_x = font_pos_x + font_a[1] +1;
return font_pos_x;
}