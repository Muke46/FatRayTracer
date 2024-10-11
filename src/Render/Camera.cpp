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

    // For each pixel
    for (unsigned int y = 0; y < yResolution; ++y)
    {
        for (unsigned int x = 0; x < xResolution; ++x)
        {
            // Loop through all the triangles
            for (size_t i = 0; i < triangles.size(); ++i)
            {
                // Create a ray
                Vector3 RayOrigin(
                    origin.x + x - xResolution / 2,
                    origin.y + y - yResolution / 2,
                    origin.z + focalLength);

                // Perspective
                Vector3 RayDirection(
                    (float) x - xResolution / 2,
                    (float) y - yResolution / 2,
                    focalLength);

                // Orthogonal
                // Vector3 RayDirection(
                //     0.0f,
                //     0.0f,
                //     1.0f);

                Ray3 ray = Ray3(RayOrigin, RayDirection);

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