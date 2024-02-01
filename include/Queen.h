#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
    public:
        Queen(bool _color, bool _moved = false);
        ~Queen();
        int getTypeInt();

    private:
        int TypeInt = 9;
};

#endif // QUEEN_H
