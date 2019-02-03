#include <stdio.h>

int main(int argc, char const *argv[])
{
	unsigned short a = 2, b = 2;
	double e = a, f = b;
	double c = e / f;


	if (c == 1)
	{
		/* code */
		printf("%lf\n", c);
	}
	return 0;
}