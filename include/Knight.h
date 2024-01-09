#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
    public:
        Knight(bool _color, bool _moved);
        ~Knight();
        string getType();

    protected:

    private:
        string type ="Knight";
};
#endif // KNIGHT_H
