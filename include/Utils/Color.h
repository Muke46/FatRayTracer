#ifndef COLOR_H
#define COLOR_H

class Color {
    public:

        unsigned char r, g, b, a;

        // Default constructor
        Color();

        // Parametric constructor
        Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
        
};

#endif // COLOR_H