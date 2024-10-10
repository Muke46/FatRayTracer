#include "Render/Camera.h"
#include <cstdio>

// Constructor
Camera3::Camera3(Vector3 origin_, Vector3 direction_, float focalLength_, float width_, float height_)
    : origin(origin_),
      direction(direction_),
      focalLength(focalLength_),
      width(width_),
      height(height_) {}

// Focal length
float Camera3::getFocalLength()
{
    return focalLength;
}
void Camera3::setFocalLength(float focalLength_)
{
    focalLength = focalLength_;
}

// Width
float Camera3::getWidth()
{
    return width;
}
void Camera3::setWidth(float width_)
{
    width = width_;
}

// Height
float Camera3::getHeight()
{
    return height;
}
void Camera3::setHeight(float height_)
{
    height = height_;
}

// Render
void Camera3::render(PixelBuffer &pixelBuffer, std::vector<Triangle3> triangles)
{
    int xResolution = pixelBuffer.getWidth();
    int yResolution = pixelBuffer.getHeight();

    float xStep = width / xResolution;
    float yStep = height / yResolution;

    // For each pixel
    for (unsigned int y = 0; y < yResolution; ++y)
    {
        for (unsigned int x = 0; x < xResolution; ++x)
        {
            // Loop through all the triangles
            for (size_t i = 0; i < triangles.size(); ++i)
            {
                // Create a ray

                Ray3 ray = Ray3(Vector3(x, y, 0.0f), Vector3(0.0f, 0.0f, 1.0f));

                // TODO!

                // Vector3 rayDirection = Vector3(
                //     xResolution / 2 * xStep - i * xStep - xStep / 2,
                //     yResolution / 2 * yStep - i * yStep - yStep / 2,
                //     focalLength);
                // Ray3 ray = Ray3(Vector3((float) x*xStep, (float) y*yStep, 0.0f), rayDirection);

                Vector3 intersection;

                // Check if the ray intersects with the triangle
                if (triangles[i].checkIntersect(ray, intersection) == true)
                {
                    Color color(
                        255,
                        255,
                        255,
                        0);
                    pixelBuffer.setPixel(x, y, color);
                }
            }
        }
    }
}