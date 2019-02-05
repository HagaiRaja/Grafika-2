#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <set>

using namespace std;

// ---------------------------------- SETUP ----------------------------------

// Melakukan inisialisasi terhadap program.
bool init_sdl();

// Menghentikan program.
void close_sdl();

// --------------------------------- INPUT KEY ---------------------------------

// process all the input from the operating system
void handle_input();

/** 
	return if user had pressed the quit button which is 'q'
*/
bool quit_pressed();

// For below functions you can check the key description on this website
// https://wiki.libsdl.org/SDL_Keycode with "SDL_Keycode Value" column.

// Return the pressed keys
const std::set<SDL_Keycode>& get_tapped_keys();

#endif