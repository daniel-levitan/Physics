#include <assert.h>
//  #include <cyclone/particle.h>
#include "../../include/core/particle.h"
// #include "../../include/core/precision.h"

using namespace physicsEngine;

void Particle::integrate(real duration)
{
    assert(duration > 0.0);
    // Update linear position.

    position.addScaledVector(velocity, duration);
    
    // Work out the acceleration from the force.
    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);
    
    // Update linear velocity from the acceleration.
    velocity.addScaledVector(resultingAcc, duration);

    // Impose drag.
    velocity *= real_pow(damping, duration);
}

void Particle::setMass(const real mass)
{
    assert(mass != 0);
    Particle::inverseMass = ((real)1.0)/mass;
}

void Particle::getPosition(Vector3 *position) const 
{
    *position = this->position;
}

void Particle::setDamping(const real damping)
{
    Particle::damping = damping;
}

void Particle::setVelocity(const real x, const real y, const real z)
{
    velocity.x = x;
    velocity.y = y;
    velocity.z = z;
}

void Particle::setAcceleration(const real x, const real y, const real z)
{
    acceleration.x = x;
    acceleration.y = y;
    acceleration.z = z;
}

void Particle::setPosition(const real x, const real y, const real z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void Particle::clearAccumulator()
{
    forceAccum.clear();
}