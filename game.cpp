#include "game.h"
#include <random>

//default constructor for game
 Game::Game()
{
    grid = Grid();
    blocks = GetEveryBlock();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
    gameover = false;
    score = 0;
}

//function that returns a random block in the sequence

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

//returns each block type
std::vector<Block> Game::GetEveryBlock()
{
    return {I(), J(), L(), O(), S(), T(), Z()};
}

//draws the window, current block, and the next block in the space shown on the UI
void Game::Draw()
{
    grid.Draw();
    current_block.Draw(11,11);
    next_block.Draw(270, 270);
    
}

//handles input conditions
// below this are the input functions
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
        UpdateScore(0, 1); //updates the score if pushed down 
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

// tests if the block is out of bounds according to position
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

// function resetting the game conditions and block conditions to begin a new cycle
void Game::Reset()
{
    grid.Initialize();
    blocks = GetEveryBlock();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
    score = 0;
}

//updates score 
void Game::UpdateScore(int rows_cleared, int movingdown)
{

    if (movingdown > 0)
    {
        score += movingdown;
    }

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
