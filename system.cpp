#include "system.hpp"
#include <random>
#include <fstream>
   
System::System(int nparticles,double side,double dt,double noise)
{
    this->nparticles = nparticles;
    this->side = side;
    this->dt = dt;
    this->noise = noise;
    this->particles.resize(nparticles);
    // random number generator
    std::random_device rd;  
    this->gen = std::mt19937(rd());
    // box
    this->box.set_side(side);

}

void System::random_start()
{
    for (Particle &p : particles){
        p.x = gen_uniform(0,this->box.get_side());
        p.y = gen_uniform(0,this->box.get_side());
        p.theta = gen_uniform(0,2*M_PI);
    }
}

void System::update()
{ 
    // implement the Vicsek model dynamics

    std::vector<double> new_theta(nparticles);
    double L = box.get_side();

    #pragma omp parallel for
    for (int i = 0; i < nparticles; i++){

        int count = 1;
        double cos = std::cos(particles[i].theta);
        double sin = std::sin(particles[i].theta);
        
        for (int j = 0 ; j < nparticles; j++){

            if (i!=j){
                // calculate distance
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;

                if(dx>L*0.5) dx-=L;
                if(dx<-L*0.5) dx+=L;
                if(dy>L*0.5) dy-=L;
                if(dy<-L*0.5) dy+=L;
                
                // calculate the distance between the two particles
                double dist = std::sqrt(dx*dx + dy*dy);
            
                // check if the distance is below the interaction radius
                if (dist < particles[i].radius){
                    // calculate the new orientation
                    cos +=  std::cos(particles[j].theta);
                    sin +=  std::sin(particles[j].theta);
                    count+=1;
                }
  
            }
        }
        
        cos /= count;
        sin /= count;
        // average + noise
        double avg_theta = std::atan2(sin, cos);
        new_theta[i] = avg_theta + noise*gen_uniform(-M_PI,M_PI);
    }
    // move the particles
    for (int i = 0; i < nparticles; i++){
        particles[i].x += std::cos(new_theta[i])*particles[i].v*dt;
        particles[i].y += std::sin(new_theta[i])*particles[i].v*dt;
        particles[i].theta = new_theta[i];
        // periodic boundaries
        if (particles[i].x >L) particles[i].x -=L;
        if (particles[i].x <0) particles[i].x += L;
        if (particles[i].y >L) particles[i].y -=L;
        if (particles[i].y <0) particles[i].y += L;
    }

    
}

void System::print_status()
{   puts("=== System status: ");
    std::cout<<" number of particles: "<<this->particles.size()<<std::endl;
    std::cout<<" side: "<<this->side<<std::endl;
    std::cout<<" time step: "<<this->dt<<std::endl;
    
}

double System::gen_uniform(double min, double max)
{   
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(gen); // Generate a random number

    
}
std::vector <std::vector <double>>  System::get_config(){
    std::vector <std::vector <double>> config;
    for (const Particle &p : this->particles){
        config.push_back({p.x, p.y, p.theta});
    }
    return config;

}
void System::save_config(const std::string &filename)
{   
    std::ofstream out_file(filename);
    if (!out_file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return; // Exit if file cannot be opened
    }
    out_file << std::to_string(particles.size())+"\nParticles"<<std::endl;
    // Write particle properties to the file
    for (size_t i = 0; i < particles.size(); ++i) {
        out_file << i << " " << particles[i].to_string() << std::endl;
    }
    out_file.close(); // Close the file
    
}
