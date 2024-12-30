//
// Created by p4nzer96 on 29/12/24.
//

#ifndef RS_VECTOR_H
#define RS_VECTOR_H

#include <cmath>
#include <random>

namespace rs {

class Vector {
    // The following members (attributes and methods) can be accessed from outside of the class
public:

    // x horizontal
    // y depth
    // z vertical

    float x, y, z;

    // Default constructor
    Vector();

    // Declaration of the constructor
    Vector(float x_, float y_, float z_);

    // Overload for the sum operator
    // This operator takes reference to another Vector3
    // The const keywords are used because the sum operator doesn't modify the content of the Vectors
    Vector operator+(const Vector &other) const;

    // Overload for the subtraction operator
    Vector operator-(const Vector &other) const;

    // Overload for the division operator
    Vector operator/(float scalar) const;

    // Overload for the multiplication operator
    Vector operator*(float coefficient) const;

    // Method to calculate the length
    [[nodiscard]] float getLength() const;
};

// Function for the dot product
float dot(const Vector &v1, const Vector &v2);

// Function for the cross product
Vector cross(const Vector &v1, const Vector &v2);

Vector normalize(const Vector &v1);

Vector getRandomDirection();

};

#endif //RS_VECTOR_H
