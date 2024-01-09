#ifndef BISHOP_H
#define BISHOP_H


#include "piece.h"

class Bishop : public Piece
{
    public:
        Bishop(bool _color, bool _moved);
        ~Bishop();
        string getType();

    protected:

    private:
        string type = "Bishop";
};

#endif // BISHOP_H
