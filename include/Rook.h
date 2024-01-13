#ifndef ROOK_H
#define ROOK_H


#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(bool _color, bool _moved = false);
        ~Rook();
        string getType();
        int getTypeInt();

    protected:

    private:
         int TypeInt = 3;
        string type = "Rook";
};

#endif // ROOK_H
