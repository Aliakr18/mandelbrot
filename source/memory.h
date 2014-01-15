#ifndef MEMORY_H
#define MEMORY_H

#define STACK_SIZE 0x00004000
#define FCRAM_BASE 0x20000000
#define TOP_ASPECT_X 0x5
#define TOP_ASPECT_Y 0x3
#define TOP_HEIGHT 240
#define TOP_WIDTH 400
#define TOP_LEFT_FRAME1 0x20184E60
#define TOP_LEFT_FRAME2 0x201CB370
#define TOP_RIGHT_FRAME1 0x20282159
#define TOP_RIGHT_FRAME2 
#define SUB_FRAME1 539039967
#define SUB_FRAME2 539039968

void write_byte(int address, char byte);
void write_byte2(int address2, char byte2);
void write_word(int address, int word);
void write_color(int address, char r, char g, char b);
void write_color2(int address2, char r, char g, char b);
int read_word(int address);
void* find_byte_sequence(char* sequence, int num, int base_address);
void paint_pixel(int x, int y, char r, char g, char b, int screen);
void paint_pixel2(int x, int y, char r, char g, char b, int screen);
void paint_letter(char letter,int x,int y, char r, char g, char b, int screen);
void paint_word(char* word, int x,int y, char r, char g, char b, int screen);
int strlen(char* string); 
#endif

