#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
public:
    double mass;        // particle's mass
    double pos[3];      // particle's position
    double vel[3];      // particle's velocity
    double boundary[3]; // bounding box

    Particle(double m, double *pos, double *vel, double *boundary); // initializor

    void updatePos(double dt); // change position of particle

    void updateVel(double inflM, double *inflPos, double dt); // update velocity based on one other particle

    double getSigma(double inflM); // get sigma (size) based on influencing particle

    double getEpsilon(double inflM); // get epsilon (energy) based on influecning particle
};

#endif
