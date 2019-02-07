#include "explosion.h"

// Default constructor
Explosion::Explosion() {
    duration = 0;
}

// Constructor with variables defined
Explosion::Explosion(point _center, color _colour, double duration) : Object(_center, _colour) {
    duration = 3;
}

void Explosion::draw() {

}

void Explosion::setDuration(std::chrono::milliseconds i) {
    duration = i;
}

void Explosion::getDuration() const {
    return duration;
}