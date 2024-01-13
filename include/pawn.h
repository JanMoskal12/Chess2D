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
        int getTypeInt();

    private:
        int TypeInt = 1;
        string type = "Pawn";
};

#endif // PAWN_H
