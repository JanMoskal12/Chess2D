#ifndef BISHOP_H
#define BISHOP_H


#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(bool _color, bool _moved = false);
        ~Bishop();
        string getType();
        int getTypeInt();

    private:
        int TypeInt = 7;
        string type = "Bishop";
};

#endif // BISHOP_H

