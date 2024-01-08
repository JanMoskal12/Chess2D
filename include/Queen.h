#ifndef QUEEN_H
#define QUEEN_H
#include <iostream>
#include "piece.h"

using std::string;

class Queen : Piece
{
    public:
        Queen(bool _color, bool _moved, string _type);
        ~Queen();
        string getType();

    protected:

    private:
        string type;
};

#endif // QUEEN_H
