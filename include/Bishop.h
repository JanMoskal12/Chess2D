#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop:public Piece
{
    public:
        Bishop(bool _color, bool _moved = false);
        ~Bishop();
        int getTypeInt();

    private:
        int TypeInt = 7;
};

#endif // BISHOP_H

