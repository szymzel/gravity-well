#include "raylib.h"

const float CAMERA_SPEED = 20.0f;
const float MOUSE_SENSIVITY = 0.1f;

void GetMovementAxes(float &forward, float &right, float &up){
    forward = 0.0f;
    right = 0.0f;
    up = 0.0f;

    if (IsKeyDown(KEY_W)) forward += 1.0f;
    if (IsKeyDown(KEY_S)) forward -= 1.0f;
    if (IsKeyDown(KEY_D)) right += 1.0f;
    if (IsKeyDown(KEY_A)) right -= 1.0f;
    if (IsKeyDown(KEY_SPACE)) up += 1.0f;
    if (IsKeyDown(KEY_LEFT_CONTROL)) up -= 1.0f;
}
Vector3 movement(float forward, float  right, float up){
    float scale = CAMERA_SPEED * GetFrameTime();
    return {forward * scale, right * scale, up * scale};
}

Vector3 rotation(){
    Vector2 MOUSE_DELTA = GetMouseDelta();
    return {MOUSE_DELTA.x * MOUSE_SENSIVITY, MOUSE_DELTA.y * MOUSE_SENSIVITY, 0.0f};
}