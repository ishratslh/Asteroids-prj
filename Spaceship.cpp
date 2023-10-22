//
// Created by Ishra on 22/10/2023.
//

#include "Spaceship.hpp"
#include <cmath>


Spaceship::Spaceship(double x, double y, double size, double angle)
        : FlyingObject(x, y, size), angle(angle) {}

double Spaceship::GetAngle(){
    return angle;
}
/*On va donc effectuer un calcul vectoriel (en l’occurrence une addition) :
 on va considérer un facteur d’accélération ou de décélération. Ce facteur est la longueur (la norme)
 du vecteur de poussée. Il faut donc convertir ce vecteur en poussée horizontale et en poussée
 verticale (ce sont les composantes de ce vecteur), puis ajouter (ou retrancher dans le cas de
 la décélération) ces composantes respectivement aux composantes horizontales et verticales de la
vitesse du vaisseau. Pour effectuer cette conversion, il faudra dont utiliser les rapports trigonométriques*/
void Spaceship::SpeedUp(double accelerationFactor){
    xSpeed += accelerationFactor * cos(angle);
    ySpeed += accelerationFactor * sin(angle);

}

