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
    UpdateFlyingObjects(framework);
    CheckCollisions();
    return 0;
}
int Model::UpdateFlyingObjects(Framework* framework) {
    Model::GetFlyingObjectsJeu(flyingObjects, framework); //Mise à jour des flyingObjects

    //Dynamic cast des objets de flyingObjects pour l'appel de Move() (car différente selon l'objet)
    for (FlyingObject* element : flyingObjects){
        if (element != nullptr){
            if(element->GetTypeName()=="Asteroid"){
                Asteroid* asteroid = dynamic_cast<Asteroid*>(element);
                asteroid->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
            else if(element->GetTypeName()=="Spaceship"){
                Spaceship* spaceship = dynamic_cast<Spaceship*>(element);
                spaceship->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
            else if (element->GetTypeName() == "Missile"){
                Missile* missile = dynamic_cast<Missile*>(element);
                missile->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
                if (missile->NotOnScreen(framework->GetScreenWidth(), framework->GetScreenHeight())){
                    this->noMissile= true;
                }
            }
        }
    }
    return 0;
}

int Model::CheckCollisions() {
// Vérification des collisions entre tous les objets
    for (int i = 0; i < flyingObjects.size(); ++i) {
        FlyingObject *objet = flyingObjects[i];
        if (objet->GetTypeName() =="Asteroid" && objet != nullptr) { //L'astéroide est le seul objet à pouvoir toucher les deux autres objets donc première boucle
            for (int j = 0; j < flyingObjects.size(); ++j) {
                FlyingObject *autreObjet = flyingObjects[j];
                if (autreObjet->GetTypeName()== "Spaceship" && autreObjet !=nullptr) {
                    bool collisionS = FlyingObject::Collide(objet, autreObjet);
                    if (collisionS) {
                        if (!spaceship->GetInvincible() ){
                            if (spaceship->GetShieldLevel() <= 0) { // si le bouclier du vaisseau est à 0, le vaisseau est détruit
                                std::cout << "Game Over : le vaisseau a été détruit" << std::endl;
                                return -1;
                            } else { // sinon, affaiblir le bouclier du vaisseau
                                spaceship->SetShieldLevel(spaceship->GetShieldLevel() - 0.25);
                                spaceship->SetInvincibleFor(3.0);
                            }
                        } else {
                            // Spaceship Invincible
                        }
                    }
                } else if (autreObjet->GetTypeName() == "Missile" && autreObjet!= nullptr) {
                    bool collisionM = FlyingObject::Collide(objet, autreObjet);
                    if (collisionM) {
                        Asteroid *newAsteroidExplose = dynamic_cast<Asteroid *>(objet); // Cast Asteroid
                        Missile *missile = dynamic_cast<Missile *>(autreObjet); // Cast Missile
                        if (newAsteroidExplose->GetNbExplosionsRestant() >= 2) { //Ajout des 2 new asteroids dans flyingObjects
                            flyingObjects.push_back(newAsteroidExplose->Explosion(newAsteroidExplose->GetXSpeed(),missile->GetAngle()+30));
                            flyingObjects.push_back(newAsteroidExplose->Explosion(newAsteroidExplose->GetYSpeed(),missile->GetAngle()-30));
                        }

                        // Suppression de l'asteroid et du missile
                        flyingObjects.erase(flyingObjects.begin() + j);
                        delete autreObjet; //asteroid
                        nbAsteroids--;
                        flyingObjects.erase(flyingObjects.begin() + i);
                        delete objet; //missile
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
        if (object->GetTypeName() == "Missile" && object != nullptr) {
            noMissile = false;
            break;
        }
    }
    if (noMissile) {
        this->missile = new Missile(spaceship->GetX(), spaceship->GetY(), 10, 30, spaceship->GetAngle());
        flyingObjects.push_back(missile);
        //std::cout << "Spaceship angle: " << spaceship->GetAngle() << std::endl;
        //std::cout << "Missile angle: " << missile->GetAngle() << std::endl;
    }
}

//____________________________________Getters:____________________________________
std::vector<FlyingObject *> Model::GetFlyingObjects() {
    std::vector<FlyingObject*> totalFlyingObjects(flyingObjects.begin(), flyingObjects.end());
    //totalFlyingObjects.insert(totalFlyingObjects.end(), asteroids.begin(), asteroids.end());
    return totalFlyingObjects;
}

std::vector<FlyingObject*> Model::GetFlyingObjectsJeu(std::vector<FlyingObject*>& totalFlyingObjects, Framework* framework) {
    for (auto element = flyingObjects.begin(); element!= flyingObjects.end();) {
        FlyingObject* object = *element;
        // retire le missile de la liste s'il n'est plus à l'écran
        if (object->GetTypeName() == "Missile") {
            Missile* missile = dynamic_cast<Missile*>(object);
            if (missile->NotOnScreen(framework->GetScreenWidth(),framework->GetScreenHeight())) {
                element = flyingObjects.erase(element);
                //delete missile;
                missile = nullptr;
                continue;
            }
        }
        ++element;
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
    //flyingObjects.push_back(newAsteroid);
}
