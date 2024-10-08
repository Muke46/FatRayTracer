#ifndef RAY_H
#define RAY_H

#include "Vector.h"

class Ray3
{
    public:

    // Default constructor
    Ray3();

    // Parametric constructor
    Ray3(Vector3 origin_, Vector3 direction_);

    Vector3 getOrigin() const;
    Vector3 getDirection() const;

    void setOrigin(const Vector3& origin);
    void setDirection(const Vector3& direction);

    private:
    
    // The direction should be normalized
    Vector3 m_origin, m_direction;

};

#endif // RAY_H