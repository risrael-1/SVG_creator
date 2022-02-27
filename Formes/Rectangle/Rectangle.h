#include "../../Utils/Point/Point.h"
#include "../../Utils/Color/Color.h"


class Rectangle {
public:
    static Rectangle create();
    Rectangle();
    Rectangle(int hauteur, int largeur, Point topCorner, Color color);
    void draw(std::string fileName);

    int getHauteur();
    int getLargeur();
    Point getCorner();
 

private:
        int hauteur;
        int largeur;
        Point topCorner;
        Color color;
        static std::string classeName;
};
