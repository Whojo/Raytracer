#pragma once

#include <vector>

#include "object.hpp"
#include "light.hpp"
#include "camera.hpp"


class Scene
{
public:
    std::vector<Sphere> objects; // XXX: Replace sphere by an object and fixed bug
    std::vector<Light> lights;
    const Camera camera;
};
