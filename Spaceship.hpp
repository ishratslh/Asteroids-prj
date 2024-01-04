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
        double angle; // angle d'orientation du vaisseau
        bool warning; // booléen indiquant si le vaisseau est en warning ou non
        double shieldLevel; // niveau de bouclier du vaisseau
        std::chrono::time_point<std::chrono::system_clock> invincibilityEndTime; // temps d'invincibilité du vaisseau

    public:
        ///////////////
        // Constructeur
        // -------
        // * x, y : coordonnées du centre de l'astéroïde, en pixels
        // * size : diamètre du vaisseau
        // * angle d'orientation
        // * xSpeed, ySpeed : vecteur de vitesse de l'objet
        // * warning : booléen indiquant si le vaisseau est en warning ou non
        // * shieldLevel : niveau de bouclier du vaisseau
        // * invincibilityEndTime : temps de fin d'invincibilité du vaisseau
        Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle);

        ~Spaceship();

        //////////
        // Getters et Setters
        // -------
        double GetAngle();
        bool GetWarning();
        double GetShieldLevel();
        bool GetInvincible(); // Renvoie un booléen indiquant si le vaisseau est invincible ou non
        std::string GetTypeName() const override;
        void SetXSpeed(double xSpeed);
        void SetYSpeed(double ySpeed);
        void SetAngle(double angle);
        void SetWarning(bool warning);
        void SetShieldLevel(double shieldLevel);
        void SetInvincibleFor(double temps); // Place le vaisseau en mode invincible (temps : durée pendant laquelle le vaisseau est invincible)

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
        // * angle : l'angle de rotation, en degrés
        void Rotate(double rAngle);

        ///////////////////////////
        // Fait se déplacer le vaisseau
        void Move(double screenWidth, double screenHeight) ;
};


#endif //ASTEROIDS_PRJ_SPACESHIP_HPP
