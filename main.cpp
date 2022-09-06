#include "HEADER/cluedo.h"

int main() {

    ///************************************************************************************************************///
    /// Bienvenue dans le jeu "Who Is", inspiré du célèbre jeu Cluedo. Projet d'informatique ECE Lyon 2021-2022    ///
    ///************************************************************************************************************///

    Cluedo cluedo;

    while (cluedo.isRunning()) {
        cluedo.handleEvents();
        cluedo.update();
        cluedo.display();
    }

    ///**************************************************************************************************///
    /// Le fichier de code principal est cluedo.h. Vous pouvez trouver les librairies dans librairies.h  ///
    ///**************************************************************************************************///

    return 0;
}