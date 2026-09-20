#pragma once
#include <deque>
#include "raylib.h"

class Orbit_Trail{
    private:
        std::deque<Vector3> points;
        size_t max_points;
        Color color;
    public:
        Orbit_Trail(size_t max_points, Color color);
        void Update(Vector3 Current_Position);
        void Draw() const;
};