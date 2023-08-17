void square() {
//FastLED.clear();
int ix,iy,iz,il=0;
int ixb= 0;
int ixb_=31;
int iyb=0;
int iyb_=31;
int cyclecounter=1;
int color=0;
int color1=0;
int ixc= 0;
int ixc_=31;
int iyc=0;
int iyc_=31;
int ixd= 0;
int ixd_=31;
int iyd=0;
int iyd_=31;
color1=random(10);

ik++;
if (ik>10) (ik=0);

for (il=1; il<34; il++){
    if (ik <6) (FastLED.clear());
    //int colorIndex = constrain((il + 1) * (255 / il), 0, 255);
     int colorIndex = ((255 / il), 0, 255);
    //FastLED.show();
    
    color=color1*il;
    int color2=color1*(il-1);
    int color3=color1*(il-2);

    for (iy=0; iy<32; iy++){
        
        for (ix=0; ix<32; ix++) {    
          

            if ( ((ix == ixb) && (iy >= iyb) && (iy <= iyb_)) 
                || ((ix == ixb_) && (iy <= iyb_) && (iy >= iyb)) 
                || ((iy == iyb) && (ix >= ixb) && (ix <= ixb_))  
                || ((iy == iyb_)  && (ix >= ixb) && (ix <= ixb_)))   
                (matrix->drawPixel(ix, iy, CHSV((color), 255, 255)));
              //(matrix->drawPixel(ix, iy, ColorFromPalette(heatPal, colorIndex))); 
          
            if ( ((ix == ixc) && (iy >= iyc) && (iy <= iyc_)) 
                || ((ix == ixc_) && (iy <= iyc_) && (iy >= iyc)) 
                || ((iy == iyc) && (ix >= ixc) && (ix <= ixc_))  
                || ((iy == iyc_)  && (ix >= ixc) && (ix <= ixc_)))   
                (matrix->drawPixel(ix, iy, CHSV((color2), 255, 200)));
                //(matrix->drawPixel(ix, iy, ColorFromPalette(heatPal, colorIndex))); 

            if ( ((ix == ixd) && (iy >= iyd) && (iy <= iyd_)) 
                || ((ix == ixd_) && (iy <= iyd_) && (iy >= iyd)) 
                || ((iy == iyd) && (ix >= ixd) && (ix <= ixd_))  
                || ((iy == iyd_)  && (ix >= ixd) && (ix <= ixd_)))   
                (matrix->drawPixel(ix, iy, CHSV((color3), 255, 150)));
                //(matrix->drawPixel(ix, iy, ColorFromPalette(heatPal, colorIndex))); 


        } 
        
               
        
    }
    FastLED.show();
    if (il < 17) {
        ixb++;
        ixb_ = 31-ixb;
        iyb++;
        iyb_ = 31-iyb;
        }
    else {
        ixb--;
        ixb_ = 31-ixb;
        iyb--;
        iyb_ = 31-iyb;

        }
    ixc=ixb-1;
    ixc_=ixb_+1;
    iyc=iyb-1;
    iyc_=iyb_+1;

    ixd=ixc-1;
    ixd_=ixc_+1;
    iyd=iyc-1;
    iyd_=iyc_+1;

    //delay(300);
    
}

}