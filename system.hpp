#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <cstdint>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include "particle.hpp"
#include "box.hpp"
#include <omp.h> 


class System{
    public:
        // member variables
        int nparticles;
        double dt;
        double noise;
        Box box;

        std::vector<Particle> particles;
        // member functions
        System(int nparticles,double sidex, double sidey, double dt, double noise);

        // random initial condition
        void random_start();
        // evolve the system
        void update();

        // UTILITIES

        // print status
        void print_status();
        // uniform random number
        double gen_uniform(double min, double max);
        // get configuration as a table (vector of vector)
        std::vector <std::vector <double>>  get_config();

        // save configuration
        void save_config(const std::string &filename);



    private:
        std::mt19937 gen;  // Random number generator
};


#endif