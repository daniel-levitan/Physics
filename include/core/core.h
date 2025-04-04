#ifndef CORE_H
#define CORE_H

#include "precision.h"

namespace physicsEngine {
    class Vector3
    {
    public:
        real x;
        real y;
        real z;

    private:
        /** Padding to ensure 4-word alignment. */
        real pad [[maybe_unused]];; /*Explicitly telling the compiler I won't use it*/

    public:
        Vector3() : x(0), y(0), z(0), pad(0) {}
        Vector3(const real x, const real y, const real z)
             : x(x), y(y), z(z), pad(0) {}

        void invert()
        {
            x = -x;
            y = -y;
            z = -z;
        }

        /** Gets the magnitude of this vector. */
        real magnitude() const
        {
            return real_sqrt(x*x+y*y+z*z);
        }

    };

}

#endif