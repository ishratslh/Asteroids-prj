//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_VIEW_HPP
#define ASTEROIDS_PRJ_VIEW_HPP

#include "Framework.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include <vector>
#include <string>
#include "include/SDL2/SDL.h"
#include <iostream>

class View {
    private:
        Framework* framework;

    public:
        View();
        View(Framework* fw);
        void RefreshDisplay(const std::vector<FlyingObject*>& flyingObjects);
};


#endif //ASTEROIDS_PRJ_VIEW_HPP
