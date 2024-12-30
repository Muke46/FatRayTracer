#ifndef PixelBuffer_H
#define PixelBuffer_H

#include <vector>
#include <Utils/Color.h>

class PixelBuffer
{
public:
    unsigned int width, height;

    // Constructor
    PixelBuffer(unsigned int width_, unsigned int height_);

    // Get dimensions
    [[nodiscard]] unsigned int getWidth() const;
    [[nodiscard]] unsigned int getHeight() const;

    // Get pixels
    [[nodiscard]] const std::vector<Color> &getPixels() const;

    // Set pixel
    void setPixel(unsigned int x, unsigned int y, Color color);

    // Clear buffer
    void clearBuffer();

private:
    std::vector<Color> pixels;
};

#endif // PixelBuffer_H