#include "frame_buffer.h"

int main(int argc, char const *argv[])
{
	/* code */
	init();

	color black = {0,0,0,255};
	color white = {255,255,255,0};
	set_background(&black);
	draw_dot(100, 100, &white);

	close_buffer();
	return 0;
}
