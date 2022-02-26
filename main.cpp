#include <iostream>
#include <math.h>
#include <stdio.h>
#include "Utils/TerminalColors.h"

#include "Draw/Draw.h"

Draw createDraw() {
    int hauteur;
    int largeur;
    std::string drawName;
    bool validData = false;
    std::cout << BOLD(FBLU("Pour commencer veuillez entrez le nom de votre dessin : \n \n"));
    std::cin >> drawName;
    std::cout << "\n";
    do {
        std::cout << "Veuiller choisir la hauteur de votre dessin : \n";
        std::cin >> hauteur;
        std::cout << "Veuiller choisir la largeur de votre dessin : \n";
        std::cin >> largeur;
        if(hauteur <= 0 || largeur <= 0) std::cout << "Veuillez saisir une taille supérieur à 0\n";
        else validData = true;
    }while(!validData);

    return Draw(largeur, hauteur, drawName);
}


void populateDraw(Draw* draw) {
    bool stopPopulate = false;
    draw->createForme();
}

int main() {
    std::cout << UNDL(FWHT("\n Bienvenue dans SVG Creator le générateur de dessin \n"));
    Draw draw = createDraw();
    populateDraw(&draw);
    std::string result = draw.createSvg();
    std::cout << "file created name : " << result;
    return 0;
}


