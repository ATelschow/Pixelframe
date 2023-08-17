#pragma region gif2
void screenClearCallback(void) { matrix->clear(); }
void updateScreenCallback(void) { matrix->show(); }

void drawPixelCallback(int16_t x, int16_t y, uint8_t red, uint8_t green, uint8_t blue) {
  //CRGB color = CRGB(matrix->gamma[red], matrix->gamma[green], matrix->gamma[blue]);
  CRGB color = CRGB(red, green, blue);
  // This works but does not handle out of bounds pixels well (it writes to the last pixel)
  // matrixleds[XY(x+OFFSETX,y+OFFSETY)] = color;
  // drawPixel ensures we don't write out of bounds
  matrix->drawPixel(x+OFFSETX, y+OFFSETY, color);
}
#pragma endregion gif2