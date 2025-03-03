#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
public:
    double mass;   // particle's mass
    double pos[3]; // particle's position
    double vel[3]; // particle's velocity

    Particle(double m, double *pos, double *vel); // initializor

    void updatePos(double dt); // change position of particle

    void updateVel(double inflM, double inflPos); //

    double getSigma(double inflM);

    double getEpsilon(double inflM);
};

#endif
