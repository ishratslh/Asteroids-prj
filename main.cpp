#include <iostream>
#include "framework.hpp"
#include "Asteroid.hpp"

#include <string>
#include "include/SDL2/SDL.h"


int WinMain(int argc, char* argv[])
//int main(int argc, char* argv[])
{
        std::cout << "Hello asteroids!" << std::endl;
        Framework * fw = new Framework(20, 60, 20);
        Asteroid asteroid(
            fw->GetScreenWidth() / 2.0, // centre
            fw->GetScreenHeight() / 2.0,
            70.0,
            1.0,  // Vitesse en x
            1.0   // Vitesse en y
        );

        while (true) {
            if (fw->GetInput() == SDLK_ESCAPE) {
                break;
            }
            //printf("test\n");

            fw->Update(); //effacer écran

            //1 Prendre en main le Framework d’affichage : missile au centre de l'écran
            /*int screenWidth = fw->GetScreenWidth();
            int screenHeight = fw->GetScreenHeight();
            fw->DrawMissile(screenWidth / 2, screenHeight / 2);*/

            //2 Créer une classe Asteroid
            asteroid.Move(fw->GetScreenWidth(), fw->GetScreenHeight());
            fw->DrawAsteroid(static_cast<int>(asteroid.GetX()), static_cast<int>(asteroid.GetY()), static_cast<int>(asteroid.GetSize()));

            //3 Créer une classe Missile

        }
        delete fw;
        return 0;
}