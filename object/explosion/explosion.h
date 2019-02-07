#ifndef CANON_H
#define CANON_H

#include "../object.h"
#include <chrono>

// A class to draw in screen

class Explosion : public Object {
    public :
        Explosion();
        Explosion(point _center, color _colour, std::chrono::milliseconds duration);

        // draw the object at the given center
        void draw();

        // Setter and Getter
        void setDuration(double i);
        double getDuration() const;
    
    private :
        // Duration of explosion to scale with draw function
        std::chrono::milliseconds duration;
};

#endif