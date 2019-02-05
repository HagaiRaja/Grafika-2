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
				} while ((p.x != q.x) && (p.y != q.y));
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
				} while ((p.x != q.x) && (p.y != q.y));
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
				} while ((p.x != q.x) && (p.y != q.y));
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
				} while ((p.x != q.x) && (p.y != q.y));
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
				} while ((p.x != q.x) && (p.y != q.y));
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
				} while ((p.x != q.x) && (p.y != q.y));
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
				} while ((p.x != q.x) && (p.y != q.y));
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
				} while ((p.x != q.x) && (p.y != q.y));
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
 
// drawing a picture by given dots and color from filename
// and draw it relatively from given center point
// for file specs open sample.txt
void drawPicture (string filename, point center)
{
	string line;
	ifstream imageFile;
	imageFile.open(filename, ios::in);
	if (imageFile.is_open())
	{
		int r,g,b,a;

		imageFile >> r >> g >> b >> a;
		color c = {(unsigned char) r, (unsigned char) g, (unsigned char) b, (unsigned char) a};
		// cout << r << " " << g << " " << b << " " << a << endl;
		double dx, dy;
		point now, prev, first;
		// first point
		imageFile >> dx >> dy;
		now.x = center.x + dx;
		now.y = center.y + dy;
		first = now;
		do {
			// read new point
			imageFile >> dx >> dy;

			// draw line
			if (dx == 9999) {
				// end of line
				drawLine(now, first, &c);
			}
			else {
				// updating point
				prev = now;	
				now.x = center.x + dx;
				now.y = center.y + dy;
				drawLine(prev, now, &c);
			}
		} while (dx != 9999);
		

		imageFile.close();
	}
	else cout << "Unable to open file"; 
}