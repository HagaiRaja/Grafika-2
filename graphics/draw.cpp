#include "draw.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;


// given a number and return the absolut value
unsigned short absolute (double a)
{
	double temp;
	temp = (a > 0) ? a : -a;
	unsigned short ans = temp;
	return ans; 
}

// Drawing line from point p to point q with given color c
// Implementation using bresenham algorithm
void _drawLine(point p, point q, color* c)
{
        // Bresenham's line algorithm
  const bool steep = (fabs(q.y - p.y) > fabs(q.x - p.x));
  if(steep)
  {
    std::swap(p.x, p.y);
    std::swap(q.x, q.y);
  }
 
  if(p.x > q.x)
  {
    std::swap(p.x, q.x);
    std::swap(p.y, q.y);
  }
 
  const float dx = q.x - p.x;
  const float dy = fabs(q.y - p.y);
 
  float error = dx / 2.0f;
  const int ystep = (p.y < q.y) ? 1 : -1;
  int y = (int)p.y;
 
  const int maxX = (int)q.x;
 
  for(int x=(int)p.x; x<maxX; x++)
  {
    if(steep)
    {
    	draw_dot(((unsigned short) (p.y)), ((unsigned short) (p.x)), c);
        // SetPixel(y,x, color);
    }
    else
    {
    	draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
        // SetPixel(x,y, color);
    }
 
    error -= dy;
    if(error < 0)
    {
        y += ystep;
        error += dx;
    }
  }
}

// Drawing line from point p to point q with given color c
// Implementation using bresenham algorithm
void drawLine(point p, point q, color* c) 
{
	double px = p.x, py = p.y, qx = q.x, qy = q.y;
	double temp;
	
	if (((unsigned short) (p.x)) == ((unsigned short) (q.x))) { // infinity margin
		if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
			for (unsigned short i = 0; i < absolute(py - qy); ++i)
			{
				/* code */
				draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y))-i, c);
			}
		}
		else {
			for (unsigned short i = 0; i < absolute(py - qy); ++i)
			{
				/* code */
				draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y))+i, c);
			}
		}
	}
	else {
		double margin = (py - qy)/(px - qx);
		if (margin > 1) {
			double newMargin = 1 / margin;
			temp = newMargin;

			draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
			if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
				do {
					p.y -= 1;
					if (temp > 1 || ((p.x == q.x + 1) && (p.y == q.y))) {
						temp -= 1;
						p.x -= 1;
					}
					temp += newMargin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) || (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
			else {
				do {
					p.y += 1;
					if (temp > 1 || ((p.x == q.x - 1) && (p.y == q.y))) {
						temp -= 1;
						p.x += 1;
					}
					temp += newMargin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) || (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
		}
		else if (margin < -1) {
			double newMargin = 1 / margin;
			temp = newMargin;

			draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
			if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
				do {
					p.y -= 1;
					if (temp < -1 || ((p.x == q.x - 1) && (p.y == q.y))) {
						temp += 1;
						p.x += 1;
					}
					temp += newMargin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) || (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
			else {
				do {
					p.y += 1;
					if (temp < -1 || p.x == q.x + 1) {
						temp += 1;
						p.x -= 1;
					}
					temp += newMargin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) || (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
		}
		else if (margin == 1) {
			if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
				for (unsigned short i = 0; i < absolute(py - qy); ++i)
				{
					/* code */
					draw_dot(((unsigned short) (p.x))-i, ((unsigned short) (p.y))-i, c);
				}
			}
			else {
				for (unsigned short i = 0; i < absolute(py - qy); ++i)
				{
					/* code */
					draw_dot(((unsigned short) (p.x))+i, ((unsigned short) (p.y))+i, c);
				}
			}
		}
		else if (margin == -1) {
			if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
				for (unsigned short i = 0; i < absolute(py - qy); ++i)
				{
					/* code */
					draw_dot(((unsigned short) (p.x))+i, ((unsigned short) (p.y))-i, c);
				}
			}
			else {
				for (unsigned short i = 0; i < absolute(py - qy); ++i)
				{
					/* code */
					draw_dot(((unsigned short) (p.x))-i, ((unsigned short) (p.y))+i, c);
				}
			}
		}
		else if (margin > -1 && margin < 0) {
			temp = margin;

			draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
			if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
				do {
					p.x += 1;
					if (temp < -1 || ((p.y == q.y + 1) && (p.x == q.x))) {
						temp += 1;
						p.y -= 1;
					}
					temp += margin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) || (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
			else {
				do {
					p.x -= 1;
					if (temp < -1 || ((p.y == q.y - 1) && (p.x == q.x))) {
						temp += 1;
						p.y += 1;
					}
					temp += margin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) || (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
		}
		else if (margin < 1 && margin > 0) {
			temp = margin;

			draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
			if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
				do {
					p.x -= 1;
					if (temp > 1 || ((p.y == q.y + 1) && (p.x == q.x))) {
						temp -= 1;
						p.y -= 1;
					}
					temp += margin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) || (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
			else {
				do {
					p.x += 1;
					if (temp > 1 || ((p.y == q.y - 1) && (p.x == q.x))) {
						temp -= 1;
						p.y += 1;
					}
					temp += margin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) || (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
		}
		else { // margin 0 
			if (((unsigned short) (p.x)) > ((unsigned short) (q.x))) {
				for (unsigned short i = 0; i < absolute(px - qx); ++i)
				{
					/* code */
					draw_dot(((unsigned short) (p.x))-i, ((unsigned short) (p.y)), c);
				}
			}
			else {
				for (unsigned short i = 0; i < absolute(px - qx); ++i)
				{
					/* code */
					draw_dot(((unsigned short) (p.x))+i, ((unsigned short) (p.y)), c);
				}
			}
		}
	}
}
 
// drawing a picture by given dots from drawPoint
// and draw it relatively from given center point
void drawPicture (list<point> drawPoint, point center, color c)
{
	point now, prev, first;
	list<point>::iterator it = drawPoint.begin();
	list<point>::iterator end = drawPoint.end();
	color noColor = {254,254,254,0};
	list<point> ctPoints;

	// first point
	now.x = center.x + (*it).x;
	now.y = center.y + (*it).y;
	first = now;
	ctPoints.push_back(now);
	do {
		// read new point
		++it;

		// draw line
		if (it == end) {
			// end of line
			drawLine(now, first, &noColor);
		}
		else {
			// updating point
			prev = now;	
			now.x = center.x + (*it).x;
			now.y = center.y + (*it).y;
			ctPoints.push_back(now);
			drawLine(prev, now, &noColor);
		}
	} while (it != end);

	// rasterObject(ctPoints, &c);
	BFill(center.x, center.y, &c, 0);
}

// drawing a cube at given center given width, length and height
// cube will be seen rotate at given degree to right
void drawCube(point center, cube data, list<color> colors) 
{
	color nowColor;
	color noColor = {254,254,254,0};
	// big image
	/*
		7--------------6
	   -              --
	  1--------------2 -
	  -			     - -
	  -	8  center    - 5 
	  -				 --
	  4--------------3

	*/
	// generating dots
	point
	point1 = {center.x - (((data.width)/2) * ((center.y*3)/SCREEN_HEIGHT)), center.y - (((data.height)/2) * ((center.y*3)/SCREEN_HEIGHT))},
	point2 = {center.x + (((data.width)/2) * ((center.y*3)/SCREEN_HEIGHT)), center.y - (((data.height)/2) * ((center.y*3)/SCREEN_HEIGHT))},
	point3 = {center.x + (((data.width)/2) * ((center.y*3)/SCREEN_HEIGHT)), center.y + (((data.height)/2) * ((center.y*3)/SCREEN_HEIGHT))},
	point4 = {center.x - (((data.width)/2) * ((center.y*3)/SCREEN_HEIGHT)), center.y + (((data.height)/2) * ((center.y*3)/SCREEN_HEIGHT))};
	list<point> ctPoints;

	// drawing front
	nowColor = colors.front();
	colors.pop_front();
	ctPoints.clear();
	drawLine(point1, point2, &noColor); ctPoints.push_back(point1);
	drawLine(point2, point3, &noColor); ctPoints.push_back(point2);
	drawLine(point3, point4, &noColor); ctPoints.push_back(point3);
	drawLine(point4, point1, &noColor); ctPoints.push_back(point4);
	rasterObject(ctPoints, &nowColor);

	// calculating slope
	double dx = sin((data.degree)*PI/180) * data.length * ((center.y*3)/SCREEN_HEIGHT);
	double dy = cos((data.degree)*PI/180) * data.length * ((center.y*3)/SCREEN_HEIGHT);
	// cout << dx << " " << dy << endl;
	point
		point5 = {point3.x + dx, point3.y - dy},
		point6 = {point2.x + dx, point2.y - dy},
		point7 = {point1.x + dx, point1.y - dy},
		point8 = {point4.x + dx, point4.y - dy};

	if (dx > 0 && dy > 0) {
		// drawing side 1
		nowColor = colors.front();
		colors.pop_front();
		ctPoints.clear();
		drawLine(point2, point3, &noColor); ctPoints.push_back(point2);
		drawLine(point3, point5, &noColor); ctPoints.push_back(point3);
		drawLine(point5, point6, &noColor); ctPoints.push_back(point5);
		drawLine(point6, point2, &noColor); ctPoints.push_back(point6);
		rasterObject(ctPoints, &nowColor);

		// drawing side 2
		nowColor = colors.front();
		colors.pop_front();
		ctPoints.clear();
		drawLine(point1, point2, &noColor); ctPoints.push_back(point1);
		drawLine(point2, point6, &noColor); ctPoints.push_back(point2);
		drawLine(point6, point7, &noColor); ctPoints.push_back(point6);
		drawLine(point7, point1, &noColor); ctPoints.push_back(point7);
		rasterObject(ctPoints, &nowColor);
	}
	else if (dx > 0 && dy < 0) {
		// drawing side 1
		nowColor = colors.front();
		colors.pop_front();
		ctPoints.clear();
		drawLine(point2, point3, &noColor); ctPoints.push_back(point2);
		drawLine(point3, point5, &noColor); ctPoints.push_back(point3);
		drawLine(point5, point6, &noColor); ctPoints.push_back(point5);
		drawLine(point6, point2, &noColor); ctPoints.push_back(point6);
		rasterObject(ctPoints, &nowColor);

		// drawing side 2
		nowColor = colors.front();
		colors.pop_front();
		ctPoints.clear();
		drawLine(point4, point3, &noColor); ctPoints.push_back(point4);
		drawLine(point3, point5, &noColor); ctPoints.push_back(point3);
		drawLine(point5, point8, &noColor); ctPoints.push_back(point5);
		drawLine(point8, point4, &noColor); ctPoints.push_back(point8);
		rasterObject(ctPoints, &nowColor);
	}
	else if (dx < 0 && dy < 0) {
		// drawing side 1
		nowColor = colors.front();
		colors.pop_front();
		ctPoints.clear();
		drawLine(point1, point7, &noColor); ctPoints.push_back(point1);
		drawLine(point7, point8, &noColor); ctPoints.push_back(point7);
		drawLine(point8, point4, &noColor); ctPoints.push_back(point8);
		drawLine(point4, point1, &noColor); ctPoints.push_back(point4);
		rasterObject(ctPoints, &nowColor);

		// drawing side 2
		nowColor = colors.front();
		colors.pop_front();
		ctPoints.clear();
		drawLine(point4, point3, &noColor); ctPoints.push_back(point4);
		drawLine(point3, point5, &noColor); ctPoints.push_back(point3);
		drawLine(point5, point8, &noColor); ctPoints.push_back(point5);
		drawLine(point8, point4, &noColor); ctPoints.push_back(point8);
		rasterObject(ctPoints, &nowColor);
	}
	else if (dx < 0 && dy > 0) {
		// drawing side 1
		nowColor = colors.front();
		colors.pop_front();
		ctPoints.clear();
		drawLine(point1, point7, &noColor); ctPoints.push_back(point1);
		drawLine(point7, point8, &noColor); ctPoints.push_back(point7);
		drawLine(point8, point4, &noColor); ctPoints.push_back(point8);
		drawLine(point4, point1, &noColor); ctPoints.push_back(point4);
		rasterObject(ctPoints, &nowColor);

		// drawing side 2
		nowColor = colors.front();
		colors.pop_front();
		ctPoints.clear();
		drawLine(point1, point2, &noColor); ctPoints.push_back(point1);
		drawLine(point2, point6, &noColor); ctPoints.push_back(point2);
		drawLine(point6, point7, &noColor); ctPoints.push_back(point6);
		drawLine(point7, point1, &noColor); ctPoints.push_back(point7);
		rasterObject(ctPoints, &nowColor);
	}
}

// return true if it contain the no color
bool isNoColor(unsigned short x, unsigned short y){
	color c = getPixelColor(x,y);
	return (c.r == 254 && c.g == 254 && c.b == 254);
}

// return true if it contain the color
bool isColor(unsigned short x, unsigned short y, color * colour){
	color c = getPixelColor(x,y);
	return (c.r == colour->r && c.g == colour->g && c.b == colour->b);
}

// return true if all of the above color is no color
bool aboveCheck (unsigned short i, unsigned short j) {
	return (isNoColor(i-1,j-1) && isNoColor(i,j-1) && isNoColor(i+1,j-1)
		&& isNoColor(i-2,j-1) && isNoColor(i+2,j-1)
		&& isNoColor(i-3,j-1) && isNoColor(i+3,j-1)
		&& isNoColor(i-4,j-1) && isNoColor(i+4,j-1));
}

// return true if all of the below color is no color
bool belowCheck (unsigned short i, unsigned short j) {
	return (isNoColor(i-1,j+1) && isNoColor(i,j+1) && isNoColor(i+1,j+1)
		&& isNoColor(i-2,j+1) && isNoColor(i+2,j+1)
		&& isNoColor(i-3,j+1) && isNoColor(i+3,j+1)
		&& isNoColor(i-4,j+1) && isNoColor(i+4,j+1));
}

void rasterObject(list<point>& ctPoints, color* c){
	unsigned short xmin, xmax, ymin, ymax;
	xmin = ctPoints.front().x;
	xmax = ctPoints.front().x;
	ymin = ctPoints.front().y;
	ymax = ctPoints.front().y;
	color white = {255,255,255,0};

	for (list<point>::iterator it=ctPoints.begin(); it!=ctPoints.end(); ++it){
		if ((*it).x < xmin)
			xmin = (*it).x;
		if ((*it).x > xmax)
			xmax = (*it).x;
		if ((*it).y < ymin)
			ymin = (*it).y;
		if ((*it).y > ymax)
			ymax = (*it).y;
	}

	// Start rastering
	for (int j=ymin; j<=ymax+1; j++){
		int drawMode = 0; // mode 0 = passing by, mode 1 = coloring
		for (int i=xmin; i<=xmax; i++){
			if (isNoColor(i,j)){
				//check if it is anomaly dots
				bool 
					above = aboveCheck(i,j),
					below = belowCheck(i,j);
				if ((!above && below) || (above && !below)){
					drawMode = drawMode;
				}
				else {
					if (drawMode == 0)
						drawMode = 1;
					else drawMode = 0;
				}
				draw_dot(i,j,&white);
			}
			else {
				if (drawMode == 1) {
					draw_dot(i,j,c);
				}
			}
		}

	}
}

void fillObject(point center, color* c){
	if (isNoColor(center.x, center.y) && !isColor(center.x, center.y, c)){
		draw_dot(center.x, center.y, c);
	}
	else {
		draw_dot(center.x,center.y,c);
		point
		n = {center.x, center.y - 1},
		ne = {center.x + 1, center.y - 1},
		e = {center.x + 1, center.y},
		se = {center.x + 1, center.y + 1},
		s = {center.x, center.y + 1},
		sw = {center.x - 1, center.y + 1},
		w = {center.x - 1, center.y},
		nw = {center.x - 1, center.y - 1};
		fillObject(n, c);
		fillObject(ne, c);
		fillObject(e, c);
		fillObject(se, c);
		fillObject(s, c);
		fillObject(sw, c);
		fillObject(w, c);
		fillObject(nw, c);
	}
}

// drawing a picture by given dots from drawPoint
// and draw it relatively from given center point
void drawPictureNoFill (list<point> drawPoint, point center, color c) {
	point now, prev, first;
	list<point>::iterator it = drawPoint.begin();
	list<point>::iterator end = drawPoint.end();
	color noColor = {254,254,254,0};
	list<point> ctPoints;

	// first point
	now.x = center.x + (*it).x;
	now.y = center.y + (*it).y;
	first = now;
	ctPoints.push_back(now);
	do {
		// read new point
		++it;

		// draw line
		if (it == end) {
			// end of line
			drawLine(now, first, &noColor);
		}
		else {
			// updating point
			prev = now;	
			now.x = center.x + (*it).x;
			now.y = center.y + (*it).y;
			ctPoints.push_back(now);
			drawLine(prev, now, &noColor);
		}
	} while (it != end);
}

list<point> loadDrawPoint(string filename)
{
	list<point> drawPoint;
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

	return drawPoint;
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

list<point> scale(list<point> drawPoints, point center, double factor) 
{
	for (list<point>::iterator it=drawPoints.begin(); it!=drawPoints.end(); ++it){
		double tempX = (*it).x, tempY = (*it).y;
		(*it).x = tempX * factor;
		(*it).y = tempY * factor;
	}

	return drawPoints;
}

// drawing a spinner at given center given center
// spinner will be seen rotate at given degree to right
void drawSpin(point center, double degree, color c) {
	list<point> drawPoint;
	drawPoint = loadDrawPoint("object/aircube/spin.txt");
	list<point> temp = rotate(drawPoint, center, degree);
	drawPoint = scale(temp, center, ((center.y*3)/SCREEN_HEIGHT));
	drawPicture(drawPoint, center, c);
}


// return true if it contain the color
bool canColor(unsigned short x, unsigned short y, color * colour){
	color c = getPixelColor(x,y);
	return (c.r == colour->r && c.g == colour->g && c.b == colour->b) || (c.r == 254 && c.g == 254 && c.b == 254);
}

// direction
// 0 = init, 1 from left, 2 from right, 3 from up, 4 from down
void BFill(unsigned short x, unsigned short y, color* c, int direction) {
	if (!canColor(x, y, c)) {
		draw_dot(x, y, c);
		if (direction == 0) {
			BFill(x-1, y, c, 1);
			BFill(x+1, y, c, 2);
			BFill(x, y-1, c, 3);
			BFill(x, y+1, c, 4);
		}
		else if (direction == 1) {
			BFill(x-1, y, c, 1);
			BFill(x, y-1, c, 3);
			BFill(x, y+1, c, 4);
		}
		else if (direction == 2) {
			BFill(x+1, y, c, 2);
			BFill(x, y-1, c, 3);
			BFill(x, y+1, c, 4);
		}
		else if (direction == 3) {
			BFill(x-1, y, c, 1);
			BFill(x+1, y, c, 2);
			BFill(x, y-1, c, 3);
		}
		else if (direction == 4) {
			BFill(x-1, y, c, 1);
			BFill(x+1, y, c, 2);
			BFill(x, y+1, c, 4);
		}

	}
}