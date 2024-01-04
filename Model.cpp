//
// Created by Ishra on 23/11/2023.
//
#include "Model.hpp"
using namespace std;

//____________________________________Constructeur :_______________________________________
Model::Model(int screenWidth, int screenHeight) {
    //Paramètres du spaceship :
    double xS = screenWidth / 4.0;
    double yS = screenHeight / 2.0;
    double sizeS = 60.0;
    double speedXS = 1.0;
    double speedYS = 1.0;
    double angleS = 0.0;
    this->spaceship = new Spaceship(xS,yS,sizeS,speedXS,speedYS, angleS);

    //Generation des asteroides :
    this->nbAsteroids = 5;
    for(int i = 0; i <nbAsteroids; i++){
        InitialiseAsteroid(screenWidth,screenHeight);
    }
    flyingObjects.insert(flyingObjects.end(), asteroids.begin(), asteroids.end());

    // Ajout du spaceship à la liste des flyingObjects
    flyingObjects.push_back(spaceship);

    this->noMissile=false;
}


//____________________________________Update :_______________________________________
int Model::Update(Framework* framework) {
    //Mise à jour des flyingObjects:
    Model::GetFlyingObjectsJeu(flyingObjects, framework);

    //Dynamic cast des objets de flyingObjects pour l'appel de Move() (car différente selon l'objet)
    for (FlyingObject* object : flyingObjects){
        if (object != nullptr){
            if (object->GetTypeName() == "Missile"){
                Missile* missile = dynamic_cast<Missile*>(object);
                missile->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
                if (missile->NotOnScreen(framework->GetScreenWidth(), framework->GetScreenHeight())){
                    this->noMissile= true;
                }
            }
            else if(object->GetTypeName()=="Asteroid"){
                Asteroid* asteroid = dynamic_cast<Asteroid*>(object);
                asteroid->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
            else if(object->GetTypeName()=="Spaceship"){
                Spaceship* spaceship = dynamic_cast<Spaceship*>(object);
                spaceship->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
        }

    }

    // Vérification des collisions entre tous les objets
    for (int i = 0; i < flyingObjects.size(); ++i) {
        FlyingObject* object = flyingObjects[i];
        if (object != nullptr && object->GetTypeName() == "Asteroid") {
            for (int j = 0; j < flyingObjects.size(); ++j) {
                FlyingObject* otherObject = flyingObjects[j];
                if (otherObject != nullptr && otherObject->GetTypeName() == "Missile") {
                    bool collisionWithMissile = FlyingObject::Collide(object, otherObject);
                    if (collisionWithMissile) {
                        //Dynamic cast to access the specific functions
                        Asteroid* asteroidToExplode = dynamic_cast<Asteroid*>(object); // Cast to Asteroid
                        Missile* missile = dynamic_cast<Missile*>(otherObject); // Cast to Missile
                        //To avoid nullptr in the list
                        if(asteroidToExplode->GetNbExplosionsRestant()>=2){
                            //Add the two other asteroids
                            flyingObjects.push_back(asteroidToExplode->Explode(asteroidToExplode->GetXSpeed(),missile->GetAngle()+30));
                            flyingObjects.push_back(asteroidToExplode->Explode(asteroidToExplode->GetYSpeed(),missile->GetAngle()-30));
                        }

                        // Remove Missile from the vector
                        flyingObjects.erase(flyingObjects.begin() + j);
                        delete otherObject;
                        nbAsteroids--;
                        // Delete the asteroid object
                        flyingObjects.erase(flyingObjects.begin() + i);
                        delete object;
                    }
                }
                else if (otherObject != nullptr && otherObject->GetTypeName() == "Spaceship") {
                    bool collisionWithSpaceship = FlyingObject::Collide(object, otherObject);
                    if (collisionWithSpaceship) {
                        //Reduce shield of spaceship
                        if (!spaceship->GetInvincible()) {
                            // Check if shield is zero and handle destruction if needed
                            if(spaceship->GetShieldLevel() <= 0){
                                //Exit Game
                                return -1;
                            }
                            else {
                                // Reduce the shield of the spaceship
                                spaceship->SetShieldLevel(spaceship->GetShieldLevel()-0.25);
                                spaceship->SetInvincibleFor(3.0);
                            }
                        }
                        else {
                            // Spaceship Invincible
                        }
                    }
                }
            }
        }
    }
    return 0;
}


//____________________________________Actions :_______________________________________
void Model::ActionInput(int input) {
    switch (input) {
        case SDLK_UP: //si la touche appuyée est la flèche du haut, on augmente la vitesse du vaisseau
            Model::SpeedUp();
            break;
        case SDLK_DOWN: //si la touche appuyée est la flèche du bas, on diminue la vitesse du vaisseau
            Model::SpeedDown();
            break;
        case SDLK_LEFT: //si la touche appuyée est la flèche de gauche, on fait pivoter le vaisseau vers la gauche
            Model::RotateLeft();
            break;
        case SDLK_RIGHT: //si la touche appuyée est la flèche de droite, on fait pivoter le vaisseau vers la droite
            Model::RotateRight();
            break;
        case SDLK_SPACE: //si la touche appuyée est la barre d'espace, on tire un missile
            Model::ShootMissile();
            break;
        case SDLK_ESCAPE: //si la touche appuyée est la touche échap, on quitte le jeu
            SDL_Quit();
            std::cout << "Game Over : abandon du joueur" << std::endl;
            exit(0);
            break;
    }
}

void Model::SpeedUp() {
    spaceship->SpeedUp(10);
}
void Model::SpeedDown() {
    spaceship->SpeedDown(10);
}
void Model::RotateLeft() {
    spaceship->Rotate(-20);
}
void Model::RotateRight() {
    spaceship->Rotate(20);
}
void Model::ShootMissile() {
    bool noMissile = true;
    for (const FlyingObject* object : flyingObjects) {
        if (object != nullptr && object->GetTypeName() == "Missile") {
            noMissile = false;
            break;
        }
    }
    if (noMissile) {
        this->missile = new Missile(spaceship->GetX(), spaceship->GetY(), 10, 30, spaceship->GetAngle());
        flyingObjects.push_back(missile);
        std::cout << "Spaceship angle: " << spaceship->GetAngle() << std::endl;
        std::cout << "Missile angle: " << missile->GetAngle() << std::endl;
    }
}

//____________________________________Getters:____________________________________
std::vector<FlyingObject *> Model::GetFlyingObjects() {
    std::vector<FlyingObject*> allFlyingObjects(flyingObjects.begin(), flyingObjects.end());
    //Add the list of vectors of asteroids
    //allFlyingObjects.insert(allFlyingObjects.end(), asteroids.begin(), asteroids.end());
    return allFlyingObjects;
}

std::vector<FlyingObject*> Model::GetFlyingObjectsJeu(std::vector<FlyingObject*>& allFlyingObjects, Framework* framework) {
    // Check all the objects in the game
    for (auto it = flyingObjects.begin(); it != flyingObjects.end();) {
        FlyingObject* object = *it;

        // Check if the object is a missile
        if (object->GetTypeName() == "Missile") {
            Missile* missile = dynamic_cast<Missile*>(object);

            // Check if the missile is not on the screen
            if (missile->NotOnScreen(framework->GetScreenWidth(), framework->GetScreenHeight())) {
                it = flyingObjects.erase(it); // Remove the missile from flyingObjects
                //delete missile;
                missile = nullptr;
                continue;
            }
        }
        ++it;
    }
    return flyingObjects;
}

void Model::InitialiseAsteroid(double screenWidth, double screenHeight) {
    //---Initialisation des variables - distribution espace :
    std::uniform_int_distribution<int> spaceDistribution(0, 7);
    std::random_device generator;
    int espace = spaceDistribution(generator);
    std::uniform_real_distribution<double> xDistribution(0.0, screenWidth);
    std::uniform_real_distribution<double> yDistribution(0.0, screenHeight);

    if(espace == 0){
        std::uniform_real_distribution<double> xDistribution(0.0,screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(0.0,screenHeight/3);
    }
    else if(espace == 1){
        std::uniform_real_distribution<double> xDistribution(screenWidth/3,2*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(0.0,screenHeight/3);
    }
    else if(espace == 2){
        std::uniform_real_distribution<double> xDistribution(2*screenWidth/3,3*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(0.0,screenHeight/3);
    }
    else if(espace == 3){
        std::uniform_real_distribution<double> xDistribution(0.0,screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(screenHeight/3,2*screenHeight/3);
    }
    else if(espace == 4){
        std::uniform_real_distribution<double> xDistribution(2*screenWidth/3,3*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(screenHeight/3,2*screenHeight/3);
    }
    else if(espace == 5){
        std::uniform_real_distribution<double> xDistribution(0.0,screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(2*screenHeight/3,3*screenHeight/3);
    }
    else if(espace == 6){
        std::uniform_real_distribution<double> xDistribution(screenWidth/3,2*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(2*screenHeight/3,3*screenHeight/3);
    }
    else if(espace == 7){
        std::uniform_real_distribution<double> xDistribution(2*screenWidth/3,3*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(2*screenHeight/3,3*screenHeight/3);
    }

    double x = xDistribution(generator);
    double y = yDistribution(generator);
    std::uniform_int_distribution<int> angleValues(-180, 180);
    int angle = angleValues(generator);

    Asteroid* newAsteroid = new Asteroid(x,y,100, 10, 3, angle, 2);
    asteroids.push_back(newAsteroid);//ajout de l'asteroid à la liste des asteroids
    //flyingObjects.push_back(asteroidGenerated);
}
