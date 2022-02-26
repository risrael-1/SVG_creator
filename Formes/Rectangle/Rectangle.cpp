#include <iostream>
#include "Rectangle.h"

// Passage par me10thode statique car le constructeur par défaut
// d'un objet est automatiquement appeler lorsque celui ci est le membre d'une classe
Rectangle Rectangle::create() {
    int L;
    int H;
    Point corner;
    Color color;
    std::cout << "Afin de créer un rectangle nous aurons besoin de trois informations : \n";
    std::cout << "- La hauteur : \n";
    std::cout << "- La largeur \n";
    std::cout << "- Une couleur \n";
    std::cout << "- Et le point correspondant au coin supérieur du rectangle \n";
    std::cout << " Tout d'abord veuillez saisir la hauteur : ";
    std::cin >> L;
    std::cout << "\n Maintenant la largeur : ";
    std::cin >> H;
    std::cout << "\n Passons a la couleur de votre rectangle";
    color = Color::create();
    std::cout << "\n Et pour finir la création du coin supérieur :";
    corner = Point::create();
    return Rectangle(H, L, corner,color);
}

Rectangle::Rectangle(int hauteur, int largeur, Point topCorner, Color color) {
    this->hauteur = hauteur;
    this->largeur = largeur;
    this->topCorner = topCorner;
    this->color = color;
}

Rectangle::Rectangle() {
    this->hauteur = 1;
    this->largeur = 1;
}


int Rectangle::getHauteur() {return this->hauteur;}
int Rectangle::getLargeur() {return this->largeur;}
Point Rectangle::getCorner() {return this->topCorner;}

void Rectangle::draw(std::string fileName) {
    std::cout << "tyty : \n";
    std::ofstream mySvg;
    mySvg.open(fileName, std::ios::app);
    mySvg << "<rect ";
    mySvg << "x=\"" << this->topCorner.getX() << "\" " << "y=\"" << this->topCorner.getY() << "\" ";
    mySvg << "width=\"" << this->largeur << "\" " << "height=\"" << this->hauteur << "\" ";
    mySvg << "fill=\"" << this->color.getColorName() << "\" ";
    mySvg << "stroke-width=\"4\" ";
    mySvg << "/>\n";
    mySvg.close();
}


