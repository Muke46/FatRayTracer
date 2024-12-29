#ifndef CAMERA_H
#define CAMERA_H

#include "RTimpl/Core/Vector.h"
#include "RTimpl/Core/Sphere.h"
#include "RTimpl/Render/PixelBuffer.h"
#include "RTimpl/Utils/Color.h"
#include <memory>

class Camera3 {
public:
    //Origin and direction
    Vector3 origin, direction;

    //Focal length
    float focalLength;

    // Canvas size
    float width, height;

    // Constructor
    Camera3(Vector3 origin_, Vector3 direction_, float focalLength_, float width_, float height_);

    void render(PixelBuffer &pixelBuffer, std::vector<std::shared_ptr<SceneObject> > &objects);
};

#endif // CAMERA_H
