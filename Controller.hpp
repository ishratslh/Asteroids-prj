//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_CONTROLLER_HPP
#define ASTEROIDS_PRJ_CONTROLLER_HPP


#include "Model.hpp"
#include "View.hpp"
#include "framework.hpp"

class Controller {
public:
    Model* model;
    View* view;
    Framework* framework;

public:
    Controller(double fps, double shipSize, double missileSize);
    void LaunchGame();

};


#endif //ASTEROIDS_PRJ_CONTROLLER_HPP
