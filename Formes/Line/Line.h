#ifndef SVG_CREATOR_LINE_H
#define SVG_CREATOR_LINE_H


#include "../../Utils/Point/Point.h"
#include "../../Utils/Color/Color.h"


class Line {

private:
    Point a;
    Point b;
    Color color;

public:
    static Line create();
    Line();
    Line(Point a, Point b, Color color);
    virtual ~Line() {};

    void draw(std::string fileName);

    Point getA();
    Point getB();
};


#endif //SVG_CREATOR_LINE_H
