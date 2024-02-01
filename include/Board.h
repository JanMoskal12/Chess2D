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
#include <set>
#include <cmath>

class Board
{
    public:
        Board(int emp);
        ~Board();

        void setClickedSquare(int _nrBB);
        void setDestination(int _nrBB);
        void swapSquares(Square* clickedSquare, Square* destination);
        bool isClickedPiece();
        bool isDestinationPiece();
        bool isSameColor();
        bool isKing();
        bool isGoodColorMoving();
        void wasKingMoving();
        int whereIsKing();
        void whereICanMove();
        bool isInSetOfMoves();
        bool pawnPieceInFront();
        void pawnMovesButNothingIsInFront();
        void pawnTakes();
        bool isSomethingBetween(Square* _squareOne, Square* _squareTwo, int typeInt);
        bool isBeatable(Square* _square);
        bool moveSimulation();
        void pawnPromotion();
        bool castling();

        std::set<int> setOfMoves;
        Square* asylum;
        Square* squareBetween;
        Square* whiteKing;
        Square* blackKing;
        Square* clickedSquare;
        Square* destination;
        Piece* pieces[2][7];
        Square* squares[8][8];
};

#endif // BOARD_H
