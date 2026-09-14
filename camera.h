#pragma once
#include "raylib.h"


void GetMovementAxes(float &forward, float &right, float &up);

Vector3 movement(float forward, float  right, float up);

Vector3 rotation();