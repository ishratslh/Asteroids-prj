//
// Created by Ishra on 23/11/2023.
//

#ifndef ASTEROIDS_PRJ_CONTROLLER_HPP
#define ASTEROIDS_PRJ_CONTROLLER_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include "Model.hpp"
#include "View.hpp"
#include "Framework.hpp"

class Controller {
    private :
        Model* model; // modèle du jeu
        Framework* framework; // framework du jeu
        View* view; // vue du jeu

    public :
        //////////////////
        // Constructeur
        // -------
        // * fps : nombre d'images par seconde
        // * shipSize : taille du vaisseau
        // * missileSize : taille des missiles
        Controller(int fps, int shipSize, int missileSize);

        /////////////////
        // Lancement du jeu
        void LaunchGame();

        /////////////////
        // Getters
        Framework* GetFramework();
        Model* GetModel();
        View* GetView();
};
#endif //ASTEROIDS_PRJ_CONTROLLER_HPP
