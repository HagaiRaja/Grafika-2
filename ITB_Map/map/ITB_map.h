/* ********** Definition of function for drawing map on screen ********** */

#ifndef ITB_MAP_H
#define ITB_MAP_H

#include "../../graphics/draw.hpp"
#include <iostream>
#include <list>
#include <math.h>
#include <string>
using namespace std;

typedef struct{
    color map[SCREEN_WIDTH][SCREEN_HEIGHT];
    bool show = true;
} Map;

// clearing screen with dark mode and put 2 blank screen with given width and height
void prepareMap(unsigned short height, unsigned short width);

// load the map into the screen 
void loadMap();

// if side is true it reset the map on the left and if false then map on the right
void resetMap(bool side);

// changing center (top-left), true for the left map and false for the right
void changeMapOrientation(int dx, int dy, bool side);

// changing scale, true for bigger and false for lesser
// for specific side where true for the left map and false for the right
void changeMapScale(bool scale, bool side);

// refreshing all map
void refreshMap();

// show and hide map on a number
// 1 = building
// 2 = tree
// 3 = road
void swapSee(int map_number);


#endif