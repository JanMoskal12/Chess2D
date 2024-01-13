#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

using std::string;

class Pawn: public Piece
{
    public:
        Pawn(bool _color, bool _moved = false);
        ~Pawn();
        string getType();

    private:
        string type = "Pawn";
};

#endif // PAWN_H
