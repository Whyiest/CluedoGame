/*---------------------------------------------------------------------------------------------------------------------------*/
/* Bibliothèque créée dans le but de regrouper des fonctions utile au développement du jeu
/*  Seules les fonctions random et map sont copiées d'internet. La classe vector est inspirée de la classe PVector de processing
/*---------------------------------------------------------------------------------------------------------------------------*/

#ifndef CLUEDO_UTILITAIRE_H
#define CLUEDO_UTILITAIRE_H

#include "libraries.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cmath>
#include "player.h"

namespace util {


    void resizeImage(const sf::Image &originalImage,sf::Image &resizedImage); //https://en.sfml-dev.org/forums/index.php?topic=24954.0

    sf::Image newImage(std::string path, int resizedWidth, int resizedHeight);

    int random(int min, int max);

    float map(float n, float min1, float max1, float min2, float max2);

    bool intIsPresentIn(int data, std::vector<int> array);

    void displayText (float startX, float startY, float size, string textContent, string fontPath, sf::RenderWindow* window );

}

#endif