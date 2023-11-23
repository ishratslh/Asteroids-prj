//
// Created by Ishra on 20/09/2023.
//

#include "Asteroid.hpp"

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed)
        : FlyingObject(x, y, size, xSpeed, ySpeed) {}


double Asteroid::GetXSpeed() {
    return xSpeed;
}
double Asteroid::GetYSpeed() {
    return ySpeed;
}

/*void Asteroid::Move() {
    x += xSpeed;
    y += ySpeed;
}*/

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

