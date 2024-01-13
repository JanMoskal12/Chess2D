#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(bool _color, bool _moved = false);
        ~Knight();
        string getType();
        int getTypeInt();

    protected:

    private:
        int TypeInt = 5;
        string type ="Knight";
};
#endif // KNIGHT_H
