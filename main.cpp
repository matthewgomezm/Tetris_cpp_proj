#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastupdatetime = 0;
bool Event(double interval)
{
    double currenttime = GetTime();
    if(currenttime - lastupdatetime >= interval)
    {
        lastupdatetime = currenttime;
        return true;
    }
    return false;
}

int main()
{
    
    InitWindow(500,620,"Tetris"); 
    SetTargetFPS(60);

    
    Grid grid = Grid();  
    grid.Print();

    Font font = LoadFontEx("GameFont/font.ttf", 64, 0, 0); 
    Game game = Game();
    
   
    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        game.Input(); 
        if(Event(0.2))
        {
            game.MoveDown();
        }
        ClearBackground(DARKBLUE);
        DrawTextEx(font, "SCORE", {365, 15}, 38, 2, RAYWHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, RAYWHITE);
        if (game.gameover)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, RAYWHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightblue);
        char scoreText[10];
        snprintf(scoreText, sizeof(scoreText), "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 32, 0);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 32, 0, RAYWHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightblue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}