#include "memory.h"
#include "letters.h"


void write_word(int address, int word){
  int *a = (int*) address;
  *a = word;
}

void write_color(int address2, char r, char g, char b){
  write_byte(address2, b);
  write_byte(address2+1, g);
  write_byte(address2+2, r);
}

void write_color2(int address, char r, char g, char b){
  write_byte2(address, b);
  write_byte2(address+1, g);
  write_byte2(address+2, r);
}

void write_byte(int address, char byte){
  char *a = (char*) address;
  *a = byte;
}

void write_byte2(int address2, char byte2){
  char *b = (char*) address2;
  *b = byte2;
}

int read_word(int address){
  int *a = (int*) address;
  return *a;
}

void* find_byte_sequence(char* sequence, int num, int base_address){
  char* c = (char*)base_address;  
  while (1){
    if (*c == sequence[0]){
      int i;
      for (i = 1; i < num; i++){
        if(*(c+i) == sequence[i]){

        } else {
          break;
        }
        return (void*)c;
      }
    }
    c++;
  }
}

void paint_pixel(int x, int y, char r, char g, char b, int screen){
  int coord = 720*x+720-(y*3);
  write_color(coord+screen,r,g,b);
}

void paint_pixel2(int x, int y, char r, char g, char b, int screen){
  int coord = 720*x+720-(y*3);
  write_color2(coord+screen,r,g,b);
}

void paint_letter(char letter,int x,int y, char r, char g, char b, int screen){

  int i;
  int k;
  int c;
  unsigned char mask;
  unsigned char* _letter;
  unsigned char l; 
  c=letter*8;

  for (i = 0; i < 8; i++){
    mask = 0b10000000;
    l = font[i+c];
    for (k = 0; k < 8; k++){
      if ((mask >> k) & l){
        paint_pixel(k+x,i+y,r,g,b,screen);
      }     
    }
  }
}

int strlen(char* string){
  int i;
  for (i = 0; ; i++){
      if (string[i] == 0x00){
        return i;
      }
  }
}

void paint_word(char* word, int x,int y, char r, char g, char b, int screen){
    int tmp_x =x;
    int i;
    int line = 0;

    for (i = 0; i <strlen(word); i++){
     
      if (tmp_x+8 > TOP_WIDTH) {
        line++;
        tmp_x = x;
      }
      paint_letter(word[i],tmp_x,y+(line*8),r,g,b, screen);

      tmp_x = tmp_x+8;
    }

}