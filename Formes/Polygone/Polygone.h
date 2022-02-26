//
// Created by Dima on 09/01/2021.
//

#ifndef SVG_CREATOR_POLYGONE_H
#define SVG_CREATOR_POLYGONE_H


#include <vector>
#include "../../Utils/Point/Point.h"
#include "../Forme.h"

class Polygone : public Forme {
private:
    std::vector<Point> listPoint;
    Color color;
    void addPoint();

public:
    static Polygone create();
    Polygone();
    Polygone(std::vector<Point> listPoint);
    void addColor(Color color);

    std::vector<Point> getListPoint();

    void draw(std::string fileName);


};


#endif //SVG_CREATOR_POLYGONE_H
