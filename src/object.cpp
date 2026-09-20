#include "object.h"
#include "raylib.h"
#include "raymath.h"
#include <string>

Object::Object(std::string name, Color color, float radius, 
    float mass, Vector3 position, Vector3 velocity, Vector3 acceleration) 
    : name(name), color(color), radius(radius), mass(mass), position(position),
    velocity(velocity), acceleration(acceleration){}

std::string Object::GetName() const{
    return this->name;
}

Color Object::GetColor() const{
    return this->color;
}

float Object::GetRadius() const{
    return this->radius;
}

float Object::GetMass() const{
    return this->mass;
}

Vector3 Object::GetPosition() const{
    return this->position;
}

Vector3 Object::GetVelocity() const{
    return this->velocity;
}

Vector3 Object::GetAcceleration() const{
    return this->acceleration;
}

void Object::SetPosition(Vector3 position){
    this->position = position;
}

void Object::SetVelocity(Vector3 velocity){
    this->velocity = velocity;
}

void Object::SetAcceleration(Vector3 acceleration){
    this->acceleration = acceleration;
}

void Object::AddToPosition(Vector3 Change){
    this->position = Vector3Add(this->position, Change);
}

void Object::AddToVelocity(Vector3 Change){
    this->velocity = Vector3Add(this->velocity, Change);
}

void Object::AddToAcceleration(Vector3 Change){
    this->acceleration = Vector3Add(this->acceleration, Change);
}



