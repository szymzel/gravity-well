#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"
#include "renderer.h"
#include "camera.h"
#include "object.h"
#include "initial_conditions.h"
#include "engine.h"
#include "orbit_trail.h"
#include "spacetime.h"

const int width = GetMonitorWidth(GetCurrentMonitor());
const int height = GetMonitorHeight(GetCurrentMonitor());


float forward, right, up;

std::vector<Object*> objects;
std::vector<Vector3> stars;

int main(){
    InitWindow(width,height, "Okno Symulacji");
    ToggleFullscreen();
    rlSetClipPlanes(RL_CULL_DISTANCE_NEAR, 5000.0);

    Camera3D camera = {0};
    camera.position = {10.0f, 10.0f, 10.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    alpha_centauri_system(objects);

    int CameraActive = 0;
    DisableCursor();

    std::vector<Orbit_Trail> orbits;
    size_t max_points = 10000;
    for (size_t i = 0; i < objects.size();i++){
        Orbit_Trail orbit(max_points, objects[i]->GetColor());
        orbits.push_back(orbit);
    }

    GenerateStars(stars);
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
        for (size_t i = 0; i < orbits.size(); i++){
            orbits[i].Update(objects[i]->GetPosition());
        }

        
        float dt = fminf(GetFrameTime(), 1.0f / 30.0f);
        Step(objects, dt);
        
        
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                DrawStars(stars, camera);
                Draw(objects);
                
                DrawSpacetime(objects);
                for (const auto& orbit : orbits){
                    orbit.Draw();
                }
            EndMode3D();
            DrawLabels(objects, camera);
        EndDrawing();
    }


}