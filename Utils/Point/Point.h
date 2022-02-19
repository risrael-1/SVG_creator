//
// Created by Dima on 28/12/2020.
//

#ifndef SVG_CREATOR_POINT_H
#define SVG_CREATOR_POINT_H


class Point{
public:
    static Point create();
    //Constructor
    Point();
    Point(int m_x, int m_y);



    //getter et setter
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    void add(Point Point);

private:
    int m_x, m_y;
};

#endif //SVG_CREATOR_POINT_H
