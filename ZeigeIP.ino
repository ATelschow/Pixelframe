void zeigeIP()
{
   matrix->fillScreen(0);
   matrix->setTextSize(1);
   matrix->setTextWrap(false);
   matrix->setCursor(scroll, 12);
   scroll--;
   if (scroll == -87)
   {
   GPIO5=1;
   scroll=32;
   }
   matrix->print(WiFi.localIP());
   matrix->show();
}
