#include "object.h"
#include "engine.h"
#include "raymath.h"

extern const float G = 1.0f;
const float SOFTENING = 0.1f;

std::vector<Vector3> ComputeAccelerations(std::vector<Object*>& objects){
    std::vector<Vector3> positions;
    std::vector<float> masses;
    for (auto* object : objects){
        positions.push_back(object->GetPosition());
        masses.push_back(object->GetMass());
    }

    std::vector<Vector3> accelerations(positions.size(), Vector3Zero());

    auto distanceCubed = [](float distance){
                return (distance * distance * distance + SOFTENING * SOFTENING * SOFTENING);
            };

    for (size_t i = 0; i < positions.size(); i++){
        for (size_t j = 0; j < positions.size(); j++){
            if (i == j) continue;

            Vector3 direction = Vector3Subtract(positions[j], positions[i]);
            float distance = Vector3Length(direction);  
            
            float ScaleFactor = (G * masses[j]) / (distanceCubed(distance));

            accelerations[i] = Vector3Add(accelerations[i], Vector3Scale(direction, ScaleFactor));
        }
    }

    return accelerations;
}

void Step(std::vector<Object*>& objects, float dt){
    std::vector<Vector3> old_positions;
    std::vector<Vector3> old_velocities;
    std::vector<Vector3> old_accelerations;
    for (auto* object : objects){
        old_positions.push_back(object->GetPosition());
        old_velocities.push_back(object->GetVelocity());
        old_accelerations.push_back(object->GetAcceleration());
    }
    std::vector<Vector3> new_positions(old_positions.size(), Vector3Zero());

    for (size_t i = 0; i < new_positions.size(); i++){
        new_positions[i] = Vector3Add(Vector3Add(old_positions[i], Vector3Scale(old_velocities[i],dt)),
        Vector3Scale(old_accelerations[i], 0.5*dt*dt));

        objects[i]->SetPosition(new_positions[i]);
    }

    std::vector<Vector3> new_accelerations = ComputeAccelerations(objects);
    std::vector<Vector3> new_velocities(new_accelerations.size(), Vector3Zero());

    for (size_t i = 0; i < new_velocities.size(); i++){
        new_velocities[i] = Vector3Add(old_velocities[i], 
            Vector3Scale(Vector3Add(new_accelerations[i], old_accelerations[i]), 0.5f*dt));
    }

    for (size_t i = 0; i < objects.size(); i++){
        
        objects[i]->SetVelocity(new_velocities[i]);
        objects[i]->SetAcceleration(new_accelerations[i]);
        
    }

}