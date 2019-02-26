#include "map/control.h"
using namespace std;

int main(int argc, char const *argv[])
{
	bool running = true;
	init();

	loadMap();
	prepareMap(600, 488);

	while (running) {
		refreshMap();
		running = getCommand();
	}
	close_buffer_without_read();
	return 0;
}