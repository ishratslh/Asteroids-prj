//
// Created by Ishra on 22/10/2023.
//

#ifndef ASTEROIDS_PRJ_SPACESHIP_HPP
#define ASTEROIDS_PRJ_SPACESHIP_HPP

#include "FlyingObject.hpp"

class Spaceship : public FlyingObject{
private:
    double angle;
    bool warning;
    float shieldLevel;

public:
    ///////////////
    // Constructeur
    // -------
    // * x, y : coordonnées du centre de l'astéroïde, en pixels
    // * size : diamètre du vaisseau
    // * angle d'orientation
    Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle);

    ~Spaceship() ;

    //////////
    // Getters
    double GetAngle();
    double GetWarning();
    double GetShieldLevel();

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

    std::string GetTypeName() const override;

};


#endif //ASTEROIDS_PRJ_SPACESHIP_HPP
