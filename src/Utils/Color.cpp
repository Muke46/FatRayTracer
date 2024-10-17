
#include "Utils/Color.h"


// Default constructor initialize a black color
Color::Color()
    : r(0), g(0), b(0), a(255) {}

// Parametric constructor
Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    : r(red), g(green), b(blue), a(alpha) {}

Color Color::operator+(const Color &other) const
{
    unsigned char red = (r + other.r > 255) ? 255 : r + other.r;
    unsigned char green = (g + other.g > 255) ? 255 : g + other.g;
    unsigned char blue = (b + other.b > 255) ? 255 : b + other.b;
    unsigned char alpha = (a + other.a > 255) ? 255 : a + other.a;
    return Color(red, green, blue, alpha);
}