/* ********** Definition of function for drawing map on screen ********** */

#ifndef ITB_MAP_H
#define ITB_MAP_H

#include "../../graphics/draw.hpp"
#include <iostream>
#include <list>
#include <math.h>
#include <string>
using namespace std;

// clearing screen with dark mode and put 2 blank screen with given width and height
void prepareMap(unsigned short height, unsigned short width);

// load the map into the screen 
void loadMap(string filename);

// if side is true it reset the map on the right and if false then map on the left
void resetMap(bool side);

// changing center (top-left), true for the right map and false for the left
void changeMapOrientation(int dx, int dy, bool side);

// changing scale, true for bigger and false for lesser
// for specific side where true for the right map and false for the left
void changeMapScale(bool scale, bool side);

// refreshing all map
void refreshMap();


#endif