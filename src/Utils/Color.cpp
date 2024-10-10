
#include "Utils/Color.h"

// Default constructor initialize a black color
Color::Color()
    : r(0), g(0), b(0), a(255) {}

// Parametric constructor
Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    : r(red), g(green), b(blue), a(alpha) {}