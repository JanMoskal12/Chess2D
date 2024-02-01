#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn:public Piece
{
    public:
        Pawn(bool _color, bool _moved = false);
        ~Pawn();
        int getTypeInt();

    private:
        int TypeInt = 1;
};

#endif // PAWN_H
