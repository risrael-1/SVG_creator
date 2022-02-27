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

void afficheDraw() {
    std::string name;
    std::cout << BOLD(FBLU("Merci d'entrer le nom de votre fichier : \n \n"));
    std::cin >> name;
    std::string fileName = name + ".svg";
    std::ifstream file;
    file.open(fileName);
    if (!file.good())
    {
        std::cout << "Ouverture ipossible" << std::endl;
    }else{
        std::string line;
        while (std::getline(file, line)) {
            printf( BOLD(FYEL("%s")),line.c_str() );
        }
        file.close();
    }
}

void populateDraw(Draw* draw) {
    bool stopPopulate = false;
    draw->createForme();
}

int main() {
    std::cout << UNDL(FWHT("\n Bienvenue dans SVG Creator le générateur de dessin \n"));
    int selectedactions;
    do {
        std::cout << BOLD(FCYN("Créer une forme 1\n"));
        std::cout << BOLD(FMAG("Afficher le contenu d'un dessin 2\n"));
        std::cout << BOLD(FMAG("Sauvegarder un dessin 3\n"));
        std::cout << BOLD(FMAG("Fusionner deux dessins 4\n"));
        std::cin >> selectedactions;
    }while(selectedactions != 1 && selectedactions != 2 && selectedactions != 3 && selectedactions != 4);
    switch(selectedactions){
        case 1: { Draw draw = createDraw();
        populateDraw(&draw);
        std::string result = draw.createSvg();
        std::cout << "Nom du fichier : " << result;
        break;}
        case 2: {afficheDraw();
            break;}
        //case 3: {break;}
        //case 4: {break;}
        default: {break;}
    }
    return 0;
}


