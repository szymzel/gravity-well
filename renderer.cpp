#include "raylib.h"
#include "renderer.h"
#include "object.h"
#include <vector>

const int rings = 300;
const int slices = 300;

void Draw(const std::vector<Object*>& objects){
    for (auto* object : objects){
        DrawSphereEx(object->GetPosition(), object->GetRadius(),
            rings, slices, object->GetColor());
        
    }
}