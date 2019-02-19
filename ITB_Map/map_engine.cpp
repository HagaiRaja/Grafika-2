#include "map/control.h"
using namespace std;

int main(int argc, char const *argv[])
{
	bool running = true;
	init();

	prepareMap(600, 488);
	loadMap("map/map.txt");

	while (running) {
		running = getCommand();
	}
	close_buffer_without_read();
	return 0;
}