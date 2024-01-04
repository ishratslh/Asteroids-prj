//
// Created by Ishra on 23/11/2023.
//

#include <iostream>
#include "Controller.hpp"

using namespace std;

//------------------Constructors :

Controller::Controller(int fps, int shipSize, int missileSize){

    this->view = new View(framework);
    this->framework = new Framework(fps,shipSize,missileSize);
    this->model = new Model(framework->GetScreenWidth(),framework->GetScreenHeight());

}


void Controller::LaunchGame() {

    while(true){
        model->ChooseAction(framework->GetInput());

        int resultModelUpdate = model->Update(framework);
        std::cout << "You lost !" << std::endl;
        if (resultModelUpdate==-1){
            exit(-1);
        }
        else if(resultModelUpdate==0){
            std::cout << "You won !" << std::endl;
        }
        else {
            continue;
        }

        view->Refresh(model->GetFlyingObjects(),framework);
    }

}
