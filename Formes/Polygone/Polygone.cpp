//
// Created by Dima on 09/01/2021.
//

#include <iostream>
#include "Polygone.h"

// Passage par methode statique car le constructeur par défaut
// d'un objet est automatiquement appeler lorsque celui ci est le membre d'une classe
Polygone Polygone::create() {
    Polygone polygone = Polygone();
    std::cout << "Afin de créer un polygone nous n'aurons besoin de deux informations : \n";
    std::cout << "- une couleur \n";
    std::cout << "- une liste de point de minimum deux points \n";
    std::cout << "Tout d'abord commencons par la couleur : \n";
    polygone.addColor(Color::create());
    polygone.addPoint();
    return polygone;
}


Polygone::Polygone() {}

Polygone::Polygone(std::vector<Point> listPoint) {
    this->listPoint = listPoint;
}

void Polygone::addPoint() {
    std::cout << "Création d'un point du polygone : \n";
    int anOther;
    Point pointToAdd = Point::create();
    this->listPoint.push_back(pointToAdd);
    std::cout << "Si vous voulez ajouter un autre point a votre polygone taper 1 sinon autre :";
    std::cin >> anOther;
    if(anOther == 1) this->addPoint();
}

std::vector<Point> Polygone::getListPoint() {return this->listPoint;}
void Polygone::addColor(Color color) {this->color = color;}

void Polygone::draw(std::string fileName) {
    std::ofstream mySvg;
    mySvg.open(fileName, std::ios::app);
    mySvg << "<polyline ";
    mySvg << "points=\"";
       std::vector<Point>::iterator it, end;
    for(it = this->listPoint.begin(), end = this->listPoint.end(); it!=end; ++it){
        mySvg << it->getX() << "," << it->getY() << " ";
    }
    mySvg << "\" fill=\"" << this->color.getColorName() << "\" ";
    mySvg << "/>\n";
    mySvg.close();
}
