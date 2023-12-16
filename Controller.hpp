//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_CONTROLLER_HPP
#define ASTEROIDS_PRJ_CONTROLLER_HPP


#include <stdio.h>
#include <string>
#include "Model.hpp"
#include "View.hpp"
#include "Framework.hpp"


class Controller {
public :

    //---------------------Constructor :
    Controller(int fps, int shipSize, int missileSize);

    void LaunchGame();

    //-------------Getters :
    Framework* GetFramework();

private :
    Model* model;
    Framework* framework;
    View* view;

};
#endif //ASTEROIDS_PRJ_CONTROLLER_HPP
