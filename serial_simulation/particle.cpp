#include "particle.h"
#include <iostream>
#include <cmath>

Particle::Particle(double m, double *p, double *v, double *walls)
{
    mass = m;
    std::copy(p, p + 3, pos);
    std::copy(v, v + 3, vel);
    std::copy(walls, walls + 3, boundary);
}

void Particle::updatePos(double dt)
{
    pos[0] += vel[0]; // normal coord updates
    pos[1] += vel[1];
    pos[2] += vel[2];

    for (int i = 0; i < 3; i++) // bounding box reflection
    {
        if (pos[i] < 0)
        {
            pos[i] *= -1.0;
            vel[i] = abs(vel[i]);
        }
        if (pos[i] > boundary[i])
        {
            pos[i] = 2 * boundary[i] - pos[i];
            vel[i] = -1.0 * abs(vel[i]);
        }
    }
}

void Particle::updateVel(double inflM, double *inflPos, double dt)
{
    double x = inflPos[0] - pos[0];
    double y = inflPos[1] - pos[1];
    double z = inflPos[2] - pos[2];
    double r = sqrt(x * x + y * y + z * z);
    double sigma = getSigma(inflM);
    double epsilon = getEpsilon(inflM);
    double f = -24.0 * epsilon * (2.0 * pow(sigma, 12.0) / pow(r, 14.0) - pow(sigma, 6.0) / pow(r, 8.0));
    vel[0] += x * f * dt;
    vel[1] += y * f * dt;
    vel[2] += z * f * dt;
}

double Particle::getSigma(double inflM)
{
    double returnable;
    mass != inflM ? returnable = 2.0 : mass == 1.0 ? returnable = 1.0
                                                   : returnable = 3.0;
    return returnable;
}

double Particle::getEpsilon(double inflM)
{
    double returnable;
    mass != inflM ? returnable = 15.0 : mass == 1.0 ? returnable = 3.0
                                                    : returnable = 60.0;
    return returnable;
}