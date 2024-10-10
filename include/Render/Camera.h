#ifndef CAMERA_H
#define CAMERA_H

#include "Core/Vector.h"
#include "Core/Triangle.h"
#include "Render/PixelBuffer.h"
#include "Utils/Color.h"

class Camera3
{
    public:

        //Origin and direction
        Vector3 origin, direction;

        //Focal length
        float focalLength;

        // Canvas size
        float width, height;

        // Constructor
        Camera3(Vector3 origin_, Vector3 direction_, float focalLength_, float width_, float height_);

        // Focal length
        float getFocalLength();
        void setFocalLength(float focalLength_);

        // get/set width
        float getWidth();
        void setWidth(float width_);

        // get/set height
        float getHeight();
        void setHeight(float height_);

        void render(PixelBuffer &pixelBuffer, std::vector<Triangle3> triangles);
};

#endif // CAMERA_H