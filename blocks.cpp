#include "block.h"
#include "position.h"
class L :public Block  //inherits block header and applies to each block here
{
    public:
        L(){
            id = 1;
            cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};
            cells[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
            cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
            cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
            Move(0,3);
        }
};
// Each different kind of block and its coordinates around a point will be colored

class J :public Block
{
   public:
    J(){
        id = 2;
        cells[0] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};
        cells[3] = {Position(0,1), Position(1,1), Position(2,0), Position(2,1)};
        Move(0,3);
    }
};

class I :public Block
{
   public:
    I(){
        id = 3;
        cells[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
        cells[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
        cells[2] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
        cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
        Move(-1,3);
    }
};

class O :public Block
{
   public:
    O(){
        id = 4;
        cells[0] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        cells[1] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        cells[2] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        cells[3] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        Move(0,4);
    }
};

class S :public Block
{
   public:
    S(){
        id = 5;
        cells[0] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
        cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
        cells[2] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
        cells[3] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
        Move(0,3);
    }
};

class T :public Block
{
   public:
    T(){
        id = 6;
        cells[0] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,1)};
        cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,1)};
        Move(0,3);
    }
};

class Z :public Block
{
   public:
    Z(){
        id = 7;
        cells[0] = {Position(0,0), Position(0,1), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,2), Position(1,1), Position(1,2), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
        cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,0)};
        Move(0,3);
    }
};