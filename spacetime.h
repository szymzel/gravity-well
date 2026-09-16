#pragma once
#include "object.h"
#include "raylib.h"
#include <vector>
#include "cmath"

float ComputeBending(const std::vector<Object*>& objects, float x0, float y0);
void DrawSpacetime(const std::vector<Object*>& objects);
