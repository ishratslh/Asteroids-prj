//
// Created by Ishra on 23/11/2023.
//

#include "Controller.hpp"

Controller::Controller(double fps, double shipSize, double missileSize, double screenWidth, double screenHeight):
        model(new Model(screenWidth, screenHeight)), view(new View()), framework(new Framework(fps, shipSize, missileSize)) {}

void Controller::LaunchGame() {
    while (true) {
        int userInput = framework->GetInput();
        if (userInput == SDLK_ESCAPE) {
            break;
        }
        framework->Update(); // Effacer l'écran

        model->HandleUserInput(userInput);
        model->Update();

        framework->Update();
    }
}
