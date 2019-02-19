#include "../../graphics/draw.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

list<point> drawPoint;

void loadDrawPoint(string filename);
list<point> rotate(list<point> drawPoints, point center, double degree);

int main(int argc, char const *argv[])
{
	/* code */
	init();
	color black = {0,0,0,0};
	color white = {255,255,255,0};
	set_background(&black);

	point center = {300, 300};
	// filename relative from compiler
	loadDrawPoint("sample.txt");
	double degree = 0;
	while (degree < 720) {
		list<point> temp = rotate(drawPoint, center, degree);
		drawPicture(temp, center, white);
		usleep(30000);
		set_background(&black);
		degree += 1;
	}
	
	close_buffer();
	return 0;
}

void loadDrawPoint(string filename)
{
	ifstream imageFile;
	imageFile.open(filename, ios::in);
	if (imageFile.is_open())
	{
		point now;

		do {
			// read new point
			imageFile >> now.x >> now.y;

			// adding point
			if (now.x != 9999) {
				drawPoint.push_back(now);
			}
		} while (now.x != 9999);
		

		imageFile.close();
	}
	else cout << "Unable to open file";
}


list<point> rotate(list<point> drawPoints, point center, double degree) 
{
	for (list<point>::iterator it=drawPoints.begin(); it!=drawPoints.end(); ++it){
		double tempX = (*it).x, tempY = (*it).y;
		(*it).x = tempX * cos(degree*PI/180) - tempY* sin(degree*PI/180);
		(*it).y = tempX * sin(degree*PI/180) + tempY * cos(degree*PI/180);
	}

	return drawPoints;
}