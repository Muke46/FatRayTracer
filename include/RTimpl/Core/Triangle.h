#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "RTimpl/Core/SceneObject.h"
#include "RTimpl/Core/Vector.h"
#include "RTimpl/Core/Ray.h"

class Triangle3 : public SceneObject {
public:
    // Vertexes
    Vector3 v0, v1, v2;

    //Normal vector
    Vector3 n;

    // Declaration of the constructor
    Triangle3(Vector3 v0_, Vector3 v1_, Vector3 v2_);

    bool Intersect(const Ray3 &ray, Ray3 &reflection) const override;
};

#endif // TRIANGLE_H
