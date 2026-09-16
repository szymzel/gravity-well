#include "spacetime.h"
#include "raylib.h"
#include "cmath"
#include "object.h"


const int grid_size = 100;
const float spacing = 18.0f;                 
const float offset = (grid_size * spacing)/2.0f;

float epsilon = 400.0f;

const float HEIGHT_ERROR_THRESHOLD = 0.2f;
const int MAX_SUBDIVISIONS = 12;


float ComputeBending(const std::vector<Object*>& objects, float x0, float z0){
    float Total_Potential = 0.0f;
    Vector3 Current_Point = {x0, 0.0f, z0};
    for (auto& object : objects){
        float mass = object->GetMass();
        float R_squared = Vector3LengthSqr(Vector3Subtract(object->GetPosition(), Current_Point));
        Total_Potential += (- mass)/sqrt(R_squared + epsilon);
    }
    return Total_Potential;

}

static void DrawAdaptiveEdge(const std::vector<Object*>& objects, Vector3 starting_point, Vector3 ending_point, int depth = 0){
    float linear_mid_y = (starting_point.y + ending_point.y)/2.0f;
    float mid_x = (starting_point.x + ending_point.x)/2.0f;
    float mid_z = (starting_point.z + ending_point.z)/2.0f;
    float true_mid_y = ComputeBending(objects, mid_x, mid_z);
    if (fabsf(linear_mid_y - true_mid_y) > HEIGHT_ERROR_THRESHOLD && depth < MAX_SUBDIVISIONS){
        Vector3 mid = {mid_x, true_mid_y, mid_z};
        DrawAdaptiveEdge(objects, starting_point, mid, depth + 1);
        DrawAdaptiveEdge(objects, mid, ending_point, depth + 1);
    } else {
        DrawLine3D(starting_point, ending_point, WHITE);
    }

}

void DrawSpacetime(const std::vector<Object*>& objects){
    
    for (int i = 0; i < grid_size; i++){
        for (int j = 0; j < grid_size; j++){
            float x0 = i * spacing - offset;
            float z0 = j * spacing - offset;
            float y0 = ComputeBending(objects, x0, z0);

            Vector3 current_point = {x0, y0, z0};

            float x1 = (i+1) * spacing - offset;
            float z1 = (j+1) * spacing - offset;
            if (i < grid_size - 1){
                DrawAdaptiveEdge(objects, current_point, (Vector3){x1,ComputeBending(objects, x1, z0),z0});
            }
            if (j < grid_size - 1){
                DrawAdaptiveEdge(objects, current_point, (Vector3){x0,ComputeBending(objects, x0, z1),z1});
            }
        }

    }
}