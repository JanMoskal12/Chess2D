#ifndef PIECE_H
#define PIECE_H

#include <iostream>

using std::string;

class Piece
{
    public:
        Piece(bool _color, bool _moved);
        virtual ~Piece();
        bool getColor();
        bool getMoved();
        void setMoved();
        virtual int getTypeInt()=0;

    protected:
        bool color;
        bool moved;
};

#endif // PIECE_H
