#include "grid.h"
#include <iostream>
#include "colors.h"
using namespace std;

Grid::Grid()
{
    number_of_columns = 10;
    number_of_rows = 20;
    cell_size = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    for (int row = 0; row < number_of_rows; row ++)
    {
        for (int column = 0; column < number_of_columns; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print()
{
    for (int row = 0; row < number_of_rows; row ++)
    {
        for (int column = 0; column < number_of_columns; column++)
        {
           cout << grid[row][column] << " ";
        }
        cout << endl;
    }
}


void Grid::Draw()
{
    for (int row = 0; row < number_of_rows; row++)
    {
        for (int column = 0; column < number_of_columns; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cell_size+11, row * cell_size+11, cell_size-1, cell_size-1 , colors[cellValue]);
        } 
    }
}

bool Grid::OutOfBounds(int row, int column)
{
    if (row >= 0 && row < number_of_rows && column >= 0 && column < number_of_columns)
        return false;
    return true;

}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
        return true;
    return false;
}

int Grid::ClearFullRows()
{
    int complete_rows = 0;
    for (int row = number_of_rows - 1; row >= 0; row--)
    {
        if(row_full(row))
        {
            clear_rows(row);
            move_rows_down(row - 1, 1);
            complete_rows++;
            row++; // recheck same row after moving down
        }
    }
    return complete_rows;
}

bool Grid::row_full(int row)
{
    for(int column = 0; column < number_of_columns; column++)
    {
        if(grid[row][column] == 0)
            return false;
    }
    return true;
}

void Grid::clear_rows(int row)
{
    for (int column = 0; column < number_of_columns; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::move_rows_down(int row, int num_rows)
{
    for(int column = 0; column < number_of_columns; column++)
    {
        grid[row + num_rows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
