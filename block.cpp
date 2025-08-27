#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotation_state = 0;
    color = GetCellColors();
    roff = 0;
    coff = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPosition();
    for(Position item: tiles)
    {
        DrawRectangle(item.column * cellSize+offsetX, item.row * cellSize+offsetY, cellSize-1, cellSize-1, color[id]);
    }
}

void Block::Move(int rows, int columns)
{
     roff += rows;
     coff += columns;
}

std::vector<Position> Block::GetCellPosition()
{
    std::vector<Position> tiles = cells[rotation_state];
    std::vector<Position> tilesmoved;
    for (Position item: tiles)
    {
        Position updated_position = Position(item.row + roff, item.column + coff);
        tilesmoved.push_back(updated_position);
    }
    return tilesmoved;
}

void Block::Rotate()        // here, handles block rotating by incrememnting rotation state and casting the cellsize to an integer
{
    rotation_state++;
    if(rotation_state == (int)cells.size())
    {
        rotation_state = 0;
    }
}

void Block::UndoRotation()
{
    rotation_state--;
    if(rotation_state == -1)
    {
        rotation_state = cells.size() -1;
    }
}
