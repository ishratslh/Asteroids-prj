//
// Created by Ishra on 05/10/2023.
//

#ifndef ASTEROIDS_PRJ_MISSILE_HPP
#define ASTEROIDS_PRJ_MISSILE_HPP

#include "FlyingObject.hpp"
#include <cmath>


class Missile : public FlyingObject{
private :
    double angle; // angle d'orientation du missile
    double speed; // vitesse de déplacement du missile

public :
    ///////////////
    // Constructeur
    // -------
    // * x, y : position dans l'écran
    // * size : diamètre du missile
    // * speed : vitesse de déplacement
    // * angle : orientation
    Missile(double x, double y, double size, double speed, double angle);

    ~Missile();

    //////////
    // Getters
    double GetSpeed();
    double GetAngle();
    std::string GetTypeName() const override;
    void SetAngle(double angle);

    ///////////////////////////////////////////////////////
    // déplace selon les vitesses de déplacement de l'objet
    // -------
    // Ancienne version = Move2 : Renvoie un booléen indiquant s'il y a sortie des limites de l'écran
    // Nouvelle version = Move : actualise les coordonnées de l'objet seulement
    bool Move2(double screenWidth, double screenHeight);
    void Move(double screenWidth, double screenHeight);

    ///////////////////////////////////////////////////////
    // Vérifie si le missile est toujours dans l'écran
    // -------
    bool NotOnScreen(double screenWidth, double screenHeight);
};

#endif //ASTEROIDS_PRJ_MISSILE_HPP
