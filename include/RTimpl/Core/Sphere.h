#ifndef SPHERE_H
#define SPHERE_H

#include "RTimpl/Core/SceneObject.h"
#include "RTimpl/Core/Vector.h"
#include "RTimpl/Core/Ray.h"

class Sphere : public SceneObject {
public:
    Vector3 Origin;

    float radius;

    float emissivity;

    // Declaration of the constructor
    Sphere(Vector3 Origin_, float radius_);

    bool Intersect(const Ray3 &ray, Ray3 &reflection) const override;
};

#endif // SPHERE_H
