#include "ITB_map.h"
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

color map[SCREEN_WIDTH][SCREEN_HEIGHT];
int map_height = 600, map_width = 488;
int x_left, y_left, x_right, y_right;
unsigned short offset_x_left, offset_y_left, offset_x_right, offset_y_right;
double map_scale_left, map_scale_right;

// helper function to load from framebuffer to map
void loadToMap();

// drawing map to the left side with given atribute
void drawLeft();

// drawing map to the right side with given attribute
void drawRight();

// making a frame from given two corner
void makeFrame(point topLeft, point bottomRight, color* c) {
	point
		topRight = {bottomRight.x, topLeft.y},
		bottomLeft = {topLeft.x, bottomRight.y};

	drawLine(topRight, topLeft, c);
	drawLine(topLeft, bottomLeft, c);
	drawLine(bottomLeft, bottomRight, c);
	drawLine(bottomRight, topRight, c);
}

void makeAllFrame (unsigned short height, unsigned short width) {
	// setting up backgroung color to black
	color black = {0,0,0,0};
	set_background(&black);

	// making left frame
	color white = {255,255,255,0};
	point 
		top = {(double) (((SCREEN_WIDTH/2)-width)/2) - 3, (double) ((SCREEN_HEIGHT-height)/2) - 3},
		bottom = {(double) (((SCREEN_WIDTH/2)-width)/2) + width + 3, (double) ((SCREEN_HEIGHT-height)/2) + height + 3};
	makeFrame(top, bottom, &white);

	// making center line
	top = {(double) (SCREEN_WIDTH/2), 0};
	bottom = {(double) (SCREEN_WIDTH/2), SCREEN_HEIGHT};
	drawLine(top, bottom, &white);

	// making right frame
	top = {(double) (SCREEN_WIDTH/2) + (((SCREEN_WIDTH/2)-width)/2) - 3, (double) ((SCREEN_HEIGHT-height)/2) - 3},
	bottom = {(double) (SCREEN_WIDTH/2) + (((SCREEN_WIDTH/2)-width)/2) + width + 3, (double) ((SCREEN_HEIGHT-height)/2) + height + 3};
	makeFrame(top, bottom, &white);
}

// clearing screen with dark mode and put 2 blank screen with given width and height
void prepareMap(unsigned short height, unsigned short width) {
	makeAllFrame(height, width);

	map_scale_right = 1;
	map_scale_left = 1;
	map_height = (int) height;
	map_width = (int) width;

	// initiating starting point
	x_left = 0; y_left = 0; x_right = 0; y_right = 0;
	offset_x_left = (unsigned short) (((SCREEN_WIDTH/2)-width)/2); 
	offset_y_left = (unsigned short) ((SCREEN_HEIGHT-height)/2); 
	offset_x_right = (unsigned short) (SCREEN_WIDTH/2) + (((SCREEN_WIDTH/2)-width)/2); 
	offset_y_right = (unsigned short) ((SCREEN_HEIGHT-height)/2);
}

// load the map into the screen 
void loadMap(string filename) {
	// setting up backgroung color to black
	color black = {0,0,0,0};
	set_background(&black);

	ifstream imageFile;
	list<point> drawPoint;
	imageFile.open(filename, ios::in);
	if (imageFile.is_open())
	{
		point now;
		color c;
		int temp_r, temp_g, temp_b, temp_a;
		point center = {0, 0};
		do {
			drawPoint.clear();

			char temp;
			imageFile >> temp;
			if (temp == '#') {
				imageFile >> temp;
				while (temp != '#') {
					imageFile >> temp;
				}
			}

			imageFile >> temp_r >> temp_g >> temp_b >> temp_a;
			c.r = (unsigned char) temp_r;
			c.g = (unsigned char) temp_g;
			c.b = (unsigned char) temp_b;
			c.a = (unsigned char) temp_a;
			do {
				// read new point
				imageFile >> now.x >> now.y;

				// adding point
				if (now.x != 9999 && now.x != 99999) {
					now.x += 3; now.y += 3;
					drawPoint.push_back(now);
				}
			} while (now.x != 9999 && now.x != 99999);

			drawPictureNoFill(drawPoint, center, c);

		} while (now.x != 99999);
		
		loadToMap();		
		imageFile.close();
	}
	else cout << "Unable to open file";
}

// if side is true it reset the map on the left and if false then map on the right
void resetMap(bool side) {
	if (side) {
		map_scale_left = 1;
		x_left = 0; y_left = 0;
	}
	else {
		map_scale_right = 1;
		x_right = 0; y_right = 0;
	}
}

// changing center (top-left), true for the left map and false for the right
void changeMapOrientation(int dx, int dy, bool side) {
	if (side) {
		if ( (((int) (map_scale_left*(x_left+dx))) <= (map_width - (map_width/map_scale_left))) && (((int) (map_scale_left*(x_left+dx))) >= 0) &&
			(((int) (map_scale_left*(y_left+dy))) <= (map_height - (map_height/map_scale_left))) && (((int) (map_scale_left*(y_left+dy))) >= 0)) {
			x_left += dx;
			y_left += dy;
		}
	}
	else {
		if ( (((int) (map_scale_right*(x_right+dx))) <= (map_width - (map_width/map_scale_right))) && (((int) (map_scale_right*(x_right+dx))) >= 0) &&
			(((int) (map_scale_right*(y_right+dy))) <= (map_height - (map_height/map_scale_right))) && (((int) (map_scale_right*(y_right+dy))) >= 0)) {
			x_right += dx;
			y_right += dy;
		}
	}
}

// changing scale, true for bigger and false for lesser
// for specific side where true for the left map and false for the right
void changeMapScale(bool scale, bool side) {
	double scalingFactor = 0.2;
	if (side) {
		if (scale) {
			if (map_scale_left < 10) {
				map_scale_left += scalingFactor;
			}
		}
		else {
			if (map_scale_left > 1.1) {
				map_scale_left -= scalingFactor;
				if (x_left+(map_width/map_scale_left) > map_width) {
					x_left -= (map_width*scalingFactor);
					y_left -= (map_height*scalingFactor);
				}
				if (x_left < 0 || y_left < 0) {
					x_left = 0;
					y_left = 0;	
				}
			}
		}
	}
	else {
		if (scale) {
			if (map_scale_right < 10) {
				map_scale_right += scalingFactor;
			}
		}
		else {
			if (map_scale_right > 1.1) {
				map_scale_right -= scalingFactor;
				if (x_right+(map_width/map_scale_right) > map_width) {
					x_right -= (map_width*scalingFactor);
					y_right -= (map_height*scalingFactor);
				}
				if (x_right < 0 || y_right < 0) {
					x_right = 0;
					y_right = 0;	
				}
			}
		}
	}
}

// refreshing all map
void refreshMap() {
	makeAllFrame(map_height, map_width);
	drawLeft();
	drawRight();
}

void loadToMap() {
	color temp = {255, 0, 0, 0};

	for (int i = 0; i < map_width; ++i)
	{
		for (int j = 0; j < map_height; ++j)
		{
			map[i][j] = getPixelColor((unsigned short) i + 3, (unsigned short) j + 3);
			// temp = map[i][j];
			// unsigned short a = 255;
			// if (temp.r == a) {
			// 	cout << "woi" << endl;
			// }
			// draw_dot((unsigned short) i + 550, (unsigned short) j + 3, &temp);
		}
	}
}

// drawing map to the left side with given atribute
void drawLeft() { 
	color temp = {255, 0, 0, 0};
	for (int i = 0; i < map_width; ++i)
	{
		for (int j = 0; j < map_height; ++j)
		{
			temp = map[(int) ((x_left*map_scale_left)+(i/map_scale_left))]
						[(int) ((y_left*map_scale_left)+(j/map_scale_left))];
			draw_dot((unsigned short) i + offset_x_left, 
				(unsigned short) j + offset_y_left, 
				&temp);
		}
	}
}

// drawing map to the right side with given attribute
void drawRight() { 
	color temp = {255, 0, 0, 0};

	for (int i = 0; i < map_width; ++i)
	{
		for (int j = 0; j < map_height; ++j)
		{
			temp = map[(int) ((x_right*map_scale_right)+(i/map_scale_right))]
						[(int) ((y_right*map_scale_right)+(j/map_scale_right))];
			draw_dot((unsigned short) i + offset_x_right, 
				(unsigned short) j + offset_y_right, 
				&temp);
		}
	}
}