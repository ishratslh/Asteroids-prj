//
// Created by Ishra on 23/11/2023.
//

#include "View.hpp"

View::View() {}
View::View(Framework* fw) {
    this->framework = fw;
}

void View::RefreshDisplay(const std::vector<FlyingObject*>& flyingObjects) {
    for (const auto& obj : flyingObjects) {
        if (obj) {
            std::string typeName = obj->GetTypeName();

            if (typeName == "Spaceship") {
                Spaceship* spaceship = dynamic_cast<Spaceship*>(obj);
                if (spaceship) {
                    // Utilise le framework pour dessiner le vaisseau
                    framework->DrawShip(static_cast<int>(spaceship->GetX()), static_cast<int>(spaceship->GetY()), static_cast<float>(spaceship->GetAngle()), 0.0, false);
                }
            } else if (typeName == "Asteroid") {
                Asteroid* asteroid = dynamic_cast<Asteroid*>(obj);
                if (asteroid) {
                    // Utilise le framework pour dessiner l'astéroïde
                    framework->DrawAsteroid(static_cast<int>(asteroid->GetX()), static_cast<int>(asteroid->GetY()), static_cast<int>(asteroid->GetSize()));
                }
            } else if (typeName == "Missile") {
                Missile* missile = dynamic_cast<Missile*>(obj);
                if (missile) {
                    // Utilise le framework pour dessiner le missile
                    framework->DrawMissile(static_cast<int>(missile->GetX()), static_cast<int>(missile->GetY()));
                }
            }
        }
    }

}