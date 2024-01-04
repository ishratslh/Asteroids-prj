#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "include/SDL2/SDL.h"
#include "framework.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include "Spaceship.hpp"
#include "Controller.hpp"

using namespace std;


//int WinMain(int argc, char* argv[])
int main(int argc, char* argv[]){
    std::cout << "Opening EFREI-Roids !" << std::endl;

    Controller controller(20,60,10);
    controller.LaunchGame();

    return 0;
}