#include "particle.h"
#include <iostream>

Particle::Particle(double m, double* p, double* v){
    mass = m;
    std::copy(p, p+3, pos);
    std::copy(v, v+3, vel);
}