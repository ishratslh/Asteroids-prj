//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_MODEL_HPP
#define ASTEROIDS_PRJ_MODEL_HPP

#include "FlyingObject.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include <vector>

class Model {


public :

    Model(int screenWidth, int screenHeight);
    void Update();
    //------------Actions :
    void ChooseAction(int action);
    void SpeedUp();
    void SpeedDown();
    void RotateRight();
    void RotateLeft();
    //----------Getters :
    std::vector<FlyingObject *> GetFlyingObjects();
    std::vector<FlyingObject *> GetFlyingObjectsInGame(std::vector<FlyingObject*>& allFlyingObjects);



private :
    //List of Flying Objects
    std::vector<FlyingObject *> flyingObjects;

    //Flying Objects
    Spaceship* spaceship;
    Asteroid* asteroidOne;
    Asteroid* asteroidTwo;
    Missile* missileTest;

};

#endif //ASTEROIDS_PRJ_MODEL_HPP
