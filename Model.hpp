//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_MODEL_HPP
#define ASTEROIDS_PRJ_MODEL_HPP

#ifndef MODEL_HPP
#define MODEL_HPP

#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include <vector>

class Model {
private:
    Spaceship* spaceship;
    Asteroid* asteroid;
    Missile* missile;
    double screenWidth;
    double screenHeight;
    double accelerationFactor;
    double decelerationFactor;
    double missileSize;

public:
    Model(double screenWidth, double screenHeight, double spaceshipSize, double missileSize);
    ~Model();

    void HandleUserInput(int userInput);
    void Update();
    std::vector<FlyingObject*> GetAllFlyingObjects();

    // Ajoute d'autres méthodes et membres si nécessaire
};

#endif // MODEL_HPP



#endif //ASTEROIDS_PRJ_MODEL_HPP
