#include "engine.hpp"

#include <iostream>

#include <cmath>
#include <exception>
#include <utility>

struct ImgPlan
{
    Point  top_left_corner;
    Vector delta_x;
    Vector delta_y;
};


const double pi = std::acos(-1);

static struct ImgPlan get_img_plan(const Camera &camera, int width, int height)
{
    if (are_colinear(camera.direction, camera.up))
        throw std::runtime_error("Not implemented yet...");

    auto unit_dir = camera.direction.as_unit();
    auto unit_up = camera.up.as_unit();

    auto img_plan_center = camera.center + unit_dir * camera.z_min;

    auto unit_x = cross_product(unit_up, unit_dir);
    auto unit_y = cross_product(unit_dir, unit_x);

    auto x_min = tan(camera.alpha / 2 * pi / 180) * 2 * camera.z_min;
    auto y_min = tan(camera.beta / 2 * pi / 180) * 2 * camera.z_min;

    auto top_left_corner = img_plan_center + unit_x * x_min / 2 + unit_y * y_min / 2;
    auto delta_x = -unit_x * x_min / width;
    auto delta_y = -unit_y * y_min / height;

    return ImgPlan{ top_left_corner, delta_x, delta_y };
}

static Point get_coords_on_image_plan(const struct ImgPlan &img_plan, size_t x, size_t y)
{
    return img_plan.top_left_corner + img_plan.delta_x * x + img_plan.delta_y * y;
}

static double add_lights_intensity(const double i1, const double i2)
{
    auto max = i1 > i2 ? i1 : i2;
    auto min = i1 > i2 ? i2 : i1;

    return max + min * (1 - max) / 2;
}

static double cast_ray_dist(const Scene &scene, const Ray &ray)
{
    double dist = -1u;

    for (const auto &obj : scene.objects) {
        auto possible_intersection = obj.get_intersection(ray);
        if (possible_intersection.has_value()
            and dist > (*possible_intersection - ray.origine).amplitude())
            dist = (*possible_intersection - ray.origine).amplitude();
    }

    return dist;
}

static double get_diffusion_light_intensity(const Light &light, const Object &obj,
                                            const Point &point)
{
    auto kd = obj.get_texture(point).diffusion_lightness;
    auto L = (light.origin - point).as_unit();
    auto cos = obj.get_normal(point) * L;
    cos = cos < 0 ? 0 : cos;
    auto I = light.intensity;

    return kd * I * cos;
}

static Vector get_reflected_vector(const Vector &d, const Vector &n)
{
    return d - n * (d * n) * 2;
}

static double get_specular_light_intensity(const Light &light, const Object &obj,
                                           const Point &point, const Ray &ray)
{
    auto ks = obj.get_texture(point).specular_lightness;
    auto ns = obj.get_texture(point).specular_pickyness;

    auto L = (light.origin - point).as_unit();
    auto S = get_reflected_vector(ray.dir, obj.get_normal(point));
    auto cos = S * L;
    cos = cos < 0 ? 0 : cos;
    auto I = light.intensity;

    return ks * I * pow(cos, ns);
}

static double get_light_influence(const Scene &scene, const Object &obj,
                                  const Point &point, const Ray &ray)
{
    double total_lights_intensity = 0;
    for (const auto light : scene.lights)
    {
        auto L = (light.origin - point).as_unit();
        if (cast_ray_dist(scene, Ray{-L, light.origin}) + epsilon < (point - light.origin).amplitude())
            continue;

        auto I_diff = get_diffusion_light_intensity(light, obj, point);
        auto I_spec = get_specular_light_intensity(light, obj, point, ray);

        auto total_light_intensity = add_lights_intensity(I_diff, I_spec);
        total_lights_intensity = add_lights_intensity(total_lights_intensity,
                                                      total_light_intensity);
    }

    return total_lights_intensity;
}

static Color get_color_on_point(const Object &obj, const Scene &scene,
                                const Point &point, const Ray &ray)
{
    auto color = obj.get_texture(point).color;
    auto light_influence = get_light_influence(scene, obj, point, ray);

    return color * light_influence;
}

static Color cast_ray(const Scene &scene, const Ray &ray, const short nb_reflect)
{
    Color ray_color{0, 0, 0};
    if (nb_reflect == 0)
        return ray_color;

    double dist = -1u;

    for (const auto &obj : scene.objects) {
        auto possible_intersection = obj.get_intersection(ray);
        if (possible_intersection.has_value()
            and dist > (*possible_intersection - ray.origine).amplitude())
        {
            auto point_color = get_color_on_point(obj, scene,
                                                  *possible_intersection, ray);

            auto reflected_vector = get_reflected_vector(ray.dir, obj.get_normal(*possible_intersection));
            auto reflected_ray = Ray{reflected_vector, *possible_intersection};
            auto reflected_color = cast_ray(scene, reflected_ray, nb_reflect - 1);

            ray_color = point_color + reflected_color;
            dist = (*possible_intersection - ray.origine).amplitude();
        }
    }

    return ray_color;
}

Image engine::generate_image(int width, int height, const Scene &scene)
{
    auto img_plan = get_img_plan(scene.camera, width, height);

    std::vector<std::vector<Color>> buffer;
    for (size_t y = 0; y < height; y++) {
        std::vector<Color> row;
        for (size_t x = 0; x < width ; x++) {
            auto dst = get_coords_on_image_plan(img_plan, x, y);
            auto ray = Ray{dst - scene.camera.center, dst};

            row.push_back(cast_ray(scene, ray, 5));
        }
        buffer.push_back(row);
    }

    return Image{width, height, buffer};
}
