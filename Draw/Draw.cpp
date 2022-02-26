#include <iostream>
#include <math.h>
#include <stdio.h>
#include "Draw.h"
#include <vector>
#include "../Utils/TerminalColors.h"


int forme = 0;
Rectangle rectangle;
Circle circle;
Polygone polygone;
Line line;

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
        std::cout << BOLD(FMAG("Pour un cercle taper 2\n"));
        std::cout << BOLD(FRED("Pour un polygone taper 3\n"));
        std::cout << BOLD(FGRN("Pour un segment taper 4\n"));
        std::cin >> typeForme;
    }while(typeForme != 1 && typeForme != 2 && typeForme != 3 && typeForme != 4);
    switch(typeForme){
       
        case 1: this->createRectangle();
        forme = 1;break;
        case 2: this->createCircle(); 
        forme = 2;break;
        case 3: this->createPolygone(); 
        forme = 3;break;
        case 4: this->createLine(); 
        forme = 4;break;
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

void Draw::createCircle() {
    bool isConform;
    circle = Circle::create();
    isConform = this->circleIsconform(circle);
    if(!isConform) {
        int cancelOrRetry = this->cancelOrRetry();
        if(cancelOrRetry == 1) {this->createCircle();}
    }
}

void Draw::createPolygone() {
    bool isConform;
    polygone = Polygone::create();
    isConform = this->polygoneIsconform(&polygone);
    if(!isConform){
        int cancelOrRetry = this->cancelOrRetry();
        if(cancelOrRetry == 1) {this->createPolygone();}
    }
}

void Draw::createLine() {
    bool isConform;
    line = Line::create();
    isConform = this->lineIsconform(line);
    if(!isConform)  {
        int cancelOrRetry = this->cancelOrRetry();
        if(cancelOrRetry == 1) {this->createLine();}
    }
}

bool Draw::circleIsconform(Circle circle) {
    bool isConform = true;
    if(!this->pointIsConform(circle.getCenter())) return false;
    else if (circle.getCenter().getY() + circle.getRadius() > this->hauteur) return false;
    else if (circle.getCenter().getX() + circle.getRadius() > this->largeur) return false;

    else return true;
}

bool Draw::polygoneIsconform(Polygone* polygone) {
    std::vector<Point>::iterator it,end;
    bool isConform = true;
    for(int i = 0; i<polygone->getListPoint().size(); i++){
        if(!this->pointIsConform(polygone->getListPoint()[i])) {isConform = false;}
    }
    return isConform;
}

bool Draw::rectangleIsconform(Rectangle rectangle) {
    if(!this->pointIsConform(rectangle.getCorner())) return false;
    else if(rectangle.getCorner().getX() + rectangle.getLargeur() > this->largeur) return false;
    else if(rectangle.getCorner().getY() + rectangle.getHauteur() > this->hauteur) return false;
    else return true;
}

bool Draw::lineIsconform(Line line) {
    if(!this->pointIsConform(line.getA())) return false;
    else if(!this->pointIsConform(line.getB())) return false;
    else return true;
}

bool Draw::pointIsConform(Point point) {
    if(this->largeur < point.getY() || point.getY() < 0) return false;
    else if(this->hauteur < point.getX() || point.getX() < 0) return false;
    else return true;
}

int Draw::cancelOrRetry() {
    int returnCode;
    std::cout << "La figure que vous avez créer n'est pas positionnable sur le dessin :/ \n";
    do {
        std::cout << "Voulez vous recommencer : taper 1\n";
        std::cout << "Ou abandonner: taper 2 :";
        std::cin >> returnCode;
    }while(returnCode != 1 && returnCode != 2 && returnCode != 3);
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
       
        case 1: {Rectangle *currentrectangle = &rectangle;currentrectangle->draw(fileName);break;}
        
        case 2: {Circle *currentcircle = &circle;currentcircle->draw(fileName);break;}
       
        case 3: {Polygone *currentpolygone = &polygone;currentpolygone->draw(fileName);break;}

        case 4: {Line *currentline = &line;currentline->draw(fileName);break;}

        default: 
        {break;}

    }
    svgFile.open(fileName, std::ios::app);
    svgFile << "</svg>";
    return fileName;
}