//
// Created by Ishra on 23/11/2023.
//

#include "Model.hpp"

Model::Model(Framework *fw, int screenWidth, int screenHeight) {}

Model::Model(int screenWidth, int screenHeight) {
    //Paramètres d'un asteroide
    double xA = screenWidth / 2.0;
    double yA = screenHeight / 2.0;
    double sizeA = 70.0;
    double xSpeedA = 0.0;
    double ySpeedA = 0.0;
    bool destroyAsteroid = false;

    //Paramètres d'un missile
    double xM = screenWidth / 4.0;
    double yM = screenHeight / 2.0;
    double sizeM = 60.0;
    double speedM = 5.0;
    double angleM = 0.0;
    bool destroyMissile = false;

    //Paramètres de la classe Spaceship
    double xS = screenWidth / 4.0;
    double yS = screenHeight / 2.0;
    double sizeS = 60.0;
    double speedXS = 1.0;
    double speedYS = 1.0;
    double angleS = 0.0;

    this->spaceship = new Spaceship(xS,yS,sizeS,speedXS,speedYS, angleS);
    this->asteroid = new Asteroid(xA, yA,sizeA,xSpeedA,ySpeedA);
    this->missile = new Missile(xM,yM,sizeM,speedM,angleM);
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
}

Model::~Model() {
    delete spaceship;
    delete asteroid;
    if (missile) {
        delete missile;
    }
}

void Model::HandleUserInput(int userInput) {
    double accelerationFactor = 0.1;
    double decelerationFactor = 0.1;
    double rotationAngle = 10;
    bool warning = false;
    if (spaceship) { // implémentation des actions du joueur
        if (userInput == SDLK_UP) {
            spaceship->SpeedUp(accelerationFactor);
        }
        if (userInput == SDLK_DOWN) {
            spaceship->SpeedDown(decelerationFactor);
        }
        if (userInput == SDLK_LEFT) {
            spaceship->Rotate(-rotationAngle);
        }
        if (userInput == SDLK_RIGHT) {
            spaceship->Rotate(rotationAngle);
        }

        /*if (userInput == SDLK_SPACE) {
            if (!missile) {
                missile = new Missile(spaceship->GetX(), spaceship->GetY(), missileSize, 5.0, spaceship->GetAngle());
            }
        }*/
    }
}
bool Model::CheckCollision(FlyingObject* object1, FlyingObject* object2) {
    return FlyingObject::Collide(*object1, *object2);
}

void Model::Update() {
    if (missile) {
        bool outOfScreen = missile->Move(screenWidth, screenHeight);
        if (outOfScreen) {
            DestroyFlyingObject(missile);
        }
    }

    if (asteroid && missile) {
        if (CheckCollision(asteroid, missile)) {
            std::cout << "Hello collision?" << std::endl;
            DestroyFlyingObject(asteroid);
            DestroyFlyingObject(missile);
        }
    }

}

void Model::DestroyFlyingObject(FlyingObject* flyingObject) {
    if(flyingObject) {
        delete flyingObject;
        flyingObject = nullptr;
    }
}

std::vector<FlyingObject*> Model::GetFlyingObjects() {
    std::vector<FlyingObject*> flyingObjects;
    flyingObjects.push_back(spaceship);
    flyingObjects.push_back(asteroid);
    if (missile) {
        flyingObjects.push_back(missile);
    }
    return flyingObjects;
}