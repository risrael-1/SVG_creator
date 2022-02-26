//
// Created by VIDAL Léo on 28/01/2021.
//

#ifndef SVG_CREATOR_DRAW_H
#define SVG_CREATOR_DRAW_H

#include <vector>
#include "../Utils/Point/Point.h"

#include "../Formes/Rectangle/Rectangle.h"

class Draw {

public:
    Draw(int largeur, int hauteur, std::string name);
    void createForme();
    std::string createSvg();

    int getHauteur();
    int getLargeur();
    int getListFormeLength();

private:
    int largeur;
    int hauteur;
    std::string name;

    void createRectangle();
    int cancelOrRetry();
    bool pointIsConform(Point point);
    bool rectangleIsconform(Rectangle rectangle);

};


#endif //SVG_CREATOR_DRAW_H
