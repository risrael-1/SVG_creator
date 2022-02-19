//
// Created by Dima on 28/12/2020.
//

#include <iostream>
#include "Point.h"

// Passage par methode statique car le constructeur par défaut
// d'un objet est automatiquement appeler lorsque celui ci est le membre d'une classe
Point Point::create() {
    int x;
    int y;
    std::cout << "Afin de créer un point nous aurons besoin de deux informations : \n";
    std::cout << "- x \n";
    std::cout << "- y \n";
    std::cout << " Tout d'abord veuillez saisir x : ";
    std::cin >> x;
    std::cout << "\n Maintenant y : ";
    std::cin >> y;
    return Point(x,y);
}

Point::Point() {
    this->m_y = 1;
    this->m_x = 1;
}

Point::Point(int x, int y){
    this-> m_x = x;
    this-> m_y = y;
}

void Point::setX(int x)
{
    this->m_x = x;
}

void Point::setY(int y)
{
    this->m_y = y;
}

int Point::getX()
{
    return this->m_x;
}

int Point::getY() {
    return this->m_y;
}

void Point::add(Point Point){
    this->m_x = m_x + Point.m_x;
    this->m_y = m_y + Point.m_y;
}