#include "raylib.h"
#include "raymath.h"
#include "renderer.h"
#include "object.h"
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "camera.h"

const int rings = 24;
const int slices = 24;
const int fontSize = 16;
const float labelPadding = 0.3f;
const float R = 1000.0f;


void Draw(const std::vector<Object*>& objects){
    for (auto* object : objects){
        DrawSphereEx(object->GetPosition(), object->GetRadius(),
            rings, slices, object->GetColor());

    }
}

void DrawLabels(const std::vector<Object*>& objects, Camera3D camera){
    Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position));

    for (auto* object : objects){
        Vector3 labelPosition = Vector3Add(object->GetPosition(),
            {0.0f, object->GetRadius() + labelPadding, 0.0f});

        Vector3 toLabel = Vector3Subtract(labelPosition, camera.position);
        if (Vector3DotProduct(forward, toLabel) <= 0.0f) continue; // za kamera

        Vector2 screenPosition = GetWorldToScreen(labelPosition, camera);
        std::string name = object->GetName();
        int textWidth = MeasureText(name.c_str(), fontSize);

        DrawText(name.c_str(), (int)screenPosition.x - textWidth / 2,
            (int)screenPosition.y, fontSize, WHITE);
    }
}

void GenerateStars(std::vector<Vector3>& stars){
    static int Number_Of_Stars = 100000;
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    static std::uniform_real_distribution<float> dist_phi(0.0f, 2*3.14f);
    static std::uniform_real_distribution<float> dist_theta(0.0f, 3.14f);

    for (int i = 0; i < Number_Of_Stars; i++){
        float x, y, z;
        float phi = dist_phi(gen);
        float theta = dist_theta(gen);
        x = R*cos(phi)*sin(theta);
        y = R*sin(phi)*sin(theta);
        z = R*cos(theta);
        Vector3 star{x,y,z};
        Vector3 star_unit_vector = Vector3Scale(star, 1/Vector3Length(star));
        stars.push_back(star_unit_vector);
}
}

void DrawStars(const std::vector<Vector3>& stars, Camera3D camera){
    for (size_t i = 0; i < stars.size(); i++){
        Vector3 starPos = Vector3Add(camera.position, Vector3Scale(stars[i], R));
        DrawPoint3D(starPos, WHITE);
    }
}