#ifndef CLUEDO_LIBRARIES_H
#define CLUEDO_LIBRARIES_H

///**************************************************************************************************************//
/// BOUTON D'ACTIVATION DU DEBUG : ACTIF SI =1 (NE PAS LAISSER SUR 1 POUR UNE PARTIE NORMAL : DEV ONLY)          //
///  Si activé, le plateau de debug s'affiche, les skins ne sont plus affichés, et le WalkPower est illimité.    //
///**************************************************************************************************************//

#define ENABLEDEBUG 0


///**************************************************************************************************************//
/// Cette bibliothèque contient la partie utile de SFML, ainsi que les fonctions standarts que nous utiliserons  //
///**************************************************************************************************************//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <random>

///**************************************************************************************************//
///                            Taille de l'écran : manipuler avec précaution                         //
///**************************************************************************************************//

#define width 1800//1700
#define height 950//880
#define margin 200

#endif