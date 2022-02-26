#include <iostream>
#include "Circle.h"

Circle Circle::create() {
    Point point;
    int radius;
    Color color;
    std::cout << "Afin de créer un cercle nous aurons besoin des informations suivantes: \n";
    std::cout << "- L'abscisse et l'ordonnée du centre du cercle : \n";
    std::cout << "- Le rayon du cercle \n";
    std::cout << "- Une couleur \n";
    std::cout << " Tout d'abord veuillez saisir l'abscisse et l'ordonnée du centre du cercle : ";
    point = Point::create();
    std::cout << " Maintenant le rayon du cercle : ";
    std::cin >> radius;
    std::cout << "\n Passons a la couleur de votre cercle";
    color = Color::create();

    return Circle(point, radius, color);
}
Circle::Circle(Point point, int radius, Color color){
    this->m_center = point;
    this->m_radius = radius;
    this->color = color;
}

Circle::Circle() {
    this->m_radius = 1;
    this->m_center = Point(1, 1);
}

Point Circle::getCenter(){
    return this->m_center;
}

float Circle::getRadius(){
    return this->m_radius;
}

/*void Circle::setRadius(float value){
    this->m_radius = value;
}*/

void Circle::setCenter(Point newCenter){
    this->m_center = newCenter;
}

void Circle::draw(std::string fileName) {
    std::ofstream mySvg;
    mySvg.open(fileName, std::ios::app);
    mySvg << "<circle ";
    mySvg << "cx=\"" << this->m_center.getX() << "\" " << "cy=\"" << this->m_center.getY() << "\" ";
    mySvg << "r=\"" << this->m_radius << "\" ";
    mySvg << "fill=\"" << this->color.getColorName() << "\" ";
    mySvg << "/>\n";
    mySvg.close();
}


