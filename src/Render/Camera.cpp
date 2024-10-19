#include "Render/Camera.h"
#include "Utils/Color.h"
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

    std::vector<Color> pixels;
    pixels.resize(width * height);
    pixels = pixelBuffer.getPixels(); // Get the colors

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

            int maxReflections = 10;

            // A ray is considered done when a light is hit or no objects have been hit
            bool hit;
            bool lightHit = false;
            float minDistance = std::numeric_limits<float>::max(); //max max super max?
            Ray3 closestObjectReflection;
            int closestObjectIndex = 0;

            // TODO add distance checking so the objects are not rendered out of order

            for (int i = 0; i < maxReflections; i++)
            {
                hit = false;

                // Loop through all the object
                for (size_t j = 0; j < objects.size(); j++)
                {

                    if (objects[j]->Intersect(ray, reflection) == true)
                    {
                        float distance = (reflection.origin - ray.origin).getLength();
                        if (distance < minDistance){
                            minDistance = distance;
                            closestObjectReflection = reflection;
                            closestObjectIndex = j;
                        }
                        hit = true;
                    }
                }
                if (hit) {
                    ray = closestObjectReflection;
                    if (objects[closestObjectIndex]->emissivity > 0.0f) {
                        lightHit = true;
                        break;
                    }
                }
            }
            if (lightHit == true){
            pixelBuffer.setPixel(x, y, ray.color);
            }
        }
    }
}