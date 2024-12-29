#include "RTimpl/Core/Sphere.h"
#include "RTimpl/Core/Ray.h"

#include <stdexcept>

// Constructor
Sphere::Sphere(Vector3 Origin_, float radius_)
    : Origin(Origin_), radius(radius_) { emissivity = 0.0f; }

// Check intersection
bool Sphere::Intersect(const Ray3 &ray, Ray3 &reflection) const {
    // Calculate the vector from the ray origin to the sphere center
    Vector3 L = Origin - ray.origin; // Sphere's center - Ray's origin

    // Calculate the projection of L onto the ray direction
    float tc = dot(L, ray.direction);

    // Check if the sphere is behind the ray
    if (tc < 0.0f)
        return false; // The sphere is behind the ray

    // Calculate the squared distance from the sphere center to the projection point
    float d2 = dot(L, L) - tc * tc;

    // Check if the distance squared is greater than the radius squared
    float radius2 = radius * radius;
    if (d2 > radius2)
        return false; // No intersection

    // Calculate the distance from the projection point to the intersection points
    float t1c = sqrt(radius2 - d2); // Distance from the projection to the intersection points

    // Calculate the intersection points
    float t1 = tc - t1c; // First intersection point
    float t2 = tc + t1c; // Second intersection point

    // Choose the closest positive intersection point
    Vector3 intersection = Vector3();
    if (t1 > 0) {
        intersection = ray.origin + ray.direction * t1; // First intersection point
    } else if (t2 > 0) {
        intersection = ray.origin + ray.direction * t2; // Second intersection point
    } else {
        return false; // Both intersections are behind
    }

    // Calculate the normal
    Vector3 normal = intersection - Origin;

    // Specular reflection ray
    Vector3 direction = ray.direction - normal * (2 * dot(ray.direction, normal));

    // Add roughness
    Vector3 randomDirection = getRandomDirection() * roughness;
    direction = direction + randomDirection;

    // // If the dot product between the random vector and the normal is negative, flip it so it points outwards
    if (dot(normal, direction) < 0) {
        direction = direction * -1;
    }

    direction = normalize(direction);

    reflection.origin = intersection + direction * 1e-6;
    reflection.direction = direction;

    reflection.color = ray.color * color;

    return true; // Intersection occurred
}
