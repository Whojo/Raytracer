#include <iostream>

#include "color.hpp"
#include "engine.hpp"
#include "image.hpp"
#include "scene.hpp"
#include "sphere.hpp"
#include "texture_material.hpp"

int main(int argc, char *argv[])
{
    UniformTexture blue_text{ Texture{ Color{ 146, 194, 182 }, 7, 0.5, 0.6 } };
    UniformTexture white_text{ Texture{ Color{ 232, 236, 196 }, 0, 0.4, 0.6 } };
    UniformTexture orange_text{ Texture{ Color{ 236, 147, 106 }, 5, 0.4, 0.6 } };
    UniformTexture yellow_text{ Texture{ Color{ 213, 166, 50 }, 7, 0, 1 } };

    Scene scene{
        std::vector<std::shared_ptr<Object>>{
            std::make_shared<Sphere>(Point{ 0, 0, -10000 }, 10000, white_text),
            std::make_shared<Sphere>(Point{ 10, 2, 1.5 }, 2, blue_text),
            std::make_shared<Sphere>(Point{ 13, -2, 2 }, 4, orange_text),
            std::make_shared<Sphere>(Point{ 20, 6, 3 }, 8, yellow_text) },
        { PointLight{ Point{ 6, -2.00, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.96, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.92, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.88, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.84, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.80, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.76, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.72, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.68, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.64, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.60, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.56, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.52, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.48, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.44, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.40, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.36, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.32, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.28, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.24, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.20, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.16, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.12, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.08, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.04, 5 }, 0.08 },
          PointLight{ Point{ 6, -1.00, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.96, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.92, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.88, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.84, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.80, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.76, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.72, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.68, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.64, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.60, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.56, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.52, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.48, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.44, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.40, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.36, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.32, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.28, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.24, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.20, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.16, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.12, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.08, 5 }, 0.08 },
          PointLight{ Point{ 6, -0.04, 5 }, 0.08 },
          PointLight{ Point{ 6, 0, 5 }, 0.15 } },
        Camera{ Point{ 0, 0, 5 }, Vector{ 1, 0, -0.2 }, Vector{ 0, 0, 1 }, 90,
                69, 1 }
    };

    auto img = engine::generate_image(352, 240, scene);
    img.save_to_ppm("test.ppm");

    return 0;
}
