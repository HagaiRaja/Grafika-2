#include "object/airplane/airplane.h"
#include "object/bullet/bullet.h"
#include "object/canon/canon.h"
#include "graphics/input.h"
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
	init();
	init_sdl();

	list<Object*> ListObject;
	bool running = true;
	bool exit = false;

	point center = {400,400};
	color black = {0,0,0,0};
	color white = {255,255,255,0};
	set_background(&black);

	Canon* canon = new Canon(center, white);
	Airplane* airplane = new Airplane(center, white, -1);

	ListObject.push_back(canon);
	ListObject.push_front(airplane);

	// list<Object*>::iterator it=ListObject.begin();
	// ++it;
	// (*it)->draw();
	while (running && !exit) {
		handle_input();
        if (quit_pressed()) {
            running = true;
        }

		// Update input from keyboard
        for (auto key : get_tapped_keys()) {
        	cout << "halo" << endl;
            switch (key) {
            	case SDLK_RIGHT :
					cout << "kanan" << endl;
					break;
				case SDLK_LEFT :
					cout << "kiri" << endl;
					break;
				case SDLK_SPACE :
					cout << "fire" << endl;
					break;
        	}
        }

		// Drawing object
        for (list<Object*>::iterator it=ListObject.begin(); it!=ListObject.end(); ++it)
    	{
    		(*it)->draw();
    	}
    	set_background(&black);
	}

	
	close_buffer();
	close_sdl();
	return 0;
}