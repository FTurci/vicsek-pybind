#include "particle.hpp"
Particle::Particle()
{
    // initialise with zeros
    this->x = 0.0;
    this->y = 0.0;
    this->theta = 0.0;
    this->v = 1.0;
    this->radius = 1.0; // default radius is 1.0

}

std::string Particle::to_string()
{
    return std::to_string(x) + " " + std::to_string(y) + " " +
               std::to_string(theta);
}


