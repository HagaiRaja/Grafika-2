#include "ITB_map.h"

color map[SCREEN_WIDTH][SCREEN_HEIGHT];
int map_height, map_width;
int x_left, y_left, x_right, y_right;
int map_scale_left, map_scale_right;

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

// clearing screen with dark mode and put 2 blank screen with given width and height
void prepareMap(unsigned short height, unsigned short width) {
	// setting up backgroung color to black
	color black = {0,0,0,0};
	set_background(&black);

	// making left frame
	color white = {255,255,255,0};
	point 
		top = {(double) (((SCREEN_WIDTH/2)-width)/2) + 3, (double) ((SCREEN_HEIGHT-height)/2) + 3},
		bottom = {(double) (((SCREEN_WIDTH/2)-width)/2) + width + 3, (double) ((SCREEN_HEIGHT-height)/2) + height + 3};
	makeFrame(top, bottom, &white);

	// making center line
	top = {(double) (SCREEN_WIDTH/2) + 3, 0 + 3};
	bottom = {(double) (SCREEN_WIDTH/2) + 3, SCREEN_HEIGHT + 3};
	drawLine(top, bottom, &white);

	// making right frame
	top = {(double) (SCREEN_WIDTH/2) + (((SCREEN_WIDTH/2)-width)/2) + 3, (double) ((SCREEN_HEIGHT-height)/2) + 3},
	bottom = {(double) (SCREEN_WIDTH/2) + (((SCREEN_WIDTH/2)-width)/2) + width + 3, (double) ((SCREEN_HEIGHT-height)/2) + height + 3};
	makeFrame(top, bottom, &white);

	map_scale_right = 1;
	map_scale_left = 1;
	map_height = (int) height;
	map_width = (int) width;
}

// load the map into the screen 
void loadMap(string filename) {
	ifstream imageFile;
	imageFile.open(filename, ios::in);
	if (imageFile.is_open())
	{
		point now;
		color c;
		int temp_r, temp_g, temp_b, temp_a;
		point center = {0, 0};
		do {
			drawPoint.clear();
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
					now.x += 3;
					now.y += 3;
					drawPoint.push_back(now);
					// cout << now.x << " " << now.y << endl;
				}
			} while (now.x != 9999 && now.x != 99999);

			drawPictureNoFill(drawPoint, center, c);
		} while (now.x != 99999);
		
		imageFile.close();
	}
	else cout << "Unable to open file";
}

// if side is true it reset the map on the left and if false then map on the right
void resetMap(bool side) {

}

// changing center (top-left), true for the left map and false for the right
void changeMapOrientation(int dx, int dy, bool side) {

}

// changing scale, true for bigger and false for lesser
// for specific side where true for the left map and false for the right
void changeMapScale(bool scale, bool side) {

}

// refreshing all map
void refreshMap() {

}