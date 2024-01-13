#ifndef BOARD_H
#define BOARD_H


#include <wx/wx.h>
#include <wx/bmpbuttn.h>
#include "Square.h"
#include "Pawn.h"
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
        Piece* pieces[2][6];
        Square* squares[8][8];

};

#endif // BOARD_H
