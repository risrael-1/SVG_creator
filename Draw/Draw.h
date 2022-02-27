#ifndef SVG_CREATOR_DRAW_H
#define SVG_CREATOR_DRAW_H

#include <vector>
#include "../Utils/Point/Point.h"

#include "../Formes/Rectangle/Rectangle.h"
#include "../Formes/Circle/Circle.h"
#include "../Formes/Polygone/Polygone.h"
#include "../Formes/Line/Line.h"

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
    void createPolygone();
    void createCircle();
    void createLine();

    int cancelOrRetry();
    
    bool pointIsConform(Point point);
    bool rectangleIsconform(Rectangle rectangle);
    bool circleIsconform(Circle circle);
    bool polygoneIsconform(Polygone* polygone);
    bool lineIsconform(Line line);
};


#endif //SVG_CREATOR_DRAW_H
