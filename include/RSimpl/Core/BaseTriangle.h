//
// Created by p4nzer96 on 29/12/24.
//

#ifndef RS_TRIANGLE_H
#define RS_TRIANGLE_H

#include <Utils/Color.h>
#include <RSimpl/Core/Vector.h>
#include <RSimpl/Core/SceneObject.h>

namespace rs{
    class Triangle : public SceneObject {
        public:

            // Vertexes
            Vector v0, v1, v2;

            // Normal Vector
            Vector n;

            //Declaration of the constructor
            Triangle(Vector v0_, Vector v1_, Vector v2_);


    };
};

#endif //RS_TRIANGLE_H
