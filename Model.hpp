//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_MODEL_HPP
#define ASTEROIDS_PRJ_MODEL_HPP
#include "Framework.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include <vector>
#include <string>
#include "include/SDL2/SDL.h"
#include <iostream>

class Model {
private:
    Spaceship* spaceship;
    Asteroid* asteroid;
    Missile* missile;
    Framework *framework;
    double screenWidth;
    double screenHeight;

public:
    Model(Framework* fw, int screenWidth, int screenHeight);
    Model(int screenWidth, int screenHeight);
    ~Model();

    void HandleUserInput(int userInput);
    static void DestroyFlyingObject(FlyingObject* flyingObject);
    bool CheckCollision(FlyingObject* flyingObject1, FlyingObject* flyingObject2);
    void Update();
    std::vector<FlyingObject*> GetFlyingObjects();
};

#endif //ASTEROIDS_PRJ_MODEL_HPP
