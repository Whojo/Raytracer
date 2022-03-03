#pragma once

#include <vector>
#include <memory>

#include "object.hpp"
#include "light.hpp"
#include "camera.hpp"


class Scene
{
public:
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<Light> lights;
    const Camera camera;
};
