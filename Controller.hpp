//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_CONTROLLER_HPP
#define ASTEROIDS_PRJ_CONTROLLER_HPP


#include "Model.hpp"
#include "View.hpp"
#include "framework.hpp"

class Controller {
public: //private:
    Model* model;
    View* view;
    Framework* framework;

public:
    Controller(double fps, double shipSize, double missileSize, double screenWidth, double screenHeight);
    ~Controller() {
        delete model;
        delete view;
        delete framework;
    }
    void LaunchGame();

};


#endif //ASTEROIDS_PRJ_CONTROLLER_HPP
