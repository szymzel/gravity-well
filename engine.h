#pragma once
#include "object.h"
#include <vector>

std::vector<Vector3> ComputeAccelerations(std::vector<Object*>& objects);

void Step(std::vector<Object*>& objects, float dt);