bool init_done = 0;
uint32_t tft_spi_speed;
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))
 
#pragma region LED_&_FFT

#if defined(DEVICETYPE1) || defined(DEVICETYPE2)
   #define LED_COUNT 1024
#else if defined(DEVICETYPE3)
   #define LED_COUNT 256
#endif

int AMPLITUDE = 2000;         // Depending on your audio source level, you may need to alter this value. Can be used as a 'sensitivity' control.
const uint8_t kMatrixWidth = (sqrt(LED_COUNT));        // Matrix width
const uint8_t kMatrixHeight = (sqrt(LED_COUNT));

#define SAMPLES         512     // Must be a power of 2
#define SAMPLING_FREQ   40000   // Hz, must be 40000 or less due to ADC conversion time. Determines maximum frequency that can be analysed by the FFT Fmax=sampleF/2.
#define AUDIO_IN_PIN    35      // Signal in on this pin
#define LED_PIN         16      // LED strip data
#define COLOR_ORDER     GRB     // If colours look wrong, play with this
#define CHIPSET         WS2812B // LED strip type
#define NOISE           1       // Used as a crude noise filter, values below this are ignored (init:500)
#define FPS             20      // Fire
#define RED             0xF800  // Fire                     
#define BAR_WIDTH       (kMatrixWidth  / (NUM_BANDS - 1))  // If width >= 8 light 1 LED width per bar, >= 16 light 2 LEDs width bar etc
#define TOP             (kMatrixHeight - 0)                // Don't allow the bars to go offscreen
#define NUM_BANDS       (kMatrixWidth)                     // To change this, you will need to change the bunch of if statements describing the mapping from bins to bands

#pragma endregion LED_&_FFT


#pragma region I2_Microphone
// most microphones will probably default to left channel but you may need to tie the L/R pin low
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT
// either wire your microphone to the same pins or change these to match your wiring
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_2
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_15
#define I2S_MIC_SERIAL_DATA GPIO_NUM_13
#pragma endregion I2_Microphone


#pragma region Variablen
int adapt[32];
int adaptsum = 0;
int adaptavg[10];
int adaptcnt =0;
int adaptzlr=0;

int AdaptSquareValue = 125;
int AdaptSquareAvg = 0;
int AdaptSquareSum = 0;
int AdaptSquareCounter = 0;
#define AdaptSquareCycles 50

//text
int textablauf = 0;
uint16_t textzlr = 0;

//Propeller 
int propx = 0;
int propy = 0;
int propix = 0;
int propiy = 0;

//circle
int circle_r[]={0,0,0,0,0,0,0,0};
int c1[]={0,0,0,0,0,0,0,0};
int c2[]={0,0,0,0,0,0,0,0};
int index1 = 0;

//scroll
int scroll = 0;
int scrollzlr = 0;

//gif
int gifinit=0;
int gifzlr=0;

byte a,b,c,d,e,f,g,h,k,m,n,o,p,r,s,u,v,v1,w,x,y,z,i1,r1,g1,b1=0;
int i,j=0;
int ah[16];
int av[16];
int ab[16];
int ar[16];
int ag[16];
long cycle,altmillis=0;
long cycle1,altmillis1=0;
int GPIO1=0;
int GPIO2,GPIO3=0;
int GPIO4 = 150;
int GPIO5 = 1;
int GPIO6 = 2000;
int GPIO7 = 0;
int GPIO8 = 0;
int GPIO6old = 2000;
int ik=0;
int color[16]={125,5,7,15,25,55,85,110,125,150,170,190,210,220,235,255};
int Richtung=1;
int startloop=1;

// Joystick
const int JoyPin = 34;
volatile int Joy_in_Value = 0;



#pragma endregion Variablen