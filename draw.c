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
	point sudut1;
	sudut1.x = center.x - 20;
	sudut1.y = center.y - 50;
	point sudut2;
	sudut2.x = center.x + 20;
	sudut2.y = center.y - 50;
	point sudut3;
	sudut3.x = center.x - 20;
	sudut3.y = center.y + 50;
	point sudut4;
	sudut4.x = center.x + 20;
	sudut4.y = center.y + 50;
	point sudut5;
	sudut5.x = center.x - 10;
	sudut5.y = center.y - 100;
	point sudut6;
	sudut6.x = center.x + 10;
	sudut6.y = center.y - 100;
	drawLine(sudut1,sudut5,c);
	drawLine(sudut1,sudut3,c);
	drawLine(sudut3,sudut4,c);
	drawLine(sudut4,sudut2,c);
	drawLine(sudut2,sudut6,c);
	drawLine(sudut5,sudut6,c);
}

// Drawing Bullet with given center point with line color c
void drawBullet(point center, color* c)
{
	point sudut1;
	sudut1.x = center.x;
	sudut1.y = center.y - 25;
	point sudut2;
	sudut2.x = center.x - 20;
	sudut2.y = center.y - 10;
	point sudut3;
	sudut3.x = center.x - 15;
	sudut3.y = center.y + 20;
	point sudut4;
	sudut4.x = center.x + 15;
	sudut4.y = center.y + 20;
	point sudut5;
	sudut5.x = center.x + 20;
	sudut5.y = center.y - 10;
	drawLine(sudut1,sudut3,c);
	drawLine(sudut1,sudut4,c);
	drawLine(sudut2,sudut4,c);
	drawLine(sudut2,sudut5,c);
	drawLine(sudut3,sudut5,c);
}

// Drawing Plane with given center point with line color c
void drawPlane(point center, color* c)
{
	point sudut1;
	sudut1.x = center.x - 175;
	sudut1.y = center.y - 20;
	point sudut2;
	sudut2.x = center.x - 175;
	sudut2.y = center.y + 20;
	point sudut3;
	sudut3.x = center.x - 135;
	sudut3.y = center.y - 50;
	point sudut4;
	sudut4.x = center.x - 135;
	sudut4.y = center.y + 50;
	point sudut5;
	sudut5.x = center.x - 90;
	sudut5.y = center.y - 50;
	point sudut6;
	sudut6.x = center.x - 60;
	sudut6.y = center.y - 120;
	point sudut7;
	sudut7.x = center.x - 15;
	sudut7.y = center.y - 120;
	point sudut8;
	sudut8.x = center.x - 45;
	sudut8.y = center.y - 50;
	point sudut9;
	sudut9.x = center.x - 90;
	sudut9.y = center.y + 50;
	point sudut10;
	sudut10.x = center.x - 60;
	sudut10.y = center.y + 120;
	point sudut11;
	sudut11.x = center.x - 15;
	sudut11.y = center.y + 120;
	point sudut12;
	sudut12.x = center.x - 45;
	sudut12.y = center.y + 50;
	point sudut13;
	sudut13.x = center.x + 100;
	sudut13.y = center.y - 50;
	point sudut14;
	sudut14.x = center.x + 125;
	sudut14.y = center.y - 120;
	point sudut15;
	sudut15.x = center.x + 175;
	sudut15.y = center.y - 120;
	point sudut16;
	sudut16.x = center.x + 150;
	sudut16.y = center.y - 50;
	point sudut17;
	sudut17.x = center.x + 100;
	sudut17.y = center.y + 50;
	point sudut18;
	sudut18.x = center.x + 125;
	sudut18.y = center.y + 120;
	point sudut19;
	sudut19.x = center.x + 175;
	sudut19.y = center.y + 120;
	point sudut20;
	sudut20.x = center.x + 150;
	sudut20.y = center.y + 50;
	drawLine(sudut1,sudut2,c);
	drawLine(sudut1,sudut3,c);
	drawLine(sudut2,sudut4,c);
	drawLine(sudut3,sudut5,c);
	drawLine(sudut5,sudut6,c);
	drawLine(sudut6,sudut7,c);
	drawLine(sudut7,sudut8,c);
	drawLine(sudut8,sudut13,c);
	drawLine(sudut13,sudut14,c);
	drawLine(sudut14,sudut15,c);
	drawLine(sudut15,sudut16,c);
	drawLine(sudut4,sudut9,c);
	drawLine(sudut9,sudut10,c);
	drawLine(sudut10,sudut11,c);
	drawLine(sudut11,sudut12,c);
	drawLine(sudut12,sudut17,c);
	drawLine(sudut17,sudut18,c);
	drawLine(sudut18,sudut19,c);
	drawLine(sudut19,sudut20,c);
	drawLine(sudut16,sudut20,c);

}