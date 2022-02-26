#include <iostream>
#include <math.h>
#include <stdio.h>
#include "Draw.h"
#include <vector>
#include "../Utils/TerminalColors.h"


const int rectangleIndex = 0;
const int circleIndex = 3;
const int lineIndex = 12;
int forme = 0;
Rectangle rectangle;
Circle circle;
#define M 1
#define N 1

Draw::Draw(int largeur, int hauteur, std::string name) {
    this->hauteur = hauteur;
    this->largeur = largeur;
    this->name = name;
    
}

int Draw::getHauteur() { return this->hauteur; }
int Draw::getLargeur() { return this->largeur; }

void Draw::createForme(){
    int typeForme;
    do {
        std::cout << "Quel figure voulez vous créer ? \n";
        std::cout << BOLD(FYEL("Pour un rectangle taper 1\n"));
        std::cout << BOLD(FYEL("Pour un cercle taper 2\n"));
        std::cin >> typeForme;
    }while(typeForme != 1 && typeForme != 2 && typeForme != 3 && typeForme != 4);
    switch(typeForme){
       
        case 1: this->createRectangle();
        case 2: this->createCircle(); break;
        forme = 1;break;
        default: break;
    }
}

void Draw::createRectangle() {
    bool isConform;
    rectangle = Rectangle::create();
    isConform = this->rectangleIsconform(rectangle);
    if(!isConform) {
        int cancelOrRetry = this->cancelOrRetry();
        if(cancelOrRetry == 1) {this->createRectangle();}
    }
}

bool Draw::rectangleIsconform(Rectangle rectangle) {
    if(!this->pointIsConform(rectangle.getCorner())) return false;
    else if(rectangle.getCorner().getX() + rectangle.getLargeur() > this->largeur) return false;
    else if(rectangle.getCorner().getY() + rectangle.getHauteur() > this->hauteur) return false;
    else return true;
}

void Draw::createCircle() {
    bool isConform;
    circle = Circle::create();
    isConform = this->circleIsconform(circle);
    if(!isConform) {
        int cancelOrRetry = this->cancelOrRetry();
        if(cancelOrRetry == 1) {this->createCircle();}
    }
}

bool Draw::circleIsconform(Circle circle) {
    bool isConform = true;
    if(!this->pointIsConform(circle.getCenter())) return false;
    else if (circle.getCenter().getY() + circle.getRadius() > this->hauteur) return false;
    else if (circle.getCenter().getX() + circle.getRadius() > this->largeur) return false;

    else return true;
}

int Draw::cancelOrRetry() {
    int returnCode;
    std::cout << "La figure que vous avez créer n'est pas positionnable sur le dessin :/ \n";
    do {
        std::cout << "Voulez vous recommencer : taper 1\n";
        std::cout << "Ou abandonner: taper 2 :";
        std::cin >> returnCode;
    }while(returnCode != 2 && returnCode != 1);
    return returnCode;
}


std::string Draw::createSvg() {
    std::string fileName = this->name + ".svg";
    std::ofstream svgFile;
    svgFile.open(fileName, std::ios::app);
    if(svgFile.is_open()) {std::cout << "file open \n";}
    svgFile << "<svg ";
    svgFile << "width=\"" << this->getLargeur() << "\" ";
    svgFile << "height=\"" << this->getHauteur() << "\" \n";
    svgFile << "xmlns=\"" << "http://www.w3.org/2000/svg" << "\"> \n";
    svgFile.close();        
    switch(forme){
       
        case 1: Rectangle *rectangle2 = &rectangle;
        rectangle2->draw(fileName);
       
    }
    svgFile.open(fileName, std::ios::app);
    svgFile << "</svg>";
    return fileName;
}

bool Draw::pointIsConform(Point point) {
    if(this->largeur < point.getY() || point.getY() < 0) return false;
    else if(this->hauteur < point.getX() || point.getX() < 0) return false;
    else return true;
}