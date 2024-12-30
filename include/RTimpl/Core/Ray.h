#ifndef RAY_H
#define RAY_H

#include "RTimpl/Core/Vector.h"
#include "Utils/Color.h"

class Ray3 {
public:
    Vector3 origin, direction;

    Color color = Color(static_cast<unsigned char>(255),
                        static_cast<unsigned char>(255),
                        static_cast<unsigned char>(255),
                        static_cast<unsigned char>(0));

    // Default constructor
    Ray3();

    // Parametric constructor
    Ray3(Vector3 origin_, Vector3 direction_);

    void setDirection(const Vector3 &direction_);
};

#endif // RAY_H
