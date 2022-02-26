#ifndef SVG_CREATOR_CIRCLE_H
#define SVG_CREATOR_CIRCLE_H


#include "../../Utils/Point/Point.h"
#include "../../Utils/Color/Color.h"
#include "../Forme.h"

class Circle : public Forme {
public:
    static Circle create();
    Circle();
    Circle(Point point, int radius, Color color);
    void draw(std::string fileName);

    Point getCenter();
    void setCenter(Point newCenter);
    float getRadius();
    //void setRadius(int value);

private:
    int m_radius;
    Point m_center;
    Color color;
};


#endif //SVG_CREATOR_CIRCLE_H
