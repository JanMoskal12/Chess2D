#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(bool _color, bool _moved = false);
        ~Knight();
        string getType();

    protected:

    private:
        string type ="Knight";
};
#endif // KNIGHT_H
