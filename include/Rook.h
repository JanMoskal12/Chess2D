#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook:public Piece
{
    public:
        Rook(bool _color, bool _moved = false);
        ~Rook();
        int getTypeInt();

    private:
        int TypeInt = 3;
};

#endif // ROOK_H
