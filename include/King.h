#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece
{
    public:
        King(bool _color, bool _moved = false);
        ~King();
        string getType();
        int getTypeInt();

    protected:

    private:
        int TypeInt = 11;
        string type = "King";
};

#endif // KING_H
