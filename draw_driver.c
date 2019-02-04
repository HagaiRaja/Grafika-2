#include "draw.h"

int main(int argc, char const *argv[])
{
	/* code */
	init();

	color black = {0,0,0,255};
	color white = {255,255,255,0};
	set_background(&white);

	point a = {300,300};
	point b = {300,200};
	point c = {400,200};
	point d = {400,300};
	point e = {400,400};
	point f = {300,400};
	point g = {200,400};
	point h = {200,300};
	point i = {200,200};
	drawLine(a, b, &black);
	drawLine(a, c, &black);
	drawLine(a, d, &black);
	drawLine(a, e, &black);
	drawLine(a, f, &black);
	drawLine(a, g, &black);
	drawLine(a, h, &black);
	drawLine(a, i, &black);


	point j = {350,200};
	point k = {400,250};
	point l = {400,350};
	point m = {350,400};
	point n = {250,400};
	point o = {200,350};
	point p = {200,250};
	point q = {250,200};
	drawLine(a, j, &black);
	drawLine(a, k, &black);
	drawLine(a, l, &black);
	drawLine(a, m, &black);
	drawLine(a, n, &black);
	drawLine(a, o, &black);
	drawLine(a, p, &black);

	close_buffer();
	return 0;
}