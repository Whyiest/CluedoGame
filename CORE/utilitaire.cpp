#ifndef CLUEDO_UTILITAIRE_H
#define CLUEDO_UTILITAIRE_H

#include "../HEADER/libraries.h"

using namespace std;

/*---------------------------------------------------------------------------------------------------------------------------*/
/* Bibliothèque créée dans le but de regrouper des fonctions utile au développement du jeu
/*  Seules les fonctions random et map sont copiées d'internet.
/*---------------------------------------------------------------------------------------------------------------------------*/




namespace util {

    void displayText(float startX, float startY, float size, string textContent, string fontPath, sf::RenderWindow *window) {

        ///******************************************************************************************************//
        /// Permet d'afficher un texte simplement                                                                //
        ///*****************************************************************************************************//

        sf::Font font;
        sf::Text text;

        font.loadFromFile(fontPath);

        text.setFont(font);
        text.setString(textContent);
        text.setCharacterSize(size);
        text.setPosition(startX, startY);
        window->draw(text);

    }


    // Proviens de la documention orignal de SMFL https://en.sfml-dev.org/forums/index.php?topic=24954.0
    // Permet de rendre les images "Responsive", c'est à dire qu'elle veux s'adapter à la taille de l'écran

    void resizeImage(const sf::Image &originalImage, sf::Image &resizedImage) {

        const sf::Vector2u originalImageSize{originalImage.getSize()};
        const sf::Vector2u resizedImageSize{resizedImage.getSize()};
        for (unsigned int y{0u}; y < resizedImageSize.y; ++y) {
            for (unsigned int x{0u}; x < resizedImageSize.x; ++x) {
                unsigned int origX{
                        static_cast<unsigned int>(static_cast<double>(x) / resizedImageSize.x * originalImageSize.x)};
                unsigned int origY{
                        static_cast<unsigned int>(static_cast<double>(y) / resizedImageSize.y * originalImageSize.y)};
                resizedImage.setPixel(x, y, originalImage.getPixel(origX, origY));
            }
        }
    }




    sf::Image newImage(std::string path, int resizedWidth, int resizedHeight) {

        ///******************************************************************************************************//
        /// Fait la même chose que la fonction ci-desus, à la différence près qu'elle initialise aussi l'image  //
        ///*****************************************************************************************************//

        sf::Image originalImage;
        sf::Image resizedImage;
        resizedImage.create(resizedWidth, resizedHeight);
        if (!originalImage.loadFromFile(path)) std::cerr;

        util::resizeImage(originalImage, resizedImage);

        return resizedImage;
    }


    int random(int min, int max) {

        ///**************************************************************************************************//
        /// Génére un nombre aléatoire compris entre ses deux bornes.                                        //
        ///**************************************************************************************************//

        static std::mt19937 randGen(time(nullptr));
        return std::uniform_int_distribution<>(min, max)(randGen);
    }

    float map(float n, float min1, float max1, float min2, float max2) {

        ///**************************************************************************************************//
        /// Permet de faire un mapping                                                                       //
        ///**************************************************************************************************//

        return n = min2 + (max2 - min2) * ((n - min1) / (max1 - min1));
    }


    bool intIsPresentIn(int data, std::vector<int> array) {

        ///******************************************************************************************************//
        /// Permet de vérifier la présence d'un nombre dans un ensemble de nombre.                              //
        ///*****************************************************************************************************//

        for (int i = 0; i < array.size(); ++i) {
            if (array[i] == data) return true;
        }
        return false;
    }
}

#endif