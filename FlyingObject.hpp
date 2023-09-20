//
// Created by Ishra on 20/09/2023.
//

#ifndef PROJET_FLYINGOBJECT_HPP
#define PROJET_FLYINGOBJECT_HPP


class FlyingObject {
public:
    FlyingObject(double x, double y, double size);
    // méthodes communs à tous les flying objects
    double GetX();
    double GetY();
    double GetSize();
    void SetX(double x);
    void SetY(double y);
    void SetSize(double size);

private:
    double x;
    double y;
    double size;
    double xSpeed;
    double ySpeed;

};


#endif //PROJET_FLYINGOBJECT_HPP
