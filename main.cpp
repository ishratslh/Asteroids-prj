#include <iostream>
#include "framework.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"

#include <string>
#include "include/SDL2/SDL.h"


//int WinMain(int argc, char* argv[])
int main(int argc, char* argv[]){
        std::cout << "Hello asteroids!" << std::endl;
        Framework * fw = new Framework(20, 60, 60);

        double xA = fw->GetScreenWidth() / 2.0;
        double yA = fw->GetScreenHeight() / 2.0;
        double sizeA = 70.0;
        double xSpeedA = 5.0;
        double ySpeedA = 5.0;
        bool destroyAsteroid = false;

        double xM = fw->GetScreenWidth() / 4.0;
        double yM = fw->GetScreenHeight() / 2.0;
        double sizeM = 60.0;
        double speedM = 5.0;
        double angleM = 0.0;
        bool destroyMissile = false;

        Asteroid *asteroid = new Asteroid(xA, yA,sizeA,xSpeedA,ySpeedA);
        Missile *missile = new Missile(xM,yM,sizeM,speedM,angleM);

        while (true) {
            if (fw->GetInput() == SDLK_ESCAPE) {
                break;
            }
            fw->Update(); //effacer écran

            //1 Prendre en main le Framework d’affichage : missile au centre de l'écran
            /*int screenWidth = fw->GetScreenWidth();
            int screenHeight = fw->GetScreenHeight();
            fw->DrawMissile(screenWidth / 2, screenHeight / 2);*/

            //2 Créer une classe Asteroid
            if (asteroid) {
                //asteroid->Move(fw->GetScreenWidth(), fw->GetScreenHeight());
                fw->DrawAsteroid(static_cast<int>(asteroid->GetX()), static_cast<int>(asteroid->GetY()),static_cast<int>(asteroid->GetSize()));
            }

            //3 Créer une classe Missile
            if(missile) {
                missile->Move(fw->GetScreenWidth(), fw->GetScreenHeight());
                fw->DrawMissile(static_cast<int>(missile->GetX()), static_cast<int>(missile->GetY()));
            }
            //4 Implémentation d'une collision - destruction des objets
            if (asteroid && missile) {
                if (FlyingObject::Collide(*asteroid, *missile)) {
                    std::cout << "Hello collision?" << std::endl;
                    destroyAsteroid = true;
                    destroyMissile = true;
                }
            }

            //Si le missile sort de l'écran, il est détruit
            if (missile) {
                bool outOfScreen = missile->Move(fw->GetScreenWidth(), fw->GetScreenHeight());
                if (outOfScreen) {
                    std::cout << "Hello missile out of screen" << std::endl;
                    destroyMissile = true;
                }
            }

            if (destroyMissile) {
                if (missile) {
                    std::cout << "Deleting missile" << std::endl;
                    delete missile;
                    missile = nullptr;
                }
            }

            if (destroyAsteroid) {
                if (asteroid) {
                    std::cout << "Deleting asteroid" << std::endl;
                    delete asteroid;
                    asteroid = nullptr;
                }
            }
            std::cout << "Gestion memoire:asteroid " << asteroid << ", Missile: " << missile << std::endl;

            //5 Class SpaceShip
            double xS = fw->GetScreenWidth() / 4.0;
            double yS = fw->GetScreenHeight() / 2.0;
            double sizeS = 60.0;
            double speedS = 5.0;
            double angleS = 0.0;
            bool warning = false;
            fw->DrawShip(static_cast<int>(xS), static_cast<int>(yS), static_cast<float>(angleS), 0.0, warning);

        }
        delete fw;
        return 0;
}