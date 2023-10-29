void read_buttons()
{
if ((Joy1_button_B == 0) && (digitalRead(Joy1_button_B_inPin) == 1))
   {
   Joy1_button_B_RE = 1;
   Joy1_button_B = 1;
   }
if ((Joy1_button_B == 1) && (digitalRead(Joy1_button_B_inPin) ==0))
   {
   Joy1_button_B_RE = 0;
   Joy1_button_B = 0;
   }
if ((Joy1_button_A == 0) && (digitalRead(Joy1_button_A_inPin) ==1))
   {
   Joy1_button_A_RE = 1;
   Joy1_button_A = 1;
   }
if ((Joy1_button_A == 1) && (digitalRead(Joy1_button_A_inPin) ==0))
   {
   Joy1_button_A_RE = 0;
   Joy1_button_A = 0;
   }


   if ((digitalRead(Joy1_button_A_inPin) == 1) && (digitalRead(Joy1_button_B_inPin) == 1))
      {
      if (doubble_press_cntr >= 7)
         {
         GPIO5 = 1;
         selected_game = gs_none;
         }
      else
         {
         doubble_press_cntr++;
         }
      }
   else
      {
      doubble_press_cntr = 0;
      }

}