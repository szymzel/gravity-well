#include "orbit_trail.h"
#include "raylib.h"
#include "deque"

Orbit_Trail::Orbit_Trail(size_t max_points, Color color) : max_points(max_points),
color(color){}

void Orbit_Trail::Update(Vector3 Current_Position){
    this->points.push_back(Current_Position);
    if (this->points.size() > this->max_points){
        this->points.pop_front();
    }
}

void Orbit_Trail::Draw() const{
    
    for (size_t i = 0;i + 1< this->points.size(); i++){
        DrawLine3D(this->points[i], this->points[i+1], this->color);
    }
}