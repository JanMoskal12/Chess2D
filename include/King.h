#ifndef KING_H
#define KING_H
#include "piece.h"

class King : Piece
{
    public:
        King(bool _color, bool _moved);
        ~King();
        string getType();

    protected:

    private:
        string type = "King";
};

#endif // KING_H
