//
// Created by Ishra on 23/11/2023.
//

#include "Controller.hpp"

using namespace std;

//____________________________________Constructeur :_______________________________________

Controller::Controller(int fps, int shipSize, int missileSize){
    this->view = new View(framework);
    this->framework = new Framework(fps,shipSize,missileSize);
    this->model = new Model(framework->GetScreenWidth(),framework->GetScreenHeight());
}

void Controller::LaunchGame() {
    while(true){
        model->ActionInput(framework->GetInput());

        //si le ship a été détruit, fin de jeu
        int resUpdate = model->Update(framework);
        if (resUpdate==-1){
            std::cout << "Fin de jeu : vous avez perdu !" << std::endl;
            exit(-1);
        }
        else if(resUpdate==0){
            //std::cout << "You won !" << std::endl;
        }
        else continue;

        view->Refresh(model->GetFlyingObjects(),framework);
    }

}

//____________________________________Getters :_______________________________________
Framework* Controller::GetFramework() {
    return this->framework;
}
Model* Controller::GetModel() {
    return this->model;
}
View* Controller::GetView() {
    return this->view;
}
