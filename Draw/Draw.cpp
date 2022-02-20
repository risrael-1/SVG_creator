#include <iostream>
#include <math.h>
#include <stdio.h>
#include "Draw.h"
#include <vector>


const int rectangleIndex = 0;
const int lineIndex = 1;


Draw::Draw(int largeur, int hauteur, std::string name) {
    this->hauteur = hauteur;
    this->largeur = largeur;
    this->name = name;

    std::vector<Rectangle *> rectangles;

    std::vector<std::vector<Forme *> > formes = {
        {rectangles.begin(), rectangles.end()}
    };
    
    this->formes = formes;
}

int Draw::getHauteur() { return this->hauteur; }
int Draw::getLargeur() { return this->largeur; }

void Draw::createForme(){
    int typeForme;
    do {
        std::cout << "Quel figure voulez vous créer ? \n";
        std::cout << "- Pour un rectangle taper 1\n";
        std::cin >> typeForme;
    }while(typeForme != 1 && typeForme != 2 && typeForme != 3 && typeForme != 4);
    switch(typeForme){
        case 1: this->createRectangle(); break;
        default: break;
    }
}


void Draw::addForme(Forme* forme, int index) {
    this->formes[index].push_back(forme);
}


void Draw::createRectangle() {
    Rectangle rectangle;
    bool isConform;
    rectangle = Rectangle::create();
    isConform = this->rectangleIsconform(rectangle);
    if(isConform) {this->addForme(&rectangle, rectangleIndex);}
    else {
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
/*
 * Return 0 for cancel
 
 * Return 1 for retry
 */
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
    svgFile << "height=\"" << this->getHauteur() << "\" >\n";
    svgFile.close();
    std::cout << "size of formes : " << this->formes.size() << "\n";
    std::cout << "size of line after : " << this->formes[lineIndex].size() << "\n";
    this->drawFormes(fileName);
    svgFile.open(fileName, std::ios::app);
    svgFile << "</svg>";
    return fileName;
}

void Draw::drawFormes(std::string fileName) {
    for(int i = 0; i < this->formes.size(); i++) {
        for(int j = 0; j < this->formes[i].size(); j++) {
            switch(i) {
                case rectangleIndex: {
                    this->drawRectangle(this->formes[rectangleIndex][j], fileName);
                    break;
                }
                default: break;
            }
        }
    }
}

void Draw::drawRectangle(Forme *forme, std::string fileName) {
    Rectangle *rectangle = dynamic_cast<Rectangle*>(forme);
    rectangle->draw(fileName);
}

int Draw::getListFormeLength() {
    return this->formes.size();
}

bool Draw::pointIsConform(Point point) {
    if(this->largeur < point.getY() && point.getY() < 0) return false;
    else if(this->hauteur < point.getX() && point.getX() < 0) return false;
    else return true;
}