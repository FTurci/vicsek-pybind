#include <iostream>
#include "system.hpp"


using namespace std;


int main(){

    puts("* Starting simulation... *");

    int N = 100;
    double L = 20;
    double dt = 0.5; 
    double noise = 0.05;  
    // initialise the system
    System system(N, L,dt,noise);
    system.random_start();
    system.save_config("test.xyz");
    system.print_status();
    for (size_t i = 0; i < 100000; i++)
    {   std::cout <<i << std::endl;
        system.update();
    }
    
    puts("* End. *");
    return 0;
}