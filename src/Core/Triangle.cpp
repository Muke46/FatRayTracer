#include "Core/Vector.h"
#include "Core/Triangle.h"
#include "Core/Ray.h"
#include <stdexcept>

// Constructor
Triangle3::Triangle3(Vector3 v0_, Vector3 v1_, Vector3 v2_)
    : v0(v0_), v1(v1_), v2(v2_) {
        n = cross(v1_ - v0_, v2_ - v0_);
    }

// Check intersection

bool Triangle3::Intersect(const Ray3& ray, Ray3& reflection) const
{
    float normal_dot_dir = dot(n, ray.direction);

    // Check if the line is parallel to the plane
    if (normal_dot_dir < 1e-6) {
        return false;
    }
    
    // Compute the independent value (t) of the line's formula at the intersection
    // with the plane
    float t = dot(n, v0 - ray.origin) / normal_dot_dir;

    // If t is negative, the intersection point is behind the origin
    if (t < 0) {
        return false;
    }

    // Calculate the intersection point
    Vector3 intersection = Vector3(ray.origin + ray.direction * t);
    
    //Edges tests to check if the intersection point is inside the triangle
    Vector3 edge0 = v1 - v0;
    Vector3 c0 = intersection - v0;
    if (dot(n, cross(edge0, c0)) < 0) return false;

    Vector3 edge1 = v2 - v1;
    Vector3 c1 = intersection - v1;
    if (dot(n, cross(edge1, c1)) < 0) return false;
    
    Vector3 edge2 = v0 - v2;
    Vector3 c2 = intersection - v2;
    if (dot(n, cross(edge2, c2)) < 0) return false;

    // If all the checks fails, the ray intersects the triangle
    return true;
}