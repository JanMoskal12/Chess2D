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
        Board(int i);
        ~Board();


        void setClickedSquare(int _nrBB);
        void setDestination(int _nrBB);
        void swapSquares();
        bool isClickedPiece();
        bool isDestinationPiece();
        bool isSameColor();
        bool isKing();
        bool isKingInCheck(Square* king);

        Square* whiteKing;
        Square* blackKing;
        Square* clickedSquare;
        Square* destination;
        Piece* pieces[2][6];
        Square* squares[8][8];

    private:


};

#endif // BOARD_H
