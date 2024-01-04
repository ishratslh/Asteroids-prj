//
// Created by Ishra on 23/11/2023.
//

#include <iostream>
#include <SDL_keycode.h>
#include "Model.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"

using namespace std;

//-------------------------------------------------------------------Constructors :
Model::Model(int screenWidth, int screenHeight) {

    //----------------Create Spaceship :
    double xS = screenWidth / 4.0;
    double yS = screenHeight / 2.0;
    double sizeS = 60.0;
    double speedXS = 1.0;
    double speedYS = 1.0;
    double angleS = 0.0;
    this->spaceship = new Spaceship(xS,yS,sizeS,speedXS,speedYS, angleS);
    //-------------------------------

    //-----------------Create Asteroid :
    this->asteroidOne= new Asteroid(150, 500,100, 10, 3);
    this->asteroidTwo = new Asteroid(1600,screenHeight, 100, -5, -2);
    //----------------------------------

    //----------------Create Missile :
    this->missileTest = new Missile(screenWidth/2, screenHeight/2,10, 10, 0);
    //-------------------------------

    //Adding them to the flyingObjects list
    flyingObjects.push_back(spaceship);
    flyingObjects.push_back(asteroidOne);
    flyingObjects.push_back(asteroidTwo);
    flyingObjects.push_back(missileTest);


}
//-----------------------------------------------------------------------------





//-----------------------------------------------------------------Update :

void Model::Update(Framework* framework) {

    //Update the list of Objects :
    Model::GetFlyingObjectsInGame(flyingObjects, framework);
    //Move the objects (different move methods so we need dynamic cast):
    for (FlyingObject* object : flyingObjects){
        if(object!=nullptr){
            if (object->GetTypeName()=="Missile"){
                Missile* missile = dynamic_cast<Missile*>(object); // Cast to Missile
                missile->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
            else if(object->GetTypeName()=="Asteroid"){
                Asteroid* asteroid = dynamic_cast<Asteroid*>(object); // Cast to Asteroid
                asteroid->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
            else if(object->GetTypeName()=="Spaceship"){
                Spaceship* spaceship = dynamic_cast<Spaceship*>(object); // Cast to Spaceship
                spaceship->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
        }

    }

    std::vector<FlyingObject*> objectsToRemove;
    // Test collisions between all missiles and all asteroids
    for (int i = 0; i < flyingObjects.size(); ++i) {
        FlyingObject* object = flyingObjects[i];
        if (object != nullptr && object->GetTypeName() == "Missile") {
            for (int j = 0; j < flyingObjects.size(); ++j) {
                FlyingObject* otherObject = flyingObjects[j];
                if (otherObject != nullptr && otherObject->GetTypeName() == "Asteroid") {
                    bool collision = FlyingObject::Collide(object, otherObject);
                    if (collision) {
                        // Remove otherObject from the vector
                        flyingObjects.erase(flyingObjects.begin() + j);
                        delete otherObject;
                    }
                }
            }
        }
    }

}
//--------------------------------------------------------------------------------






//-----------------Actions :
void Model::ChooseAction(int action) {
    switch (action) {
        case SDLK_UP:
            Model::SpeedUp();
            break;
        case SDLK_DOWN:
            Model::SpeedDown();
            break;
        case SDLK_RIGHT:
            Model::RotateRight();
            break;
        case SDLK_LEFT:
            Model::RotateLeft();
            break;
        case SDLK_ESCAPE:
            SDL_Quit();
            exit(0);
            break;


    }
}


void Model::SpeedUp() {
    spaceship->SpeedUp(10);
}

void Model::SpeedDown() {
    spaceship->SpeedDown(10);
}

void Model::RotateRight() {
    spaceship->Rotate(20);
}

void Model::RotateLeft() {
    spaceship->Rotate(-20);
}

//------------------------------------------

//---------------------Getters:
std::vector<FlyingObject *> Model::GetFlyingObjects() {
    return flyingObjects;
}



std::vector<FlyingObject*> Model::GetFlyingObjectsInGame(std::vector<FlyingObject*>& allFlyingObjects, Framework* framework) {

    // Check all the objects in the game
    for (auto it = flyingObjects.begin(); it != flyingObjects.end();) {
        FlyingObject* object = *it;

        // Check if the object is a missile
        if (object->GetTypeName() == "Missile") {
            Missile* missile = dynamic_cast<Missile*>(object);

            // Check if the missile is not on the screen
            if (missile->NotOnScreen(framework->GetScreenWidth(), framework->GetScreenHeight())) {
                //delete missile;
                missile = nullptr;
                it = flyingObjects.erase(it); // Remove the missile from flyingObjects
                continue;
            }
        }
        ++it;

    }

    return flyingObjects;
}