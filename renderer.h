#pragma once
#include "raylib.h"
#include "object.h"
#include "raymath.h"
#include <vector>
#include "camera.h"

void Draw(const std::vector<Object*>& objects);
void DrawLabels(const std::vector<Object*>& objects, Camera3D camera);
void DrawOrbits(std::vector<Object*>& objects);
void GenerateStars(std::vector<Vector3>& stars);
void DrawStars(const std::vector<Vector3>& stars, Camera3D camera);