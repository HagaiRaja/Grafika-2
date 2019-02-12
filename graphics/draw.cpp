#include "draw.hpp"

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
					if (temp > 1) {
						temp -= 1;
						p.x -= 1;
					}
					temp += newMargin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) && (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
			else {
				do {
					p.y += 1;
					if (temp > 1) {
						temp -= 1;
						p.x += 1;
					}
					temp += newMargin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) && (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
		}
		else if (margin < -1) {
			double newMargin = 1 / margin;
			temp = newMargin;

			draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
			if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
				do {
					p.y -= 1;
					if (temp < -1) {
						temp += 1;
						p.x += 1;
					}
					temp += newMargin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) && (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
			else {
				do {
					p.y += 1;
					if (temp < -1) {
						temp += 1;
						p.x -= 1;
					}
					temp += newMargin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) && (((unsigned) (p.y)) != ((unsigned short) (q.y))));
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
					if (temp < -1) {
						temp += 1;
						p.y -= 1;
					}
					temp += margin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) && (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
			else {
				do {
					p.x -= 1;
					if (temp < -1) {
						temp += 1;
						p.y += 1;
					}
					temp += margin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) && (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
		}
		else if (margin < 1 && margin > 0) {
			temp = margin;

			draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
			if (((unsigned short) (p.y)) > ((unsigned short) (q.y))) {
				do {
					p.x -= 1;
					if (temp > 1) {
						temp -= 1;
						p.y -= 1;
					}
					temp += margin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) && (((unsigned) (p.y)) != ((unsigned short) (q.y))));
			}
			else {
				do {
					p.x += 1;
					if (temp > 1) {
						temp -= 1;
						p.y += 1;
					}
					temp += margin;
					draw_dot(((unsigned short) (p.x)), ((unsigned short) (p.y)), c);
				} while ((((unsigned short) (p.x)) != ((unsigned short) (q.x))) && (((unsigned) (p.y)) != ((unsigned short) (q.y))));
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

	// first point
	now.x = center.x + (*it).x;
	now.y = center.y + (*it).y;
	first = now;
	do {
		// read new point
		++it;

		// draw line
		if (it == end) {
			// end of line
			drawLine(now, first, &c);
		}
		else {
			// updating point
			prev = now;	
			now.x = center.x + (*it).x;
			now.y = center.y + (*it).y;
			drawLine(prev, now, &c);
		}
	} while (it != end);
}

// drawing a cube at given center given width, length and height
// cube will be seen rotate at given degree to right
void drawCube(point center, cube data, list<color> colors) 
{
	color nowColor;
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
	point1 = {center.x - ((data.width)/2), center.y - ((data.height)/2)},
	point2 = {center.x + ((data.width)/2), center.y - ((data.height)/2)},
	point3 = {center.x + ((data.width)/2), center.y + ((data.height)/2)},
	point4 = {center.x - ((data.width)/2), center.y + ((data.height)/2)};

	// drawing front
	nowColor = colors.front();
	colors.pop_front();
	drawLine(point1, point2, &nowColor);
	drawLine(point2, point3, &nowColor);
	drawLine(point3, point4, &nowColor);
	drawLine(point4, point1, &nowColor);

	// calculating slope
	double dx = sin((data.degree)*PI/180) * data.length;
	double dy = cos((data.degree)*PI/180) * data.length;
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
		drawLine(point2, point3, &nowColor);
		drawLine(point3, point5, &nowColor);
		drawLine(point5, point6, &nowColor);
		drawLine(point6, point2, &nowColor);

		// drawing side 2
		nowColor = colors.front();
		colors.pop_front();
		drawLine(point1, point2, &nowColor);
		drawLine(point2, point6, &nowColor);
		drawLine(point6, point7, &nowColor);
		drawLine(point7, point1, &nowColor);
	}
	else if (dx > 0 && dy < 0) {
		// drawing side 1
		nowColor = colors.front();
		colors.pop_front();
		drawLine(point2, point3, &nowColor);
		drawLine(point3, point5, &nowColor);
		drawLine(point5, point6, &nowColor);
		drawLine(point6, point2, &nowColor);

		// drawing side 2
		nowColor = colors.front();
		colors.pop_front();
		drawLine(point4, point3, &nowColor);
		drawLine(point3, point5, &nowColor);
		drawLine(point5, point8, &nowColor);
		drawLine(point8, point4, &nowColor);
	}
	else if (dx < 0 && dy < 0) {
		// drawing side 1
		nowColor = colors.front();
		colors.pop_front();
		drawLine(point1, point7, &nowColor);
		drawLine(point7, point8, &nowColor);
		drawLine(point8, point4, &nowColor);
		drawLine(point4, point1, &nowColor);

		// drawing side 2
		nowColor = colors.front();
		colors.pop_front();
		drawLine(point4, point3, &nowColor);
		drawLine(point3, point5, &nowColor);
		drawLine(point5, point8, &nowColor);
		drawLine(point8, point4, &nowColor);
	}
	else if (dx < 0 && dy > 0) {
		// drawing side 1
		nowColor = colors.front();
		colors.pop_front();
		drawLine(point1, point7, &nowColor);
		drawLine(point7, point8, &nowColor);
		drawLine(point8, point4, &nowColor);
		drawLine(point4, point1, &nowColor);

		// drawing side 2
		nowColor = colors.front();
		colors.pop_front();
		drawLine(point1, point2, &nowColor);
		drawLine(point2, point6, &nowColor);
		drawLine(point6, point7, &nowColor);
		drawLine(point7, point1, &nowColor);
	}
}
