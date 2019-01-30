#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include <sys/mman.h>

#define FILENAME "image.txt"
#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 762

typedef struct{
    int r,g,b,a;
} color;

struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
char *fbp = 0 ; //pointer framebuffer
int fbfd = 0; //pointer framebuffer driver
color black = {0,0,0,0};
color white = {255,255,255,255};

unsigned char buffer_r[SCREEN_WIDTH][SCREEN_HEIGHT];
unsigned char buffer_g[SCREEN_WIDTH][SCREEN_HEIGHT];
unsigned char buffer_b[SCREEN_WIDTH][SCREEN_HEIGHT];

void draw_dot(int x, int y, color* c);
void draw_dots(int x, int y, color* c);
void draw_line(int x1, int y1, int x2, int y2, color* c);
void set_background(color* c);
void draw_rectangle(int center_x, int center_y, int width, int height, color* c);
void draw_airplane(int center_x, int center_y,color* c);
void draw_canon(int center_x, int center_y, color* c);
void draw_bullet(int center_x, int center_y, color* c);

int main()
{
//======================================================================================
// PREPARING SCREEN AND FRAME BUFFER

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
    if((int)fbp == -1){
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    // Turn off the cursor
    system("setterm -cursor off");

//======================================================================================
// LOAD IMAGE FROM FILENAME

    FILE* file = fopen (FILENAME, "r");
    int temp_r = 0, temp_g = 0, temp_b = 0;
    for (int i = 0; i < SCREEN_HEIGHT; ++i)
    {
        for (int j = 0; j < SCREEN_WIDTH; ++j)
        {
            fscanf (file, "%d %d %d", &temp_r, &temp_g, &temp_b);
            buffer_r[j][i] = temp_r;
            buffer_g[j][i] = temp_g;
            buffer_b[j][i] = temp_b;
        }
    }
    
    fclose (file); 

//=======================================================================================
// DISPLAYING THE IMAGE TO SCREEN
    int screen_speed = 2;
    int start = 0;

    // while(1){
    // // rendering the image
    //     set_background(&black);
    //     draw_rectangle(500, 200, 100, 100, &white);
	   //  usleep(10000);
    // }

    set_background(&white);
    draw_line(500, 500, 800, 300, &black);
    // draw_rectangle(500, 200, 300, 300, &black); 
    int temp;
    scanf("%d", &temp);

    // Turn the cursor back on
    system("setterm -cursor on");
    return 0;

}

//######################################################################################
void draw_dot(int x, int y, color* c)
// Drawing a dot at (x,y) point in the screen with c as the color
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
        int b = c->b;
        int g = c->g;
        int r = c->r;
        unsigned short int t = r<<11 | g << 5 | b;
        *((unsigned short int*)(fbp + position)) = t;
    }
}

void draw_dots(int x, int y, color* c)
// Drawing a dot at (x,y) point in the screen with c as the color
{
    int range = 1;
    for (int i = -range; i < range + 1; ++i)
    {
        for (int j = -range; j < range + 1; ++j)
        {
            draw_dot(x+i, y+j, c);
        }
    }
}

void draw_line(int x1, int y1, int x2, int y2, color* c)
// Drawing a line in screen from (x1,y1) to (x2,y2) with color c using 
// Bresenham Algorithm
{
    int m_new = 2 * (y2 - y1); 
    int slope_error_new = m_new - (x2 - x1);

    for (int x = x1, y = y1; x <= x2; x++) 
    { 
        // Drawing dot in the line
        draw_dots(x, y, c); 

        // Add slope to increment angle formed 
        slope_error_new += m_new; 

        // Slope error reached limit, time to 
        // increment y and update slope error. 
        if (slope_error_new >= 0) 
        { 
            y++; 
            slope_error_new  -= 2 * (x2 - x1); 
        } 
    } 
}

void draw_rectangle(int center_x, int center_y, int width, int height, color* c) 
{
    int topLeft_x = center_x - (width/2), topLeft_y = center_y + (height/2);
    int bottomLeft_x = center_x - (width/2), bottomLeft_y = center_y - (height/2);
    int topRight_x = center_x + (width/2), topRight_y = center_y + (height/2);
    int bottomRight_x = center_x + (width/2), bottomRight_y = center_y - (height/2);

    printf("%d %d %d %d\n", bottomRight_x, bottomRight_y, bottomLeft_x, bottomLeft_y);
    // draw_line(topLeft_x, topLeft_y, topRight_x, topRight_y, c);
    // draw_line(bottomRight_x, bottomRight_y, topRight_x, topRight_y, c);
    draw_line(bottomRight_x, bottomRight_y, bottomLeft_x, bottomLeft_y, c);
    // draw_line(topLeft_x, topLeft_y, bottomLeft_x, bottomLeft_y, c);
}

void draw_airplane(int center_x, int center_y,color* c) 
{

}

void draw_canon(int center_x, int center_y, color* c) 
{

}

void draw_bullet(int center_x, int center_y, color* c) 
{

}

void set_background(color* c) {
    for (int i = 0; i < SCREEN_HEIGHT; ++i)
    {
        for (int j = 0; j < SCREEN_WIDTH; ++j)
        {
            draw_dot(j, i, c);
        }
    }
}