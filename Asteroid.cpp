//
// Created by Ishra on 20/09/2023.
//

#include "Asteroid.hpp"

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed)
        : x(x), y(y), size(size), xSpeed(xSpeed), ySpeed(ySpeed) {}

// Getters
double Asteroid::GetX() {
    return x;
}
double Asteroid::GetY() {
    return y;
}
double Asteroid::GetXSpeed() {
    return xSpeed;
}
double Asteroid::GetYSpeed() {
    return ySpeed;
}
double Asteroid::GetSize() {
    return size;
}

// Setters
void Asteroid::SetX(double x) {
    this->x = x;
}
void Asteroid::SetY(double y) {
    this->y = y;
}
void Asteroid::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}
void Asteroid::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}
void Asteroid::SetSize(double size) {
    this->size = size;
}

//move
void Asteroid::Move() {
    // avec xSpeed ySpeed
    x += xSpeed;
    y += ySpeed;
}

// move astéroide avec réentrée
void Asteroid::Move(double screenWidth, double screenHeight) {
    // mise à jour de la position
    x += xSpeed;
    y += ySpeed;

    if (x < 0) {
        x = screenWidth; // réapparaît à droite
    } else if (x > screenWidth) {
        x = 0; // réapparaît à gauche
    }

    if (y < 0) {
        y = screenHeight; // réapparaît en bas de l'écran
    } else if (y > screenHeight) {
        y = 0; // réapparaît en haut de l'écran
    }
}

