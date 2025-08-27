#pragma once
#include <raylib.h>
#include <vector>
extern const Color grey; // extern keyword allows to use a variable declared in another file, const means cannot be modified
extern const Color green; //here, each color was declared already in colors.cpp
extern const Color red;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color orange;
extern const Color lightblue;
extern const Color darkblue;

std::vector<Color> GetCellColors();