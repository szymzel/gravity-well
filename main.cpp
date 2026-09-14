#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "renderer.h"
#include "camera.h"
#include "object.h"

const int width = GetMonitorWidth(GetCurrentMonitor());
const int height = GetMonitorHeight(GetCurrentMonitor());


float forward, right, up;

std::vector<Object*> objects;
Object sun("Sun", YELLOW, 5.0f, 100.0f, {0.0f, 0.0f, 0.0f}, Vector3Zero(),
Vector3Zero());
Object planet("Planet", BLUE, 1.0f, 5.0f, {15.0f, 0.0f, 0.0f}, Vector3Zero(),
Vector3Zero());



int main(){
    objects.push_back(&sun);
    objects.push_back(&planet);

    InitWindow(width,height, "Okno Symulacji");
    ToggleFullscreen();

    Camera3D camera = {0};
    camera.position = {10.0f, 10.0f, 10.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    

    int CameraActive = 0;
    DisableCursor();

    while(!WindowShouldClose()){
        if (CameraActive==1){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                CameraActive = 0;
                DisableCursor();
            }
        } else if(CameraActive == 0){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                CameraActive = 1;
                EnableCursor();
            }
        }

        if (CameraActive==0){
            GetMovementAxes(forward, right, up);
            Vector3 move = movement(forward, right ,up);
            Vector3 rot = rotation();
            UpdateCameraPro(&camera, move, rot, 0.0f);
        }

        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                Draw(objects);
                DrawGrid(20,1.0f);
            EndMode3D();
        EndDrawing();
    }


}