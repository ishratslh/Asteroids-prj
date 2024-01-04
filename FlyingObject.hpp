//
// Created by Ishra on 20/09/2023.
//
#ifndef PROJET_FLYINGOBJECT_HPP
#define PROJET_FLYINGOBJECT_HPP

#include <string>
#include <cmath>

class FlyingObject {
protected:
    double x; // position x
    double y; // position y
    double size; // taille de l'objet
    double xSpeed; // vitesse de déplacement selon x
    double ySpeed; // vitesse de déplacement selon y

public:
    /////////////////////////
    // Constructeur
    // -------
    // paramètres & méthodes communs à tous les flying objects
    // * x, y : position dans l'écran
    // * size : diamètre de l'objet
    // * xSpeed, ySpeed : vecteur de vitesse de l'objet
    FlyingObject(double x, double y, double size, double xSpeed, double ySpeed);

    /////////////////////////
    // Getters et Setters
    double GetX();
    double GetY();
    double GetSize();
    double GetXSpeed();
    double GetYSpeed();
    void SetX(double x);
    void SetY(double y);
    void SetSize(double size);
    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);

    /////////////////////////
    // Renvoie le nom de la classe
    virtual std::string GetTypeName() const = 0;

    /////////////////////////
    // Déplace selon les vitesses de déplacement de l'objet
    void Move();
    void Move(double screenWidth, double screenHeight);

    /////////////////////////////
    // Détermination de collision
    // calcul basé sur l'hypothèse que les objets sont sphériques
    // -------
    // * o1, o2 : les deux objets à tester
    // -------
    // Renvoie : true si les deux objets se touchent, false sinon
    static bool Collide(FlyingObject &o1, FlyingObject &o2);
    static bool Collide(FlyingObject *o1,FlyingObject *o2);

    /////////////////////////////
    // Conversion degrés/radians
    double DegToRad(double angle);
};

#endif //PROJET_FLYINGOBJECT_HPP
