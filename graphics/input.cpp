#include "input.h"
#include <iostream>
using namespace std;

bool quit = false;
std::set<SDL_Keycode> tappedKeys;

bool init_sdl()
{
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {

        if(TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
    }

    return success;
}

void close_sdl()
{
    SDL_Quit();
}

// process all the input from the operating system
void handle_input()
{
	SDL_Event e;
    if (!tappedKeys.empty()) tappedKeys.clear();
    while( SDL_PollEvent( &e ) != 0 )
    {
    	cout << "al" << endl;
        if ( e.type == SDL_QUIT ) {
            quit = true;
        } else if (e.type == SDL_KEYDOWN && !e.key.repeat) {
            tappedKeys.insert(e.key.keysym.sym);
        }
    }
}


/** 
	return if user had pressed the quit button which is 'q'
*/
bool quit_pressed()
{
	return quit;
}


// For below functions you can check the key description on this website
// https://wiki.libsdl.org/SDL_Keycode with "SDL_Keycode Value" column.

// Return the pressed keys
const std::set<SDL_Keycode>& get_tapped_keys() {
    return tappedKeys;
}