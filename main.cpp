#include <iostream>
#include "include/SDL2/SDL.h"
#include "framework.hpp"
#include "Controller.hpp"

using namespace std;

int main(int argc, char* argv[]){
    std::cout << "Bienvenue chez EFREIRoids, cher terrien :)" << std::endl;
    Controller controller(20,60,10);
    controller.LaunchGame();

    return 0;
}