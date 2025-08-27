#pragma once //'#pragma once' means the exact same as using #ifndef and #def and #endif. they are guards that allow compiler to only include each defnintion once. pragma is just better, less words
#include <vector>
#include <raylib.h>


class Grid
{
    public:
        Grid();
        void Print();
        void Initialize();
        void Draw();
        int grid[20][10];
        bool OutOfBounds(int row, int column);
        bool IsCellEmpty(int row, int column);
        int ClearFullRows();


    private:
        int number_of_rows;
        int number_of_columns;
        bool row_full(int row);
        void clear_rows(int row);
        void move_rows_down(int row,int num_rows);
        int cell_size;
        std::vector<Color> colors;

};

 