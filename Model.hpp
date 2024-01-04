//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_MODEL_HPP
#define ASTEROIDS_PRJ_MODEL_HPP

#include "FlyingObject.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "Framework.hpp"
#include <vector>

class Model {

private :
    //List of Flying Objects
    std::vector<FlyingObject *> flyingObjects;

    //Flying Objects
    Spaceship* spaceship;
    Missile* missile;
    int nbAsteroids;
    bool missileNotOnScreen;

public :

    Model(int screenWidth, int screenHeight);
    int Update(Framework* framework);
    //------------Actions :
    void ChooseAction(int action);
    void SpeedUp();
    void SpeedDown();
    void RotateRight();
    void RotateLeft();
    void ShootMissile();
    void InitializeAsteroids(double screenWidth, double sreenHeight);

    //----------Getters :
    std::vector<FlyingObject *> GetFlyingObjects();
    std::vector<FlyingObject *> GetFlyingObjectsInGame(std::vector<FlyingObject*>& allFlyingObjects, Framework* framework);

};

#endif //ASTEROIDS_PRJ_MODEL_HPP
