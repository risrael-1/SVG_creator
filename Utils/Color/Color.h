#ifndef SVG_CREATOR_COLOR_H
#define SVG_CREATOR_COLOR_H

#include <iostream>


class Color {
private:
    std::string nameColor;

public:
    static Color create();
    explicit Color(std::string nameColor);
    Color();
    std::string getColorName();
};


#endif //SVG_CREATOR_COLOR_H
