#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece
{
    public:
        Piece(bool _color, bool _moved);
        virtual ~Piece();
        bool getColor();
        bool getMoved();
        void setMoved();

    protected:
        bool color;
        bool moved = false;
};


#endif // PIECE_H
