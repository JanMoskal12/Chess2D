#ifndef BOARD_H
#define BOARD_H

#include "../Chess2DMain.h"
#include "Square.h"

#include "pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board
{
    public:
        Board();
        ~Board();

    protected:

    private:
        wxBitmapButton *board[64];
        wxBitmap images[26];
        Piece** pieces;
        Square** squares;

};

#endif // BOARD_H
