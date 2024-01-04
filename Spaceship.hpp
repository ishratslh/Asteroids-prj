//
// Created by Ishra on 22/10/2023.
//

#ifndef ASTEROIDS_PRJ_SPACESHIP_HPP
#define ASTEROIDS_PRJ_SPACESHIP_HPP

#include "FlyingObject.hpp"
#include <cmath>
#include <chrono>
#include <iostream>

class Spaceship : public FlyingObject{
private:
    double angle;
    bool warning;
    double shieldLevel;
    std::chrono::time_point<std::chrono::system_clock> invincibilityEndTime;

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
    bool GetWarning();
    double GetShieldLevel();

    //Setters
    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);
    void SetAngle(double angle);
    void SetWarning(bool warning);
    void SetShieldLevel(double shieldLevel);

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

    ////////////////////////////////////////
    // Indique si le vaisseau est invincible
    // -------
    // Renvoie: true si le vaisseau est dans une période d'invincibilité, false sinon
    bool GetInvincible();

    ///////////////////////////////////////
    // Place le vaisseau en mode invincible
    // -------
    // * duration : durée pendant laquelle le vaisseau est invincible
    void SetInvincibleFor(double duration);

    std::string GetTypeName() const override;

};


#endif //ASTEROIDS_PRJ_SPACESHIP_HPP
