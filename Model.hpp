//
// Created by Ishra on 23/11/2023.
//
#ifndef ASTEROIDS_PRJ_MODEL_HPP
#define ASTEROIDS_PRJ_MODEL_HPP

#include <vector>
#include <iostream>
#include <random>
#include <SDL_keycode.h>

#include "FlyingObject.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "Framework.hpp"

class Model {

private :
    Spaceship* spaceship; //Vaisseau du joueur
    Missile* missile; //Missile
    int nbAsteroids; //Nombre d'astéroïdes à l'écran
    bool noMissile; //indicateur true s'il n'y a pas de missile à l'écran
    std::vector<FlyingObject *> flyingObjects; //Liste des objets volants du jeu
    std::vector<Asteroid *> asteroids; //Liste des astéroïdes du jeu

public :
    ///////////////
    // Constructeur
    // -------
    // * screenWidth, screenHeight : taille de l'écran
    Model(int screenWidth, int screenHeight);

    /////////////////
    // Getters
    std::vector<FlyingObject *> GetFlyingObjects();
    std::vector<FlyingObject *> GetFlyingObjectsJeu(std::vector<FlyingObject*>& allFlyingObjects, Framework* framework);

    /////////////////
    // Update
    int Update(Framework* framework);
    int UpdateFlyingObjects(Framework* framework);
    int CheckCollisions();

    /////////////////
    // ActionInput
    // -------
    // * input : touche appuyée par l'utilisateur
    void ActionInput(int input);
    void SpeedUp();
    void SpeedDown();
    void RotateRight();
    void RotateLeft();
    void ShootMissile();

    /////////////////
    // Initialisation des asteroïdes aléatoire
    void InitialiseAsteroid(double screenWidth, double screenHeight);
};

#endif //ASTEROIDS_PRJ_MODEL_HPP
