#include "Render/Camera.h"
#include <cstdio>
#include <memory>

// Constructor
Camera3::Camera3(Vector3 origin_, Vector3 direction_, float focalLength_, float width_, float height_)
    : origin(origin_),
      direction(direction_),
      focalLength(focalLength_),
      width(width_),
      height(height_) {}

// Render
void Camera3::render(PixelBuffer &pixelBuffer, std::vector<std::shared_ptr<SceneObject>> &objects)
{
    int xResolution = pixelBuffer.getWidth();
    float xStep = width / xResolution;
    int yResolution = pixelBuffer.getHeight();
    float yStep = height / yResolution;

    // For each pixel
    for (unsigned int y = 0; y < yResolution; ++y)
    {
        for (unsigned int x = 0; x < xResolution; ++x)
        {
            // Create the first ray

            // Perspective
            Vector3 RayDirection(
                (float)x * xStep - xStep * xResolution / 2,
                (float)y * yStep - yStep * yResolution / 2,
                focalLength);

            // Orthogonal
            // Vector3 RayDirection(
            //     0.0f,
            //     0.0f,
            //     1.0f);

            Vector3 RayOrigin = origin;
            Ray3 ray = Ray3(RayOrigin, normalize(RayDirection));

            Ray3 reflection;

            int maxReflections = 5;

            int color = 0;

            for (int i = 0; i < maxReflections; i++)
            {

                bool hit = false;

                // Loop through all the object
                for (size_t j = 0; j < objects.size(); j++)
                {

                    if (objects[j]->Intersect(ray, reflection) == true)
                    {
                        ray = reflection;
                        if (j>1) color = color + 10;
                        else color = color + 1;
                        hit = true;
                    }
                }
                if (hit == false) break;
            }

            Color c(
                color,
                color,
                color,
                0);
            Color co = pixelBuffer.getPixels()[y * pixelBuffer.width + x];
            pixelBuffer.setPixel(x, y, co + c);
        }
    }
}