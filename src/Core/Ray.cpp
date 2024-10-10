#include "Core/Ray.h"
#include <stdexcept>

// Default constructor
Ray3::Ray3()
    : m_origin(Vector3(0.0f, 0.0f, 0.0f)),
      m_direction(Vector3(0.0f, 0.0f, 1.0f)) // Default direction along +Z axis
{
}

// Parameterized constructor
Ray3::Ray3(Vector3 origin, Vector3 direction)
    : m_origin(origin)
{
    // Ensure the direction is normalized
    float length = direction.getLength();
    if (length == 0.0f)
    {
        throw std::invalid_argument("Ray direction vector cannot be zero.");
    }
    m_direction = direction / length;
}

Vector3 Ray3::getOrigin() const
{
    return m_origin;
}

Vector3 Ray3::getDirection() const
{
    return m_direction;
}

void Ray3::setOrigin(const Vector3& origin) {
    m_origin = origin;
}

void Ray3::setDirection(const Vector3& direction) {
    float length = direction.getLength();
        if (length == 0.0f) {
            throw std::invalid_argument("Ray direction vector cannot be zero.");
        }
        m_direction = direction / length;
}