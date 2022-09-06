#include "../HEADER/cards.h"

///*************************************************************************************************************************//

Card::Card(string thisCardType) {

    if (thisCardType != "weaponCard" || thisCardType != "roomCard" || thisCardType != "playerCard") {

        std::cout << "Critical error : error in the type of the card : aborting creation.";
        return;
    } else {
        m_cardtype = thisCardType;
    }
}

Card::Card(string thisCardType, string thisCardAttribut, sf::Texture thisCardTexture, sf::Sprite thisCardSprite) {
    if (thisCardType != "weaponCard" && thisCardType != "roomCard" && thisCardType != "playerCard") {

        std::cout << "Erreur dans la creation de " << thisCardAttribut << " : le type " << thisCardType
                  << " n'est pas reconnu. Abandon de la creation.\n";
        return;
    } else {
        m_cardtype = thisCardType;
        m_cardSprite = thisCardSprite;
        m_cardTexture = thisCardTexture;
        m_attribut = thisCardAttribut;
    }
}


///*************************************************************************************************************************//

void Card::display(int startX, int startY, sf::RenderWindow *window) {

    ///**************************************************************************************************//
    /// Permet d'afficher la carte depuis laquelle la méthode est appelée                                //
    ///**************************************************************************************************//

    m_cardSprite.setPosition(startX, startY);
    window->draw(m_cardSprite);
}

string Card::getType() {

    return m_cardtype;
}

string Card::getAttribut() {
    return m_attribut;
}



sf::Sprite Card::getSprite() {
    return m_cardSprite;
}





