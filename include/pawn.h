#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "piece.h"

using std::string;

class Pawn: public Piece
{
    public:
        Pawn(bool _color, bool _moved, string _type);
        ~Pawn();
        string getType();

    private:
        string type;
};

#endif // PAWN_H
