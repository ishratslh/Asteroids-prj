//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_VIEW_HPP
#define ASTEROIDS_PRJ_VIEW_HPP

#include <vector>
#include "FlyingObject.hpp"
#include "Model.hpp"
#include "framework.hpp"

class View{


public:

    //---------------------Constructor :
    View(Framework* framework);

    void Refresh(std::vector<FlyingObject *>, Framework* framework);


private :



};
#endif //ASTEROIDS_PRJ_VIEW_HPP
