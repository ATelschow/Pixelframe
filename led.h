#pragma region FastLED_stuff
CRGB leds[LED_COUNT];
DEFINE_GRADIENT_PALETTE( purple_gp ) {
  0,   0, 212, 255,   //blue
255, 179,   0, 255 }; //purple
DEFINE_GRADIENT_PALETTE( outrun_gp ) {
  0, 141,   0, 100,   //purple
127, 255, 192,   0,   //yellow
255,   0,   5, 255 };  //blue
DEFINE_GRADIENT_PALETTE( greenblue_gp ) {
  0,   0, 255,  60,   //green
 64,   0, 236, 255,   //cyan
128,   0,   5, 255,   //blue
192,   0, 236, 255,   //cyan
255,   0, 255,  60 }; //green
DEFINE_GRADIENT_PALETTE( redyellow_gp ) {
  0,   250, 250,  50,   //white
 64,   255, 218,    0,   //yellow
127,   231,   0,    0,   //red
128,   231,   0,    0,   //red
192,   255, 218,    0,   //yellow
255,   250, 250,  50 }; //white
CRGBPalette16 purplePal = purple_gp;
CRGBPalette16 outrunPal = outrun_gp;
CRGBPalette16 greenbluePal = greenblue_gp;
CRGBPalette16 heatPal = redyellow_gp;
uint8_t colorTimer = 0;

const uint16_t textcolors[] = {
0x0000,
0x001F,
0xF800,
0x07E0,
0x07FF,
0xF81F,
0xFFE0,
0xFFFF
};



#pragma endregion FastLED_stuff

#pragma region Neomatrix
// FastLED_NeoMaxtrix - see https://github.com/marcmerlin/FastLED_NeoMatrix for Tiled Matrixes, Zig-Zag and so forth


// Choose this for 1024 1mx1m:
#if defined(DEVICETYPE1)
FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(leds, kMatrixWidth, kMatrixHeight,
  NEO_MATRIX_BOTTOM        + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS       + NEO_MATRIX_ZIGZAG +
  NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ROWS);
#endif

// Choose this for 1024:
#if defined(DEVICETYPE2)
FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(leds, 16, 16, 2, 2,
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS       + NEO_MATRIX_ZIGZAG +
  NEO_TILE_TOP   + NEO_TILE_LEFT   + NEO_TILE_COLUMNS    + NEO_TILE_ZIGZAG);
#endif

// Choose this for 256:
#if defined(DEVICETYPE3)
FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(leds, kMatrixWidth, kMatrixHeight,
  NEO_MATRIX_TOP        + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS       + NEO_MATRIX_ZIGZAG +
  NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ROWS);
#endif


// FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(leds, kMatrixWidth, kMatrixHeight,
//   NEO_MATRIX_BOTTOM        + NEO_MATRIX_LEFT +
//   NEO_MATRIX_ROWS      + NEO_MATRIX_ZIGZAG +
//   NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ROWS);

#pragma endregion Neomatrix