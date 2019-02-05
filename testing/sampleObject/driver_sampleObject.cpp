#include "sample_object.h"
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
	init();

	list<Object*> ListObject;

	point center = {400,400};
	color black = {0,0,0,0};
	color white = {255,255,255,0};
	set_background(&black);

	SampleObject* a = new SampleObject(center, white, 1, 2);
	SampleObject* b = new SampleObject(center, white, -1, 2);
	SampleObject* c = new SampleObject(center, white, 1, -2);

	ListObject.push_front(a);
	ListObject.push_front(b);
	ListObject.push_front(c);

	while (1) {
		// DRAWING THE Koin
        for (list<Object*>::iterator it=ListObject.begin(); it!=ListObject.end(); ++it)
    	(*it)->draw();
    	set_background(&black);
	}

	
	close_buffer();
	return 0;
}