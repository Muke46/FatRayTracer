#include "Core/Triangle.h"
#include "Core/Ray.h"
#include <stdexcept>

// Constructor
Triangle3::Triangle3(Vector3 v0_, Vector3 v1_, Vector3 v2_)
    : v0(v0_), v1(v1_), v2(v2_) {
        n = (v1_ - v0_).cross(v2_ - v0_);
    }

// Check intersection

bool Triangle3::checkIntersect(const Ray3& incomingVector, Vector3& intersectionPoint) const
{
    float normal_dot_dir = n.dot(incomingVector.getDirection());

    // Check if the line is parallel to the plane
    if (normal_dot_dir < 1e-6) {
        return false;
    }
    
    // Compute the independent value (t) of the line's formula at the intersection
    // with the plane
    float t = n.dot(v0 - incomingVector.getOrigin()) / normal_dot_dir;

    // If t is negative, the intersection point is behind the origin
    if (t < 0) {
        return false;
    }

    // Calculate the intersection point
    intersectionPoint = incomingVector.getOrigin() + incomingVector.getDirection() * t;
    
    //Edges tests to check if the intersection point is inside the triangle
    Vector3 edge0 = v1 - v0;
    Vector3 c0 = intersectionPoint - v0;
    if (n.dot(edge0.cross(c0)) < 0) return false;

    Vector3 edge1 = v2 - v1;
    Vector3 c1 = intersectionPoint - v1;
    if (n.dot(edge1.cross(c1)) < 0) return false;
    
    Vector3 edge2 = v0 - v2;
    Vector3 c2 = intersectionPoint - v2;
    if (n.dot(edge2.cross(c2)) < 0) return false;

    // If all the checks fails, the ray intersects the triangle
    return true;
}