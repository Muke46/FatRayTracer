
#include "Core/Vector.h"
#include <stdexcept>

// Default constructor that initializes a vector with all zeroes
Vector3::Vector3()
    : x(0.0f), y(0.0f), z(0.0f) {}

// Parameterized constructor
Vector3::Vector3(float x_, float y_, float z_)
    : x(x_), y(y_), z(z_) {}

// Vector addition
Vector3 Vector3::operator+(const Vector3 &other) const
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}

// Vector subtraction
Vector3 Vector3::operator-(const Vector3 &other) const
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

// Division
Vector3 Vector3::operator/(float scalar) const
{
    if (scalar == 0.0f)
    {
        throw std::invalid_argument("Division by zero in Vector3.");
    }
    return Vector3(x / scalar, y / scalar, z / scalar);
}

// Multiplication
Vector3 Vector3::operator*(float coefficient) const
{
    return Vector3(x * coefficient, y * coefficient, z * coefficient);
}

// Length calculation
float Vector3::getLength() const
{
    return std::sqrt(x * x + y * y + z * z);
}

// Dot product
float Vector3::dot(const Vector3 &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

// Cross product
Vector3 Vector3::cross(const Vector3 &other) const
{
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x);
}