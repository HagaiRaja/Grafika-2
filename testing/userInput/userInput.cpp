#include "../../object/airplane/airplane.h"
#include "../../object/bullet/bullet.h"
#include "../../object/canon/canon.h"
#include "../../object/aircube/aircube.h"
#include "../../graphics/input.h"
#include <unistd.h>
#include <list>
#include <thread> 
using namespace std;

// defining the global variable
int input;
bool inputReady = false;

int getch(void);

void userInput();

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
    	if (inputReady) {
    		point temp = aircube.getCenter();
    		if (input == 120) {
    			temp.y -= 2;
    		}
    		else if (input == 121) {
    			temp.y += 2;
    		}
    		else if (input == 122) {
    			temp.x -= 2;
    		}
    		else if (input == 123) {
    			temp.x += 2;
    		}

    		aircube.setCenter(temp);

    		inputReady = false;
    	}
    	usleep(30000);
    	set_background(&black);
	}

	
	close_buffer();
	// close_sdl();
	return 0;
}

int getch(void)
{
    int ch;
    struct termios oldt;
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
    newt = oldt; /* copy old settings to new settings */
    newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
    ch = getchar(); /* standard getchar call */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
    return ch; /*return received char */
}

void userInput () {
	int x = ' ';
    int y = ' ';
    int z = ' ';

    while (1) {
        x = getch();

        if (x == 27) {
            y = getch();
            z = getch();

            if (x == 27 && y == 91) {
                switch (z) {
                case 65:
                printf("up arrow key pressed\n");
                break;

                case 66:
                printf("down arrow key pressed\n");
                break;

                case 67:
                printf("right arrow key pressed\n");
                break;

                case 68:
                printf("left arrow key pressed\n");
                break;
                }
            }   
        }
        else {
            printf("'%c' key pressed\n", x);
        } 
    }

    return 0;
}