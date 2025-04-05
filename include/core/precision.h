#ifndef PRECISION_H
#define PRECISION_H

// #include <float.h>
#include <math.h>

namespace physicsEngine {
    typedef float real;

    /** Defines the precision of the square root operator. */ 
    #define real_sqrt sqrtf

    /** Defines the precision of the power operator. */
    #define real_pow powf

    
}

#endif