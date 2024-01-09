#ifndef ROOK_H
#define ROOK_H


#include "piece.h"

class Rook : public Piece
{
    public:
        Rook(bool _color, bool _moved);
        ~Rook();
        string getType();

    protected:

    private:
        string type = "Rook";
};

#endif // ROOK_H
