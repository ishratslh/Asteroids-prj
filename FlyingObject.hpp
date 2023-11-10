//
// Created by Ishra on 20/09/2023.
//

#ifndef PROJET_FLYINGOBJECT_HPP
#define PROJET_FLYINGOBJECT_HPP


class FlyingObject {
public:
    double x;
    double y;
    double size;
    double xSpeed;
    double ySpeed;

public:
    FlyingObject(double x, double y, double size, double xSpeed, double ySpeed);
    // méthodes communs à tous les flying objects
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

    /////////////////////////////
    // Détermination de collision
    // calcul basé sur l'hypothèse que les objets sont sphériques
    // -------
    // * o1, o2 : les deux objets à tester
    // -------
    // Renvoie : true si les deux objets se touchent, false sinon
    static bool Collide(FlyingObject o1, FlyingObject o2);

};


#endif //PROJET_FLYINGOBJECT_HPP
