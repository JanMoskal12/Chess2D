#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight:public Piece
{
    public:
        Knight(bool _color, bool _moved = false);
        ~Knight();
        int getTypeInt();

    private:
        int TypeInt = 5;
};

#endif // KNIGHT_H
