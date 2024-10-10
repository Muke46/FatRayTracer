#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Core/Vector.h"
#include "Core/Ray.h"

class Triangle3
{

public:

    // Vertexes
    Vector3 v0, v1, v2;

    //Normal vector
    Vector3 n;

    // Declaration of the constructor
    Triangle3(Vector3 v0_, Vector3 v1_, Vector3 v2_);

    // Checks if a ray intersects with the triangle
    bool checkIntersect(const Ray3& incomingVector, Vector3& intersectionPoint) const;

};

#endif // TRIANGLE_H