//
// Created by Ishra on 23/11/2023.
//

#include "Model.hpp"


Model::Model(double screenWidth, double screenHeight, double spaceshipSize, double missileSize) {
    // Initialiser le vaisseau, le missile et l'astéroïde avec les paramètres donnés
    spaceship = new Spaceship(screenWidth / 4.0, screenHeight / 2.0, spaceshipSize, 1.0, 1.0, 0.0);
    asteroid = new Asteroid(screenWidth / 2.0, screenHeight / 2.0, 70.0, 0.0, 0.0);
    missile = nullptr; // Initialement, le missile n'est pas tiré
}

Model::~Model() {
    // Libérer la mémoire des objets créés
    delete spaceship;
    delete asteroid;
    if (missile) {
        delete missile;
    }
}

void Model::HandleUserInput(int userInput) {
    // Implémenter la logique pour gérer les différentes actions du joueur
    if (userInput == SDLK_UP) {
        spaceship->SpeedUp(accelerationFactor);
    }
    if (userInput == SDLK_DOWN) {
        spaceship->SpeedDown(decelerationFactor);
    }
    if (userInput == SDLK_SPACE) {
        // Tirer un missile si aucun missile n'est déjà en jeu
        if (!missile) {
            missile = new Missile(spaceship->GetX(), spaceship->GetY(), missileSize, 5.0, spaceship->GetAngle());
        }
    }
    // Ajouter d'autres actions selon les besoins
}

void Model::Update() {
    // Mettre à jour les données du modèle, c'est-à-dire calculer les nouvelles coordonnées des objets

    // Mettre à jour le vaisseau
    spaceship->Move(screenWidth, screenHeight);

    // Mettre à jour l'astéroïde
    asteroid->Move(screenWidth, screenHeight);

    // Mettre à jour le missile s'il est en jeu
    if (missile) {
        bool outOfScreen = missile->Move(screenWidth, screenHeight);
        if (outOfScreen) {
            // Supprimer le missile s'il sort de l'écran
            delete missile;
            missile = nullptr;
        }
    }

    // Vérifier la collision entre le missile et l'astéroïde
    if (missile && FlyingObject::Collide(*asteroid, *missile)) {
        // Détruire l'astéroïde et le missile en cas de collision
        delete asteroid;
        delete missile;
        asteroid = nullptr;
        missile = nullptr;
    }
}

std::vector<FlyingObject*> Model::GetAllFlyingObjects() {
    std::vector<FlyingObject*> flyingObjects;

    // Ajouter le vaisseau, l'astéroïde et le missile (s'il est en jeu) au vecteur
    flyingObjects.push_back(spaceship);
    flyingObjects.push_back(asteroid);
    if (missile) {
        flyingObjects.push_back(missile);
    }

    return flyingObjects;
}