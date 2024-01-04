//
// Created by Ishra on 05/10/2023.
//

#include "Missile.hpp"

Missile::Missile(double x, double y, double size, double speed, double angle)
: FlyingObject(x, y, size, speed, speed), angle(angle) {}

//____________________________________Getters and Setters____________________________________
double Missile::GetXSpeed() { //récupère la vitesse de déplacement en x
    return xSpeed * cos(angle);
}
double Missile::GetYSpeed() { //récupère la vitesse de déplacement en y
    return ySpeed * sin(angle);
}
double Missile::GetAngle() { //récupère l'angle d'orientation
    return this->angle;
}

std::string Missile::GetTypeName() const { //récupère le nom de l'objet
    return "Missile";
}

//____________________________________Move____________________________________
bool Missile::Move2(double screenWidth, double screenHeight){ //ancienne version de move
    // déplace selon les vitesses de déplacement de l'objet
    x += xSpeed * cos(angle);
    y += ySpeed * sin(angle);

    // Renvoie : un booléen indiquant s'il y a sortie des limites de l'écran
    if (x < 0 || x > screenWidth || y < 0 || y > screenHeight) {
        return true;
    } else {
        return false;
    }
}

void Missile::Move(double screenWidth, double screenHeight) { //nouvelle version de move qui actualise les coordonnées de l'objet seulement
    double xspeed = Missile::GetXSpeed() * sin(FlyingObject::DegToRad(Missile::GetAngle()));
    double yspeed = Missile::GetYSpeed() * cos(FlyingObject::DegToRad(Missile::GetAngle()));

    if (FlyingObject::GetX() + xSpeed >= screenWidth || FlyingObject::GetX() + xSpeed <= 0 ||
        FlyingObject::GetY() + ySpeed >= screenHeight || FlyingObject::GetY() + ySpeed <= 0) {

    }
    else {
        FlyingObject::SetX(FlyingObject::GetX() + xspeed);
        FlyingObject::SetY(FlyingObject::GetY() + yspeed);
    }
}

bool Missile::NotOnScreen(double screenWidth, double screenHeight) { //vérifie si le missile est toujours dans l'écran
    if (FlyingObject::GetX() + xSpeed >= screenWidth || FlyingObject::GetX() + xSpeed <= 0 ||
        FlyingObject::GetY() + ySpeed >= screenHeight || FlyingObject::GetY() + ySpeed <= 0) {
        return true;
    }
    else {
        return false;
    }
}

Missile::~Missile() {
    delete this;
}