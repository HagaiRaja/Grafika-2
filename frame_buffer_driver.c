#include "frame_buffer.h"

int main(int argc, char const *argv[])
{
	/* code */
	init();

	color black = {0,0,0,255};
	color white = {255,255,255,0};
	color red = {255,0,0,0};
	set_background(&white);
	draw_dot(100, 100, &red);
	draw_dot(101, 100, &red);
	draw_dot(102, 100, &red);
	draw_dot(103, 100, &red);
	draw_dot(104, 100, &red);
	draw_dot(105, 100, &red);
	draw_dot(101, 101, &red);
	draw_dot(102, 101, &red);
	draw_dot(103, 101, &red);
	draw_dot(104, 101, &red);
	draw_dot(105, 101, &red);

	printf("vicky something something vicky1");
	color c = getPixelColor(100,100);
	draw_dot(150, 200, &c);
	draw_dot(151, 200, &c);
	draw_dot(152, 200, &c);
	draw_dot(153, 200, &c);
	draw_dot(154, 200, &c);
	draw_dot(155, 200, &c);
	draw_dot(151, 201, &c);
	draw_dot(152, 201, &c);
	draw_dot(153, 201, &c);
	draw_dot(154, 201, &c);
	draw_dot(155, 201, &c);


	printf("vicky something something vicky2");


	close_buffer();
	return 0;
}
