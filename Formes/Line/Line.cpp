//
// Created by VIDAL Léo on 28/01/2021.
//

#include <iostream>
#include "Line.h"

Line::Line(Point a, Point b, Color color) {
    this->a = a;
    this->b = b;
    this->color = color;
}

// Passage par methode statique car le constructeur par défaut
// d'un objet est automatiquement appeler lorsque celui ci est le membre d'une classe
Line Line::create() {
    Point a;
    Point b;
    Color color;
    std::cout << "Afin de créer un segment nous aurons besoin de trois informations : \n";
    std::cout << "- Un point A \n";
    std::cout << "- Un Point B \n";
    std::cout << "- Une couleur\n";
    std::cout << " Tout d'abord commençon par créer le point A : \n";
    a = Point::create();
    std::cout << " Maintenant passons au point B :  \n";
    b = Point::create();
    std::cout << "Et pour finir veuiller choisir la couleur :";
    color = Color::create();
    return Line(a,b,color);
}

Line::Line() {}

Point Line::getA() {return this->a;}
Point Line::getB() {return this->b;}

void Line::draw(std::string fileName) {
    std::ofstream mySvg;
    mySvg.open(fileName, std::ios::app);
    mySvg << "<line ";
    mySvg << "x1=\"" << this->getA().getX() << "\" y1=\"" << this->getA().getY() << "\" ";
    mySvg << "x2=\"" << this->getB().getX() << "\" y2=\"" << this->getB().getY() << "\" ";
    mySvg << "stroke=\"" << this->color.getColorName() << "\" ";
    mySvg << "stroke-width=\"4\" ";
    mySvg << "/>\n";
    mySvg.close();
}

