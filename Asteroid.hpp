//
// Created by Ishra on 20/09/2023.
//

#ifndef PROJET_ASTEROID_HPP
#define PROJET_ASTEROID_HPP

#include "FlyingObject.hpp"

class Asteroid : public FlyingObject{
public:
    //double xSpeed;   // Vitesse en x
    //double ySpeed;   // Vitesse en y

public:
    ///////////////
    // Constructeur
    // -------
    // * x, y : position dans l'écran
    // * size : diamètre de l'objet
    // * xSpeed, ySpeed : vecteur de vitesse de l'objet

    Asteroid(double x, double y, double size, double xSpeed, double ySpeed);

    //////////
    // Getters
    double GetXSpeed();
    double GetYSpeed();

    //////////
    // Setters
    //void SetXSpeed(double xSpeed);
    //void SetYSpeed(double ySpeed);

    /////////////////////////
    // Déplacement de l'objet
    // déplace selon le vecteur de vitesse de l'objet
    void Move();

    ///////////////////////////////////////
    // Déplacement de l'objet avec réentrée
    // déplace selon le vecteur de vitesse de l'objet
    // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
    // de l'autre côté
    // -------
    // * screenWidth, screenHeight : taille de l'écran
    void Move(double screenWidth, double screenHeight);
};

#endif //PROJET_ASTEROID_HPP
