#pragma region Fire
/* Display size; can be smaller than matrix size, and if so, you can move the origin.
 * This allows you to have a small fire display on a large matrix sharing the display
 * with other stuff. See README at Github. */
const uint16_t rows = kMatrixHeight;
const uint16_t cols = kMatrixWidth;
const uint16_t xorg = 0;
const uint16_t yorg = 0;

/* Flare constants */
const uint8_t flarerows = 5;    /* number of rows (from bottom) allowed to flare */
const uint8_t maxflare = 1;     /* max number of simultaneous flares */
const uint8_t flarechance = 5; /* chance (%) of a new flare (if there's room) */
const uint8_t flaredecay = 14;  /* decay rate of flare radiation; 14 is good */

/* This is the map of colors from coolest (black) to hottest. Want blue flames? Go for it! */
const uint32_t colors[] = {
  0x000000,
  0x100000,
  0x200000,
  0x300000,
  0x400000,
  0x500000,
  0x600000,
  0x700000,
  0x800000,
  0x900000,
  0xA00000,
  0xB00000,
  0xC02000,
  0xC04000,
  0xC06000,
  0xC08000,
  0x807080
};
const uint8_t NCOLORS = (sizeof(colors)/sizeof(colors[0]));
uint8_t pix[rows][cols];
uint8_t nflare = 0;
uint32_t flare[maxflare];

uint32_t isqrt(uint32_t n) {
  if ( n < 2 ) return n;
  uint32_t smallCandidate = isqrt(n >> 2) << 1;
  uint32_t largeCandidate = smallCandidate + 1;
  return (largeCandidate*largeCandidate > n) ? smallCandidate : largeCandidate;
}
unsigned long t = 0; /* keep time */

 #pragma endregion Fire
