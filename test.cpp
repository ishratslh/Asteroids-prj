#include "framework.hpp"

// EFREIRoid
int main(int argc, char* argv[]) {
        Framework * fw = new Framework(100, 60, 20);
        while (true) {
            // clavier

            

            fw->Update();
        }
}