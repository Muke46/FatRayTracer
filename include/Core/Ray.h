#ifndef RAY_H
#define RAY_H

#include "Vector.h"

class Ray3
{
    public:
    
    Vector3 origin, direction;

    // Default constructor
    Ray3();

    // Parametric constructor
    Ray3(Vector3 origin_, Vector3 direction_);

    void setDirection(const Vector3& direction_);

};

#endif // RAY_H