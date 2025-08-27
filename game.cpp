#include "game.h"
#include <random>

 Game::Game()
{
    grid = Grid();
    blocks = GetEveryBlock();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
    gameover = false;
    score = 0;
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetEveryBlock();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetEveryBlock()
{
    return {I(), J(), L(), O(), S(), T(), Z()};
}

void Game::Draw()
{
    grid.Draw();
    current_block.Draw(11,11);
    next_block.Draw(270, 270);
    
}

void Game::Input()
{
    int key = GetKeyPressed();
    if(key && gameover != 0)
    {
        gameover = false;
        Reset();
    }
    switch (key)
    {
        case KEY_LEFT:
        MoveLeft();
        break;
        case KEY_RIGHT:
        MoveRight();
        break;
        case KEY_DOWN:
        MoveDown();
        UpdateScore(0, 1);
        break;
        case KEY_UP:
        MoveUp();
        break;

        
    }
}

void Game::MoveLeft()
{
    if(!gameover)
    {
        current_block.Move(0,-1);
        if(OutOfBounds() || !BlockFits())
        {
            current_block.Move(0,1);
        }
    }
}

void Game::MoveDown()
{
    if(!gameover)
   {     current_block.Move(1,0);
        if(OutOfBounds() || !BlockFits())
        {
            current_block.Move(-1,0);
            LockBlock();
        }
   }
}


void Game::MoveRight()
{
    if(!gameover)
    {    current_block.Move(0,1);
        if(OutOfBounds() || !BlockFits())
        {
            current_block.Move(0,-1);
        }
    }
}

void Game::MoveUp()
{
    if(!gameover)
    {
        RotateBlock();
    }
}

bool Game::OutOfBounds()
{
    std::vector<Position> tiles = current_block.GetCellPosition();
    for (Position item: tiles)
    {
        if(grid.OutOfBounds(item.row, item.column))
        {
            return true;
        }
    }
    return false;

}

void Game::RotateBlock()
{
    current_block.Rotate();
    if(OutOfBounds() || !BlockFits())
    {
        current_block.UndoRotation();
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = current_block.GetCellPosition();
    for(Position item: tiles)
    {
        grid.grid[item.row][item.column] = current_block.id;
    }

    current_block = next_block;
    if(!BlockFits())
    {
        gameover = true;
    }
    next_block = GetRandomBlock();
    int rows_cleared = grid.ClearFullRows();
    UpdateScore(rows_cleared, 0);
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = current_block.GetCellPosition();
    for (Position item: tiles)
    {
        if(!grid.IsCellEmpty(item.row, item.column))
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetEveryBlock();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int rows_cleared, int movingdown)
{
    // Soft drop: +1 point per cell moved down when player presses down
    if (movingdown > 0)
    {
        score += movingdown;
    }

    // Line clear scoring (standard Tetris-like values)
    switch (rows_cleared)
    {
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        case 4:
            score += 800;
            break;
        default:
            break;
    }
}
