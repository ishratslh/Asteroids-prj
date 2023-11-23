//
// Created by Ishra on 22/10/2023.
//

#ifndef ASTEROIDS_PRJ_SPACESHIP_HPP
#define ASTEROIDS_PRJ_SPACESHIP_HPP

#include "FlyingObject.hpp"

class Spaceship : public FlyingObject{
public:
    double angle;

public:
    ///////////////
    // Constructeur
    // -------
    // * x, y : coordonnées du centre de l'astéroïde, en pixels
    // * size : diamètre du vaisseau
    // * angle d'orientation
    Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle);

    //////////
    // Getters

    double GetAngle();

    ///////////////////////
    // Accélère le vaisseau
    // -------
    // * accelerationFactor : le facteur d'accéleration appliqué
    void SpeedUp(double accelerationFactor);

    ///////////////////////
    // Décélère le vaisseau
    // -------
    // * decelerationFactor : le facteur de décéleration appliqué
    void SpeedDown(double decelerationFactor);

    ///////////////////////////
    // Fait pivoter le vaisseau
    // -------
    // * angle : l'angle de rotation, en degrés.
    void Rotate(double rAngle);

    void Move(double screenWidth, double screenHeight) ;

};


#endif //ASTEROIDS_PRJ_SPACESHIP_HPP
