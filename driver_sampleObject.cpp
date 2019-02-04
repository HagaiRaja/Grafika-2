#include "sample_object.h"
#include "LinkedList.hpp"

int main(int argc, char const *argv[])
{
	init();

	LinkedList<SampleObject> ListObject;

	point center = {400,400};
	color black = {0,0,0,0};
	color white = {255,255,255,0};
	set_background(&white);

	SampleObject a(center, black, 1, 2);
	SampleObject b(center, black, -1, 2);
	SampleObject c(center, black, 1, -2);

	ListObject.add(a);
	ListObject.add(b);
	ListObject.add(c);

	while (1) {
		// DRAWING THE Koin
        node<SampleObject> *o = ListObject.getFirst();
        int i = 0;
        while (o != NULL) {
            (o -> data).draw();
            point temp = (o -> data).getCenter();
            o = o -> next;
            i += 1;
        }
        set_background(&white);
	}

	
	close_buffer();
	return 0;
}