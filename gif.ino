void gif() 
{
if (gifinit==0)
{
decoder.setScreenClearCallback(screenClearCallback);
decoder.setUpdateScreenCallback(updateScreenCallback);
decoder.setDrawPixelCallback(drawPixelCallback);
decoder.setFileSeekCallback(fileSeekCallback);
decoder.setFilePositionCallback(filePositionCallback);
decoder.setFileReadCallback(fileReadCallback);
decoder.setFileReadBlockCallback(fileReadBlockCallback);

Serial.println(F("Inizializing FS..."));
if (FFat.begin())
   {
   Serial.println(F("done."));
   }
else
   {
   Serial.println(F("fail."));
   }
Serial.print(pathname);

if (file) file.close();
file = FFat.open("/no10.gif");
unsigned int totalBytes = FFat.totalBytes();

Serial.print(totalBytes);

//File entry =  dir.openNextFile();
if (!file) 
   {
   Serial.println(": Error opening GIF file");
   while (1) { delay(1000); }; // while 1 loop only triggers watchdog on ESP chips
   }
Serial.println(": Opened GIF file, start decoding");
decoder.startDecoding();
gifinit=1;
}

EVERY_N_SECONDS(5) 
{
decoder.setScreenClearCallback(screenClearCallback);
decoder.setUpdateScreenCallback(updateScreenCallback);
decoder.setDrawPixelCallback(drawPixelCallback);
decoder.setFileSeekCallback(fileSeekCallback);
decoder.setFilePositionCallback(filePositionCallback);
decoder.setFileReadCallback(fileReadCallback);
decoder.setFileReadBlockCallback(fileReadBlockCallback);

Serial.println(F("Inizializing FS..."));
if (FFat.begin())
   {
   Serial.println(F("done."));
   }
else
   {
   Serial.println(F("fail."));
   }
// Serial.print(pathname);


   file = FFat.open("/");
   File  entry =  file.openNextFile();
   int i=0;
   for ( i=0; i<gifzlr; i++)
   {
   entry =  file.openNextFile();
   }
   gifzlr++;
   
   //File dir = FFat.open("/");
   Serial.println(entry.name());
String stringOne = "/";
   Serial.println(stringOne);
String stringThree = stringOne + entry.name();
   Serial.println(stringThree);

const char *meinedatei =stringThree.c_str();
   Serial.println(c);

if (file) file.close();
// pathname1 = stringThree;
// file = FFat.open(c);
//const char *meinedatei = "/no3.gif";
 file = FFat.open(meinedatei);
//file = FFat.open(openNextFile())

// if (file) file.close();
// file = FFat.open("/no11.gif");
unsigned int totalBytes = FFat.totalBytes();

Serial.println(totalBytes);
if (!file)
   {
   gifzlr=0;
   decoder.setScreenClearCallback(screenClearCallback);
decoder.setUpdateScreenCallback(updateScreenCallback);
decoder.setDrawPixelCallback(drawPixelCallback);
decoder.setFileSeekCallback(fileSeekCallback);
decoder.setFilePositionCallback(filePositionCallback);
decoder.setFileReadCallback(fileReadCallback);
decoder.setFileReadBlockCallback(fileReadBlockCallback);

Serial.println(F("Inizializing FS..."));
if (FFat.begin())
   {
   Serial.println(F("done."));
   }
else
   {
   Serial.println(F("fail."));
   }
// Serial.print(pathname);


   file = FFat.open("/");
   File  entry =  file.openNextFile();
   int i=0;
   for ( i=0; i<gifzlr; i++)
   {
   entry =  file.openNextFile();
   }
   gifzlr++;
   
   //File dir = FFat.open("/");
   Serial.println(entry.name());
String stringOne = "/";
   Serial.println(stringOne);
String stringThree = stringOne + entry.name();
   Serial.println(stringThree);

const char *meinedatei =stringThree.c_str();
   Serial.println(c);

if (file) file.close();
// pathname1 = stringThree;
// file = FFat.open(c);
//const char *meinedatei = "/no3.gif";
 file = FFat.open(meinedatei);
//file = FFat.open(openNextFile())

// if (file) file.close();
// file = FFat.open("/no11.gif");
unsigned int totalBytes = FFat.totalBytes();

   }



//File entry =  dir.openNextFile();
if (!file) 
   {
   Serial.println(": Error opening GIF file");
   while (1) { delay(1000); }; // while 1 loop only triggers watchdog on ESP chips
   }
    Serial.print(file.name());
Serial.println(": Opened GIF file, start decoding");
decoder.startDecoding();
//gifinit=1;
}


// EVERY_N_SECONDS(5) 
//    {
//    decoder.setScreenClearCallback(screenClearCallback);
// decoder.setUpdateScreenCallback(updateScreenCallback);
// decoder.setDrawPixelCallback(drawPixelCallback);
// decoder.setFileSeekCallback(fileSeekCallback);
// decoder.setFilePositionCallback(filePositionCallback);
// decoder.setFileReadCallback(fileReadCallback);
// decoder.setFileReadBlockCallback(fileReadBlockCallback);
//    // if (gifinit==0)
//    // {
//    //    File file = FFat.open("/");
//    //    gifinit=1;
//    // }
// //if (file) file.close();
//    File file = FFat.open("/");
//   File entry =  file.openNextFile();
//    entry =  file.openNextFile();
//       entry =  file.openNextFile();
//             entry =  file.openNextFile();
//    //File dir = FFat.open("/");
//    Serial.println(entry.name());
// String stringOne = "/";
//    Serial.println(stringOne);
// String stringThree = stringOne + entry.name();
//    Serial.println(stringThree);
// if (file) file.close();
// // file = FFat.open(stringThree);
// file = FFat.open("/no11.gif");
// // file.openNextFile()


//    //if (file) file.close();
//    //file = FFat.open(pathname);
//    //unsigned int totalBytes = FFat.totalBytes();
//    //Serial.print(totalBytes);

//    if (!file) 
//       {
//       Serial.println(": Error opening GIF file");
//       while (1) { delay(1000); }; // while 1 loop only triggers watchdog on ESP chips
//       }
//       Serial.print(file.name());
//    Serial.println(": Opened GIF file, start decoding");
//    decoder.startDecoding();
//    }

decoder.decodeFrame();







}
