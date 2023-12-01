//
// Created by Ishra on 23/11/2023.
//

#include "Controller.hpp"

Controller::Controller(double fps, double shipSize, double missileSize):
        model(new Model()), view(new View()), framework(new Framework(fps, shipSize, missileSize)) {}

void Controller::LaunchGame() {
    while (true) {
        int userInput = framework->GetInput();
        if (userInput == SDLK_ESCAPE) {
            break;
        }
        framework->Update(); // Effacer l'écran

        /*model->HandleUserInput(userInput);
        model->Update();

        view->Refresh(model->GetFlyingObjects());*/
    }
}
