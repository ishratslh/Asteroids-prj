//
// Created by Ishra on 20/09/2023.
//

#include "Asteroid.hpp"
#include <cmath>

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle, int nbExplosions)
        : FlyingObject(x, y, size, xSpeed, ySpeed), angle(angle), nbExplosionsLeft(nbExplosions) {}


double Asteroid::GetXSpeed() {
    return xSpeed;
}
double Asteroid::GetYSpeed() {
    return ySpeed;
}
double Asteroid::GetAngle() {
    return angle;
}
double Asteroid::GetNbExplosionsLeft() {
    return nbExplosionsLeft;
}

/*void Asteroid::Move() {
    x += xSpeed;
    y += ySpeed;
}*/

// move astéroide avec réentrée
void Asteroid::Move(double screenWidth, double screenHeight) {
    // mise à jour de la position

    double xspeed = Asteroid::GetXSpeed() * sin(FlyingObject::DegToRad(Asteroid::GetAngle()));
    double yspeed = Asteroid::GetYSpeed() * cos(FlyingObject::DegToRad(Asteroid::GetAngle()));

    if (this->x < 0) {
        x = screenWidth; // réapparaît à droite
    } else if (this->x > screenWidth) {
        x = 0; // réapparaît à gauche
    }

    if (y < 0) {
        y = screenHeight; // réapparaît en bas de l'écran
    } else if (y > screenHeight) {
        y = 0; // réapparaît en haut de l'écran
    }
    else{
        x += xspeed;
        y += yspeed;
    }
}

Asteroid *Asteroid::Explode(double speed, double angle) {
    if(this->nbExplosionsLeft>0){
        //Each asteroids generated reduce the nbExplosionsLeft (means that when a missile hits an asteroids the nbOfExplosions reduce by 2)
        double newSize = Asteroid::GetSize()/2; //Reduce size
        Asteroid* newAsteroid = new Asteroid(Asteroid::GetX(), Asteroid::GetY(), newSize, Asteroid::GetXSpeed(), Asteroid::GetYSpeed(), angle,nbExplosionsLeft-2);
        this->nbExplosionsLeft--;
        return newAsteroid;

    }
    else{
        return nullptr;
    }
}

std::string Asteroid::GetTypeName() const {
    return "Asteroid";
}

