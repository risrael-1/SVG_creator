//
// Created by VIDAL Léo on 06/02/2021.
//

#include <iostream>
#include "Color.h"

// Passage par methode statique car le constructeur par défaut
// d'un objet est automatiquement appeler lorsque celui ci est le membre d'une classe
Color Color::create() {
    bool isConformSaisie;
    do {
        isConformSaisie = false;
        int selection = 0;
        std::cout << "Voici la liste des couleurs possible veuillez en selectionner une : \n";
        std::cout << "1 - Rouge\n";
        std::cout << "2 - Orange\n";
        std::cout << "3 - Vert\n";
        std::cout << "4 - Bleu\n";
        std::cout << "5 - Noir \n";
        std::cin >> selection;
        if(selection < 0 || selection > 5) {std::cout << "Veuillez saisir une couleur proposé";}
        else {
            isConformSaisie = true;
            switch (selection) {
                case 1: return Color("red");
                case 2: return Color("orange");
                case 3: return Color("green");
                case 4: return Color("blue");
                case 5: return Color("black");
                default: break;
            }
        }
    }while(!isConformSaisie);
}


Color::Color(std::string colorName) {
    this->nameColor = colorName;
}

Color::Color() {
    this->nameColor = "";
}

std::string Color::getColorName() {
    return this->nameColor;
}
