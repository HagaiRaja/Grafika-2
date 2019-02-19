#include "frame_buffer.h"

struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
char *fbp = 0 ; //pointer framebuffer
int fbfd = 0; //pointer framebuffer driver

void init ()
// Opening the framebuffer file and turn of the cursor
{
	// opening frame buffer file
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: driver framebuffer tidak dapat dibuka");
        exit(1);
    }

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    // Mapping framebuffer to memory
    int screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if(atoi(fbp) == -1){
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    // Turn off the cursor
    system("setterm -cursor off");
}

void set_background(color* c)
// Set the full screen color into given color c
{
	for (unsigned short i = 0; i < SCREEN_HEIGHT; ++i)
    {
        for (unsigned short j = 0; j < SCREEN_WIDTH; ++j)
        {
            draw_dot(j, i, c);
        }
    }
}

void close_buffer()
// Turn on the cursor and shut the program
{
	int temp;
    scanf("%d", &temp);
    // Turn the cursor back on
    system("setterm -cursor on");
}

void close_buffer_without_read() {
    system("setterm -cursor on");
}

void draw_dot(unsigned short x, unsigned short y, color* c)
// drawing a dot on positin (x,y) with given color c
{
	if((x<1) || (x>SCREEN_WIDTH) || (y<1) || (y>SCREEN_HEIGHT)){
		return ;
	}


    long int position = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
       (y + vinfo.yoffset) * finfo.line_length;
    if(vinfo.bits_per_pixel == 32){
        *(fbp + position) = c->b;
        *(fbp + position + 1) = c->g;
        *(fbp + position + 2) = c->r;
        *(fbp + position + 3) = c->a;
    }
    else
    {//assume 16 bit color
        unsigned short b = c->b;
        unsigned short g = c->g;
        unsigned short r = c->r;
        unsigned short int t = r<<11 | g << 5 | b;
        *((unsigned short int*)(fbp + position)) = t;
    }
}

color getPixelColor(unsigned short x, unsigned short y){
  color c;
  long int position = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) + (y + vinfo.yoffset) * finfo.line_length;
  c.b = *(fbp + position);
  c.g = *(fbp + position + 1);
  c.r = *(fbp + position + 2);
  c.a = *(fbp + position + 3);
  return c;
}