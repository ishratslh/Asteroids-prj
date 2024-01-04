//
// Created by Ishra on 23/11/2023.
//
#ifndef ASTEROIDS_PRJ_VIEW_HPP
#define ASTEROIDS_PRJ_VIEW_HPP

#include <vector>
#include <iostream>
#include "FlyingObject.hpp"
#include "Model.hpp"
#include "Framework.hpp"

class View{
    public:
        //////////////////
        // Constructeur
        // -------
        // * framework : pointeur vers le framework
        View(Framework* framework);

        /////////////////
        // Refresh
        // -------
        // * flyingObjects : liste des objets volants
        // * framework : pointeur vers le framework
        void Refresh(std::vector<FlyingObject *>, Framework* framework);


    private :

};
#endif //ASTEROIDS_PRJ_VIEW_HPP
