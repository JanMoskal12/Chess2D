#ifndef BISHOP_H
#define BISHOP_H


#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(bool _color, bool _moved = false);
        ~Bishop();
        string getType();

    private:
        string type = "Bishop";
};

#endif // BISHOP_H

