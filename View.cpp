//
// Created by Ishra on 23/11/2023.
//
#include "View.hpp"

using namespace std;

//____________________________________Constructeur :_______________________________________

View::View(Framework* framework) {}

//____________________________________Refresh :_______________________________________
void View::Refresh(std::vector<FlyingObject *> flyingObjects,Framework* framework) {

    //----------------Test the list of FlyingObjects:
    for (FlyingObject* object : flyingObjects){
        if(object!=nullptr) {
            //For an Asteroid :
            if (object->GetTypeName() == "Asteroid") {
                framework->DrawAsteroid(object->GetX(), object->GetY(), object->GetSize());
                //std::cout << flyingObjects.size() << std::endl;
            }

                //For a Missile :
            else if (object->GetTypeName() == "Missile") {
                framework->DrawMissile(object->GetX(), object->GetY());
            }

            else if(object->GetTypeName() == "Spaceship"){
                Spaceship* spaceship = dynamic_cast<Spaceship*>(object); // Cast to Spaceship
                framework->DrawShip(spaceship->GetX(),spaceship->GetY(),spaceship->GetAngle(),spaceship->GetShieldLevel(),spaceship->GetWarning());
            }
        }

    }
    framework->Update();
}