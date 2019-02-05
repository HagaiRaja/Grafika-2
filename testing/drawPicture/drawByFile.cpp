#include "../../graphics/draw.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	init();
	color black = {0,0,0,0};
	color white = {255,255,255,0};
	set_background(&black);

	point center = {300, 300};
	// filename relative from compiler
	drawPicture("sample.txt", center, white);
	

	close_buffer();
	return 0;
}