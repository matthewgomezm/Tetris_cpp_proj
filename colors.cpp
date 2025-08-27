#include "colors.h"

    const Color grey = {26, 31, 40, 255}; //each number in the struct is for the following: {red, blue, green, opacity}. 255 is the max number for intenstiy/opacity, and 0 being the lowest
    const Color green = {47,230,23,255};
    const Color red = {232, 18, 18, 255};
    const Color orange = {226, 116, 17, 255};
    const Color yellow = {237, 234, 4, 255};
    const Color purple = {166, 0, 247, 255};
    const Color cyan = {21, 204, 209, 255};
    const Color blue = {13, 64, 216, 255};
    const Color lightblue = {59, 85, 162, 255};
    const Color darkblue = {44, 44, 127, 255};

    std::vector<Color>GetCellColors()
    {
        return {grey, green, red, orange, yellow, purple, cyan, blue}; //returns the colors of the vector
    }