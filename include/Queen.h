#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"



class Queen : public Piece
{
    public:
        Queen(bool _color, bool _moved = false);
        ~Queen();
        string getType();

    protected:

    private:
        string type;
};

#endif // QUEEN_H
