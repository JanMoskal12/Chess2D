#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
    public:
        King(bool _color, bool _moved = false);
        ~King();
        int getTypeInt();

    private:
        int TypeInt = 11;
};

#endif // KING_H
