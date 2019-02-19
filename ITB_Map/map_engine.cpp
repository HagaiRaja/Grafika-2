#include "map/control.h"
using namespace std;

int main(int argc, char const *argv[])
{
	bool running = true;
	init();

	loadMap("map/map.txt");
	prepareMap(600, 488);

	while (running) {
		running = getCommand();
		refreshMap();
	}
	close_buffer_without_read();
	return 0;
}