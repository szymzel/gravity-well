#pragma once
#include <string>
#include "raylib.h"
#include "raymath.h"

class Object{
    public: 
        Object(std::string name, Color color, float radius, float mass, 
            Vector3 position, Vector3 velocity, Vector3 acceleration);
        std::string GetName() const;
        Color GetColor() const;
        float GetRadius() const;
        float GetMass() const;
        Vector3 GetPosition() const;
        Vector3 GetVelocity() const;
        Vector3 GetAcceleration() const;
        
        void SetPosition(Vector3 position);
        void SetVelocity(Vector3 velocity);
        void SetAcceleration(Vector3 acceleration);

        void AddToPosition(Vector3 Change);
        void AddToVelocity(Vector3 Change);
        void AddToAcceleration(Vector3 Change);
    private:
        std::string name;
        Color color;
        float radius;
        float mass;
        Vector3 position;
        Vector3 velocity;
        Vector3 acceleration;
};