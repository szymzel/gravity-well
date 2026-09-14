#include "object.h"
#include "engine.h"
#include "raymath.h"

const float G = 1.0f;
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
