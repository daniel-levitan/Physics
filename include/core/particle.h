#ifndef PARTICLE_H
#define PARTICLE_H

#include "core.h"

namespace physicsEngine 
{

    class Particle 
    {
    public:
        Vector3 position;
        Vector3 velocity;
        Vector3 acceleration;

        /**
         * Holds the amount of damping applied to linear motion. Damping is required to remove 
         * energy added through numerical instability in the integrator.
         * If the damping is zero, then the velocity will be reduced to nothing: this would mean that
         *  the object couldn’t sustain any motion without a force and would look odd to the player. 
         * A value of 1 means that the object keeps all its velocity (equivalent to no damping). 
         * If you don’t want the object to look like it is experiencing drag, then values near 
         * but less than 1 are optimal—0.995, for example.
        */
        real damping;

        /**
         * Holds the inverse of the mass of the particle. It is more useful to hold the 
         * inverse mass because integration is simpler and because in real-time simulation 
         * it is more useful to have objects with infinite mass (immovable) than zero mass
         * (completely unstable in numerical simulation).
         */
        real inverseMass;

        /**
         * Holds the accumulated force to be applied at the next
         * simulation iteration only. This value is zeroed at each
         * integration step.
         */
        Vector3 forceAccum;

        /**
         * Integrates the particle forward in time by the given amount.
         * This function uses a Newton-Euler integration method, which is a * linear approximation of the correct integral. For this reason it * may be inaccurate in some cases.
         */
        void integrate(real duration);


        void getPosition(Vector3 *position) const;
        
        void setPosition(const real x, const real y, const real z);
        void setMass(const real mass);
        void setDamping(const real damping);
        void setVelocity(const real x, const real y, const real z);
        void setAcceleration(const real x, const real y, const real z);

        void clearAccumulator();
        // void setVelocity(const Vector3 &velocity);
        // void setAcceleration(const Vector3 &acceleration);
    };

}

#endif