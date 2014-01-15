#include "main.h"
#include "memory.h" 

void mandelbrot_3DS(int zoom,int scalex,int scaley,int sx,int sy);
void mandelbrot_3DS2(int zoom,int scalex,int scaley,int sx,int sy);
int fxpt_Mult(int a, int b);

int offx;
int offy;
int rm,gm,bm;

int main()
{
  
	char* c="Hacked By Aliak11, A.K.A. RBWDash!";
    
	int i;
	
	int scx;
	int scy;
	int sx;
	int sy;
	
	while(1){
	
	scx=0x020;
	scy=0x022;
	sx=0x040;
    sy=0x044;
	offx=-0x2800;
    offy=-0x1000;
	
   
	
	for(i=0;i<4;i++){
	    if(i==0){rm=0;gm=2;bm=1;} if(i==1){rm=2;gm=0;bm=0;}if(i==2){rm=2;gm=2;bm=1;}if(i==3){rm=0;gm=1;bm=1;}
	    
	    paint_word(c,5,220, 255, 0, 0, TOP_LEFT_FRAME1);
        paint_word(c,5,220, 255, 0, 0, TOP_LEFT_FRAME2); 
		
		mandelbrot_3DS(i,scx,scy,sx,sy);
		
		paint_word(c,5,220, 255, 0, 0, SUB_FRAME1);
        paint_word(c,5,220, 255, 0, 0, SUB_FRAME2); 
		
		
		mandelbrot_3DS2(i,scx,scy,sx,sy);
	    scx=fxpt_Mult(0x800,scx);
		scy=fxpt_Mult(0x800,scy);	
	    sx=fxpt_Mult(0x800,sx);
		sy=fxpt_Mult(0x800,sy);	
	}
 }
  
	  
  return 0;
}
void mandelbrot_3DS(int zoom,int scalex,int scaley,int sx,int sy)
{
    const int MAX=32;
    int zc=(1<<zoom);
    int zp=(1<<(zoom-1));

    //floatp scalex=(3.0/400.0/zc);  1f
	//int scalex=0x01F;
    
	//floatp scaley=(2.0/240.0/zc); 22
	//int scaley=0x022;
	

    //floatp sx=(3.0/400.0/zp);
	//int sx=0x030;
	
    //floatp sy=(2.0/240.0/zp);
	//int sy=0x02A;

    if(zoom>0)
    {
        offx=offx+fxpt_Mult(0x6A000,sx);
        offy=offy+fxpt_Mult(0x34000,sy);

    }
   
	
    //zoom++;
		
    int x0 = 0;
    int y0 = 0;
    int x = 0;
    int y = 0;
    int temp=0;
    int X=0;
    int Y=0;
    char i = 0;
	char px=0;
	int xx,yy;
	char r,g,b;
	r=g=b=1;
	
/*  //old NDS stuff, we're big time now :)
	u16 *p=VRAM_A;   
	for(X=0;X<256*192;X++)*(p+X)=X;
	
	int t=time(NULL);
	
	if(time(NULL)==35){
		while(time(NULL)==t){
		swiWaitForVBlank();
		} 
	}
	t=time(NULL);
*/
   
    for(Y=0; Y<241; Y++)
    {
	  
        for(X=0; X<400; X++) 
        {
		   

            x=y=i=xx=yy=0;

            x0=( fxpt_Mult(scalex,X<<12) )+offx;
            y0=( fxpt_Mult(scaley,Y<<12) )+offy;
            
            while( xx + yy < 0x4000  &&  i < MAX )
            {
                temp = ( xx - yy ) + x0;
                y = fxpt_Mult( 0x2000 , fxpt_Mult(x,y)) + y0;

                x = temp;

                i++;
				xx=fxpt_Mult(x,x);
				yy=fxpt_Mult(y,y);
            }
			 
			 r=i<<rm;
             g=i<<bm;
			 b=i<<gm;
			 //i=i<<2;
			 //*(p+256*Y+X)= X/8 | i<<5 | (Y/6)<<10;
			 paint_pixel(X,Y , r, g, b, TOP_LEFT_FRAME1); 
			 paint_pixel(X,Y , r, g, b, TOP_LEFT_FRAME2); 
			 
			 paint_pixel(X,Y , r, g, b, TOP_RIGHT_FRAME1); 
			 
			 //paint_pixel2(X,Y , r, g, b, SUB_FRAME1); 
			 //paint_pixel2(X,Y , r, g, b, SUB_FRAME2);
			 
        }
        
    }
/*
    t=time(NULL)-t;
	if(t)iprintf("Completion Time:\n%d Secs.\n",t);
	else
	iprintf("Time not possible on emulator.\n");
	
	swiWaitForVBlank();
*/
}

void mandelbrot_3DS2(int zoom,int scalex,int scaley,int sx,int sy)
{
    const int MAX=32;
    int zc=(1<<zoom);
    int zp=(1<<(zoom-1));

    //floatp scalex=(3.0/400.0/zc);  1f
	//int scalex=0x01F;
    
	//floatp scaley=(2.0/240.0/zc); 22
	//int scaley=0x022;
	

    //floatp sx=(3.0/400.0/zp);
	//int sx=0x030;
	
    //floatp sy=(2.0/240.0/zp);
	//int sy=0x02A;

    if(zoom>0)
    {
        offx=offx+fxpt_Mult(0x6A000,sx);
        offy=offy+fxpt_Mult(0x34000,sy);

    }
   
	
    //zoom++;
		
    int x0 = 0;
    int y0 = 0;
    int x = 0;
    int y = 0;
    int temp=0;
    int X=0;
    int Y=0;
    char i = 0;
	char px=0;
	int xx,yy;
	char r,g,b;
	r=g=b=0;
	
/*  //old NDS stuff, we're big time now :)
	u16 *p=VRAM_A;   
	for(X=0;X<256*192;X++)*(p+X)=X;
	
	int t=time(NULL);
	
	if(time(NULL)==35){
		while(time(NULL)==t){
		swiWaitForVBlank();
		} 
	}
	t=time(NULL);
*/
   
    for(Y=0; Y<241; Y++)
    {
	  
        for(X=0; X<320; X++) 
        {
		   

            x=y=i=xx=yy=0;

            x0=( fxpt_Mult(scalex,X<<12) )+offx;
            y0=( fxpt_Mult(scaley,Y<<12) )+offy;
            
            while( xx + yy < 0x4000  &&  i < MAX )
            {
                temp = ( xx - yy ) + x0;
                y = fxpt_Mult( 0x2000 , fxpt_Mult(x,y)) + y0;

                x = temp;

                i++;
				xx=fxpt_Mult(x,x);
				yy=fxpt_Mult(y,y);
            }
			 
			 r=i<<rm;
             g=i<<bm;
			 b=i<<gm;
			 //i=i<<2;
			 //*(p+256*Y+X)= X/8 | i<<5 | (Y/6)<<10; 
			 
			 paint_pixel2(X,Y , r, g, b, SUB_FRAME1); 
			 paint_pixel2(X,Y , r, g, b, SUB_FRAME2);
			 
        }
        
    }
/*
    t=time(NULL)-t;
	if(t)iprintf("Completion Time:\n%d Secs.\n",t);
	else
	iprintf("Time not possible on emulator.\n");
	
	swiWaitForVBlank();
*/
}
/*
int float2fix(floatp a){

int left=a;
float dec=a-left;
int right=(dec*4096);

return left<<12 | right;
}
*/

int fxpt_Mult(int a, int b)
{
	return (a*b) >> 12;
}

