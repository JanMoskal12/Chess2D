#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"



class Queen : Piece
{
    public:
        Queen(bool _color, bool _moved);
        ~Queen();
        string getType();

    protected:

    private:
        string type;
};

#endif // QUEEN_H
