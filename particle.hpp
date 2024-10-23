#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "box.hpp"


class Particle{
    public:
        // position
        double x;
        double y;
        // orientation
        double theta;

        // `velocity
        double v;
        // radius of interaction
        double radius;

        // methods
        Particle ();
        std::string to_string();
};






#endif