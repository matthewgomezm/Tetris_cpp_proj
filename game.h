#pragma once
#include "grid.h"
#include "blocks.cpp"

// game header file
// contains all aspects of the game

class Game
{
    public: 
    Game();
    bool gameover;
    Grid grid;
    Block GetRandomBlock();
    std::vector<Block>GetEveryBlock();
    void Draw();
    void Input();
    void MoveLeft();
    void MoveDown();
    void MoveRight();
    void MoveUp();
    int score;
    int high_score;

    private:
    std::vector<Block> blocks;
    Block current_block;
    Block next_block;
    bool BlockFits();
    bool OutOfBounds();
    void RotateBlock();
    void LockBlock(); 
    void Reset();
    void UpdateScore(int rows_cleared, int movingdown);

};
