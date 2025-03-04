#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <random>

class Vector3 {
    // The following members (attributes and methods) can be accessed from outside of the class
public:
    float x, y, z;

    // Default constructor
    Vector3();

    // Declaration of the constructor
    Vector3(float x_, float y_, float z_);

    // Overload for the sum operator
    // This operator takes reference to another Vector3
    // The const keywords are used because the sum operator doesn't modify the content of the Vectors
    Vector3 operator+(const Vector3 &other) const;

    // Overload for the subtraction operator
    Vector3 operator-(const Vector3 &other) const;

    // Overload for the division operator
    Vector3 operator/(float scalar) const;

    // Overload for the multiplication operator
    Vector3 operator*(float coefficient) const;

    // Method to calculate the length
    [[nodiscard]] float getLength() const;
};

// Function for the dot product
float dot(const Vector3 &v1, const Vector3 &v2);

// Function for the cross product
Vector3 cross(const Vector3 &v1, const Vector3 &v2);

Vector3 normalize(const Vector3 &v1);

Vector3 getRandomDirection();

#endif // VECTOR_H
