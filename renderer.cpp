#include "raylib.h"
#include "raymath.h"
#include "renderer.h"
#include "object.h"
#include <vector>
#include <string>

const int rings = 24;
const int slices = 24;
const int fontSize = 16;
const float labelPadding = 0.3f; // odstep etykiety nad powierzchnia obiektu

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

