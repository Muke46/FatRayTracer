//
// Created by p4nzer96 on 30/12/24.
//

#ifndef RS_CUBE_H
#define RS_CUBE_H

#include <RSimpl/Core/Vector.h>

namespace rs{
    class Cube{
        public:

            Vector origin;
            float size;

            Cube(Vector origin_, float size_);
    /*private:
        // TODO: Maybe using a vector of Vectors is more convenient (But pnz knows only C-types vectors rn)
        Vector v000{};
        Vector v001{};
        Vector v010{};
        Vector v011{};
        Vector v100{};
        Vector v101{};
        Vector v110{};
        Vector v111{};*/
    };

};

#endif //RS_CUBE_H
