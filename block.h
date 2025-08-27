#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
    public:
        Block();
        void Draw(int offsetX, int offsetY);
        int id;
        void Move(int rows, int columns);
        std::vector<Position> GetCellPosition();
        std::map<int, std::vector<Position>> cells;
        void Rotate();
        void UndoRotation();


    private:
        int cellSize;
        int rotation_state;
        std::vector<Color> color;
        int roff; //row offset
        int coff; //column offset

};