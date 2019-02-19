#include "object/airplane/airplane.h"
#include "object/bullet/bullet.h"
#include "object/canon/canon.h"
#include "object/aircube/aircube.h"
#include "graphics/input.h"
#include <unistd.h>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
	init();
	// init_sdl();

	list<Object*> ListObject;
	list<color> colours;
	bool running = true;
	bool exit = false;
	cube data = {200, 50, 100, 45};

	point top = {1000,300};
	point bottom_center = {SCREEN_WIDTH/2,SCREEN_HEIGHT - 50};
	color black = {0,0,0,0};
	color white = {255,255,255,0};
	color red = {255,0,0,0};
	color green = {0,255,0,0};
	color blue = {0,0,255,0};
	colours.push_back(red);
	colours.push_back(green);
	colours.push_back(blue);
	set_background(&black);

	Canon* canon = new Canon(bottom_center, white);
	// Airplane* airplane = new Airplane(top, white, -1);
	Aircube* aircube = new Aircube(top, colours, data);

	ListObject.push_back(canon);
	// ListObject.push_front(airplane);
	ListObject.push_front(aircube);

	// list<Object*>::iterator it=ListObject.begin();
	// ++it;
	// (*it)->draw();
	while (running && !exit) {
		// handle_input();
  //       if (quit_pressed()) {
  //           running = true;
  //       }

		// // Update input from keyboard
  //       for (auto key : get_tapped_keys()) {
  //       	cout << "halo" << endl;
  //           switch (key) {
  //           	case SDLK_RIGHT :
		// 			cout << "kanan" << endl;
		// 			break;
		// 		case SDLK_LEFT :
		// 			cout << "kiri" << endl;
		// 			break;
		// 		case SDLK_SPACE :
		// 			cout << "fire" << endl;
		// 			break;
  //       	}
  //       }

		// Drawing object
        for (list<Object*>::iterator it=ListObject.begin(); it!=ListObject.end(); ++it)
    	{
    		(*it)->draw();
    	}
    	usleep(30000);
    	set_background(&black);
	}

	
	close_buffer();
	// close_sdl();
	return 0;
}