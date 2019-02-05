/* ********** FRAME BUFFER Access ********** */

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include <sys/mman.h>

/* Your screen size. Change it so it would not be segmentation fault */
#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 762

typedef struct{
    unsigned char r,g,b,a;
} color;

void init ();
// Opening the framebuffer file and turn of the cursor
void set_background(color* c);
// Set the full screen color into given color c
void close_buffer();
// Turn on the cursor and shut the program
void draw_dot(unsigned short x, unsigned short y, color* c);
// drawing a dot on positin (x,y) with given color c
color getPixelColor(unsigned short x, unsigned short y);
// return color of a pixel

#endif
