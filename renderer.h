#pragma once
#include "raylib.h"
#include "object.h"
#include "raymath.h"
#include <vector>

void Draw(const std::vector<Object*>& objects);
void DrawLabels(const std::vector<Object*>& objects, Camera3D camera);