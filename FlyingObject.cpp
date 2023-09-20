//
// Created by Ishra on 20/09/2023.
//

#include "FlyingObject.hpp"

FlyingObject::FlyingObject(double x, double y, double size)
        : x(x), y(y), size(size) {}

// Getters
double FlyingObject::GetX() {
    return x;
}
double FlyingObject::GetY() {
    return y;
}
double FlyingObject::GetSize() {
    return size;
}

// Setters
void FlyingObject::SetX(double x) {
    this->x = x;
}
void FlyingObject::SetY(double y) {
    this->y = y;
}
void FlyingObject::SetSize(double size) {
    this->size = size;
}

//move


