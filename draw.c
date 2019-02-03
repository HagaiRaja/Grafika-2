#include "draw.h"

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
	// int px = p.x, py = p.y, qx = q.x, qy = q.y;
	// int distX, distY;
	// do {
	// 	distX = px - qx;
	// 	distY = py - qy;
	// 	if (absolute(distX) > absolute(distY)) {
	// 		if (distX > 0) {

	// 		}
	// 	}
	// 	else {

	// 	}
	// } while (px != qx && py != qy);
	double px = p.x, py = p.y, qx = q.x, qy = q.y;
	double temp;
	
	if (p.x == q.x) { // infinity margin
		if (p.y > q.y) {
			for (unsigned short i = 0; i < absolute(py - qy); ++i)
			{
				/* code */
				draw_dot(p.x, p.y-i, c);
			}
		}
		else {
			for (unsigned short i = 0; i < absolute(py - qy); ++i)
			{
				/* code */
				draw_dot(p.x, p.y+i, c);
			}
		}
	}
	else {
		double margin = (py - qy)/(px - qx);
		if (margin > 1) {
			double newMargin = 1 / margin;
			temp = newMargin;

			draw_dot(p.x, p.y, c);
			if (p.y > q.y) {
				do {
					p.y -= 1;
					if (temp > 1) {
						temp -= 1;
						p.x -= 1;
					}
					temp += newMargin;
					draw_dot(p.x, p.y, c);
				} while (p.x != q.x && p.y != q.y);
			}
			else {
				do {
					p.y += 1;
					if (temp > 1) {
						temp -= 1;
						p.x += 1;
					}
					temp += newMargin;
					draw_dot(p.x, p.y, c);
				} while (p.x != q.x && p.y != q.y);
			}
		}
		else if (margin < -1) {
			double newMargin = 1 / margin;
			temp = newMargin;

			draw_dot(p.x, p.y, c);
			if (p.y > q.y) {
				do {
					p.y -= 1;
					if (temp < -1) {
						temp += 1;
						p.x += 1;
					}
					temp += newMargin;
					draw_dot(p.x, p.y, c);
				} while (p.x != q.x && p.y != q.y);
			}
			else {
				do {
					p.y += 1;
					if (temp < -1) {
						temp += 1;
						p.x -= 1;
					}
					temp += newMargin;
					draw_dot(p.x, p.y, c);
				} while (p.x != q.x && p.y != q.y);
			}
		}
		else if (margin == 1) {
			if (p.y > q.y) {
				for (unsigned short i = 0; i < absolute(py - qy); ++i)
				{
					/* code */
					draw_dot(p.x-i, p.y-i, c);
				}
			}
			else {
				for (unsigned short i = 0; i < absolute(py - qy); ++i)
				{
					/* code */
					draw_dot(p.x+i, p.y+i, c);
				}
			}
		}
		else if (margin == -1) {
			if (p.y > q.y) {
				for (unsigned short i = 0; i < absolute(py - qy); ++i)
				{
					/* code */
					draw_dot(p.x+i, p.y-i, c);
				}
			}
			else {
				for (unsigned short i = 0; i < absolute(py - qy); ++i)
				{
					/* code */
					draw_dot(p.x-i, p.y+i, c);
				}
			}
		}
		else if (margin > -1 && margin < 0) {
			temp = margin;

			draw_dot(p.x, p.y, c);
			if (p.y > q.y) {
				do {
					p.x += 1;
					if (temp < -1) {
						temp += 1;
						p.y -= 1;
					}
					temp += margin;
					draw_dot(p.x, p.y, c);
				} while (p.x != q.x && p.y != q.y);
			}
			else {
				do {
					p.x -= 1;
					if (temp < -1) {
						temp += 1;
						p.y += 1;
					}
					temp += margin;
					draw_dot(p.x, p.y, c);
				} while (p.x != q.x && p.y != q.y);
			}
		}
		else if (margin < 1 && margin > 0) {
			temp = margin;

			draw_dot(p.x, p.y, c);
			if (p.y > q.y) {
				do {
					p.x -= 1;
					if (temp > 1) {
						temp -= 1;
						p.y -= 1;
					}
					temp += margin;
					draw_dot(p.x, p.y, c);
				} while (p.x != q.x && p.y != q.y);
			}
			else {
				do {
					p.x += 1;
					if (temp > 1) {
						temp -= 1;
						p.y += 1;
					}
					temp += margin;
					draw_dot(p.x, p.y, c);
				} while (p.x != q.x && p.y != q.y);
			}
		}
		else { // margin 0 
			if (p.x > q.x) {
				for (unsigned short i = 0; i < absolute(px - qx); ++i)
				{
					/* code */
					draw_dot(p.x-i, p.y, c);
				}
			}
			else {
				for (unsigned short i = 0; i < absolute(px - qx); ++i)
				{
					/* code */
					draw_dot(p.x+i, p.y, c);
				}
			}
		}
	}
	
	// unsigned char direction; 
	// /* from p to q value between 
	//  1. east 			5. west
	//  2. southeast		6. northwest
	//  3. south 			7. north 
	//  4. southwest		8. northeast
	// */

	// if (p.x > q.x) 
	// {
	// 	if (p.y > q.y) {
	// 		direction = 4;
	// 		margin = 
	// 	}
	// 	else if (p.y == q.y) {
	// 		direction = 5;
	// 	}
	// 	else {
	// 		direction = 6;
	// 	}
	// }
	// else if (p.x == q.x) 
	// {
	// 	if (p.y > q.y) {
	// 		direction = 3;
	// 	}
	// 	else {
	// 		direction = 7;
	// 	}
	// }
	// else // (p.x < q.x) 
	// {
	// 	if (p.y > q.y) {
	// 		direction = 2;
	// 	}
	// 	else if (p.y == q.y) {
	// 		direction = 1;
	// 	}
	// 	else {
	// 		direction = 8;
	// 	}
	// }
}
 
// Drawing Canon with given center point with line color c
void drawCanon(point center, color* c)
{

}

// Drawing Bullet with given center point with line color c
void drawBullet(point center, color* c)
{

}

// Drawing Plane with given center point with line color c
void drawPlane(point center, color* c)
{

}