#include <Utils/Color.h>

// Default constructor initialize a black color
Color::Color() : r(0), g(0), b(0), a(255) {}

// Parametric constructor
Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) :
    r(red), g(green), b(blue), a(alpha) {}

Color::Color(int red, int green, int blue, int alpha) :
    r(static_cast<unsigned char>(red)), g(static_cast<unsigned char>(green)), b(static_cast<unsigned char>(blue)),
    a(static_cast<unsigned char>(alpha)) {}

Color Color::operator+(const Color &other) const {
    unsigned char red = (r + other.r > 255) ? 255 : r + other.r;
    unsigned char green = (g + other.g > 255) ? 255 : g + other.g;
    unsigned char blue = (b + other.b > 255) ? 255 : b + other.b;
    unsigned char alpha = (a + other.a > 255) ? 255 : a + other.a;
    return Color(red, green, blue, alpha);
}

Color Color::operator*(const Color &other) const {
    unsigned char red = static_cast<unsigned char>(r) * other.r / 255;
    unsigned char green = static_cast<unsigned char>(g) * other.g / 255;
    unsigned char blue = static_cast<unsigned char>(b) * other.b / 255;
    unsigned char alpha = static_cast<unsigned char>(a) * other.a / 255;

    return Color(red, green, blue, alpha);
}

Color averageColors(const Color &color0, const Color &color1) {
    int red = static_cast<int>(color0.r) + static_cast<int>(color1.r);
    int green = static_cast<int>(color0.g) + static_cast<int>(color1.g);
    int blue = static_cast<int>(color0.b) + static_cast<int>(color1.b);
    int alpha = static_cast<int>(color0.a) + static_cast<int>(color1.a);

    return Color(static_cast<unsigned char>(static_cast<float>(red / 2)),
                 static_cast<unsigned char>(static_cast<float>(green / 2)),
                 static_cast<unsigned char>(static_cast<float>(blue / 2)),
                 static_cast<unsigned char>(static_cast<float>(alpha / 2)));
}
