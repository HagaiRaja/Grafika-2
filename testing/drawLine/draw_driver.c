#include "../../graphics/draw.hpp"

int main(int argc, char const *argv[])
{
	/* code */
	init();

	color black = {0,0,0,255};
	color white = {255,255,255,0};
	set_background(&black);

	double translateX = 300;
	double translateY = SCREEN_HEIGHT - 500;

	point a = {300 + translateX,300+ translateY};
	point b = {300 + translateX,200+ translateY};
	point c = {400 + translateX,200+ translateY};
	point d = {400 + translateX,300+ translateY};
	point e = {400 + translateX,400+ translateY};
	point f = {300 + translateX,400+ translateY};
	point g = {200 + translateX,400+ translateY};
	point h = {200 + translateX,300+ translateY};
	point i = {200 + translateX,200+ translateY};
	drawLine(a, b, &white);
	drawLine(a, c, &white);
	drawLine(a, d, &white);
	drawLine(a, e, &white);
	drawLine(a, f, &white);
	drawLine(a, g, &white);
	drawLine(a, h, &white);
	drawLine(a, i, &white);


	point j = {350 + translateX,200+ translateY};
	point k = {400 + translateX,250+ translateY};
	point l = {400 + translateX,350+ translateY};
	point m = {350 + translateX,400+ translateY};
	point n = {250 + translateX,400+ translateY};
	point o = {200 + translateX,350+ translateY};
	point p = {200 + translateX,250+ translateY};
	point q = {250 + translateX,200+ translateY};
	drawLine(a, j, &white);
	drawLine(a, k, &white);
	drawLine(a, l, &white);
	drawLine(a, m, &white);
	drawLine(a, n, &white);
	drawLine(a, o, &white);
	drawLine(a, p, &white);
	drawLine(a, q, &white);

	j = {375 + translateX,200+ translateY};
	k = {400 + translateX,250+ translateY};
	l = {400 + translateX,350+ translateY};
	m = {350 + translateX,400+ translateY};
	n = {250 + translateX,400+ translateY};
	o = {200 + translateX,350+ translateY};
	p = {200 + translateX,250+ translateY};
	q = {250 + translateX,200+ translateY};
	drawLine(a, j, &white);
	drawLine(a, k, &white);
	drawLine(a, l, &white);
	drawLine(a, m, &white);
	drawLine(a, n, &white);
	drawLine(a, o, &white);
	drawLine(a, p, &white);
	drawLine(a, q, &white);

	close_buffer();
	return 0;
}