//
// Created by Ishra on 05/10/2023.
//

#ifndef ASTEROIDS_PRJ_MISSILE_HPP
#define ASTEROIDS_PRJ_MISSILE_HPP

#include "FlyingObject.hpp"

class Missile : public FlyingObject{
public :
    double angle;

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
    ///////////////////////////////////////////////////////
    // déplace selon les vitesses de déplacement de l'objet
    // Renvoie : un booléen indiquant s'il y a sortie des limites de l'écran
    bool Move2(double screenWidth, double screenHeight);

    void Move(double screenWidth, double screenHeight);

    bool NotOnScreen(double screenWidth, double screenHeight);

    //////////
    // Getters
    double GetXSpeed();
    double GetYSpeed();
    std::string GetTypeName() const override;
};


#endif //ASTEROIDS_PRJ_MISSILE_HPP
