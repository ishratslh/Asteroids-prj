//
// Created by Ishra on 20/09/2023.
//

#ifndef PROJET_ASTEROID_HPP
#define PROJET_ASTEROID_HPP

#include "FlyingObject.hpp"
#include <cmath>

class Asteroid : public FlyingObject{
    private:
        double angle; // angle d'orientation de l'astéroïde
        int nbExplosionsRestant; // nombre d'explosions restant

    public:
        ///////////////
        // Constructeur
        // * x, y : position dans l'écran
        // * size : diamètre de l'objet
        // * xSpeed, ySpeed : vecteur de vitesse de l'objet
        // * angle : orientation de l'astéroïde
        // * nbExplosions : nombre d'explosions restant
        Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle, int nbExplosions);

        //////////
        // Getters et Setters
        double GetXSpeed();
        double GetYSpeed();
        double GetAngle();
        double GetNbExplosionsRestant();
        std::string GetTypeName() const override;

        void SetXSpeed(double xSpeed);
        void SetYSpeed(double ySpeed);
        void SetAngle(double angle);
        void SetNbExplosionsRestant(int nbExplosionsRestant);

        /////////////////////////
        // Déplacement de l'objet
        // déplace selon le vecteur de vitesse de l'objet
        void Move();

        ////////////
        // avec réentrée
        // déplace selon le vecteur de vitesse de l'objet
        // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
        // de l'autre côté
        // -------
        // * screenWidth, screenHeight : taille de l'écran
        void Move(double screenWidth, double screenHeight);

        /////////////////////////////
        // Explosion de l'astéroïde
        // -------
        // si un missile touche un asteroide, celui-ci se divise en 2 et nbExplosionsRestant est décrémenté
        Asteroid* Explode(double speed, double angle);
};

#endif //PROJET_ASTEROID_HPP
