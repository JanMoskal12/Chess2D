#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"



class Queen : public Piece
{
    public:
        Queen(bool _color, bool _moved = false);
        ~Queen();
        string getType();
        int getTypeInt();

    protected:

    private:
        int TypeInt = 9;
        string type = "Queen";
};

#endif // QUEEN_H
