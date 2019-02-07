#include "../../object/airplane/airplane.h"
#include "../../object/bullet/bullet.h"
#include "../../object/canon/canon.h"
// #include "../../graphics/input.h"
#include <list>
#include <ncurses.h>
#include <iostream>
#include <stdio.h>
#include <ncurses.h>
using namespace std;



#define WIDTH 30
#define HEIGHT 10 


int main(int argc, char const *argv[])
{
	// init();
	initscr();
	clear();
	WINDOW *menu_win;
	int c;
	int startx = 0;
	int starty = 0;


	// list<Object*> ListObject;
	bool running = true;
	bool exit = false;

	// point center = {400,400};
	// color black = {0,0,0,0};
	// color white = {255,255,255,0};
	// set_background(&black);

	// Canon* canon = new Canon(center, white);
	// Airplane* airplane = new Airplane(center, white, -1);

	// ListObject.push_back(canon);
	// ListObject.push_front(airplane);

	// list<Object*>::iterator it=ListObject.begin();
	// ++it;
	// (*it)->draw();
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
		
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	refresh();

	while (running && !exit) {
		
		c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				cout << "UP" << endl;
			case KEY_DOWN:
				cout << "DOWN" << endl;
		}
		// Drawing object
     //    for (list<Object*>::iterator it=ListObject.begin(); it!=ListObject.end(); ++it)
    	// {
    	// 	(*it)->draw();
    	// }
    	// set_background(&black);
	}

	refresh();
	endwin();
	// close_buffer();
	return 0;
}