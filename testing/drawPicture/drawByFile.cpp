#include "../../graphics/draw.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	init();
	color black = {0,0,0,0};
	set_background(&black);

	point center = {300, 300};
	// filename relative from compiler
	drawPicture("sample.txt", center);
	

	close_buffer();
	return 0;
}