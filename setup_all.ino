void setup_all()
{

#pragma region Fastled_setup
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, LED_COUNT).setCorrection(TypicalSMD5050);
  //FastLED.setMaxPowerInVoltsAndMilliamps(LED_VOLTS, MAX_MILLIAMPS);
  FastLED.setBrightness(GPIO4);
  FastLED.clear();
  #pragma endregion Fastled_setup

  #pragma region Misc_setup
//   sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQ));
  sampling_period_us = round(1000000 * (1.0 / samplingFrequency));
  // start up the I2S peripheral
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &i2s_mic_pins);

  pinMode(3, OUTPUT);
    digitalWrite(3, LOW);
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);
    pinMode(33, OUTPUT);
    digitalWrite(33, LOW);

  Webserver();
  #pragma endregion Misc_setup

 #pragma region Fire_setup
   for ( uint16_t i=0; i<rows; ++i ) {
    for ( uint16_t j=0; j<cols; ++j ) {
      if ( i == 0 ) pix[i][j] = NCOLORS - 1;
      else pix[i][j] = 0;
    }
}
 #pragma endregion Fire_setup



#pragma region gif_setup
// decoder.setScreenClearCallback(screenClearCallback);
// decoder.setUpdateScreenCallback(updateScreenCallback);
// decoder.setDrawPixelCallback(drawPixelCallback);
// decoder.setFileSeekCallback(fileSeekCallback);
// decoder.setFilePositionCallback(filePositionCallback);
// decoder.setFileReadCallback(fileReadCallback);
// decoder.setFileReadBlockCallback(fileReadBlockCallback);

// Serial.println(F("Inizializing FS..."));
// if (FFat.begin())
//    {
//    Serial.println(F("done."));
//    }
// else
//    {
//    Serial.println(F("fail."));
//    }
// Serial.print(pathname);

// if (file) file.close();
// file = FFat.open("/no10.gif");
// unsigned int totalBytes = FFat.totalBytes();

// Serial.print(totalBytes);

// //File entry =  dir.openNextFile();
// if (!file) 
//    {
//    Serial.println(": Error opening GIF file");
//    while (1) { delay(1000); }; // while 1 loop only triggers watchdog on ESP chips
//    }
// Serial.println(": Opened GIF file, start decoding");
// decoder.startDecoding();

pinMode(Joy1_button_A_inPin, INPUT_PULLDOWN);
pinMode(Joy1_button_B_inPin, INPUT_PULLDOWN);

#pragma endregion gif_setup

  #pragma region Taskcreation
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  //delay(500); 

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
  //  delay(500); 
  #pragma endregion Taskcreation
   

}