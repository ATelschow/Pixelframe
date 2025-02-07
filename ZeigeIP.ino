void zeigeIP()
{
#if defined(DEVICETYPE1) || defined(DEVICETYPE2)
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
#else if defined(DEVICETYPE3)
   matrix->fillScreen(0);
   matrix->setTextSize(1);
   matrix->setTextWrap(false);
   matrix->setCursor(scroll, 4);
   scroll--;
   if (scroll == -87)
   {
   GPIO5=1;
   scroll=32;
   }
   matrix->print(WiFi.localIP());
   matrix->show();
   delay(100);
#endif
}
