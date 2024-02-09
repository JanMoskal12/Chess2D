#ifndef BOARD_H
#define BOARD_H

#include <set>
#include <list>
#include <cmath>
#include <wx/wx.h>
#include <wx/bmpbuttn.h>
#include "Square.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

using std::list;
using std::set;
using std::abs;

class Board
{
    public:
        Board(int i);
        ~Board();
        void cleaning();
        void creatingSquares();
        void creatingPieces();
        void assigningPieces();
        void restart();
        void setClicked(int _nrBB);
        void setDestination(int _nrBB);
        bool isClickedPiece();
        bool isDestinationPiece();
        bool arePiecesSameColor();
        bool isGoodColorMoving();
        void updateSquares(Square* _clicked, Square* _destination);
        bool isKingInside();
        void wasKingMoving();
        int whereIsKing();
        bool castling();
        bool pawnBlockedByPieceInFront();
        void pawnMovesButNothingIsInFront();
        void pawnTakes();
        void pawnPromotion();
        void whereICanMove(Square* clicked);
        bool isInSetOfMoves();
        bool isSomethingBetween(Square* _squareOne, Square* _squareTwo, int _typeInt);
        bool isBeatable(Square* _square);
        bool moveSimulation(Square* clicked, Square* destination);
        bool isMate();
        Piece* pieces[2][7];
        Square* squares[8][8];
        Square* clicked;
        Square* destination;
        Square* whiteKing;
        Square* blackKing;
        set<int> setOfMoves;
        Square* squareBetween;
        list<int> listOfThreats;
        Square* target;
        list<int> listOfDefenders;

};

#endif // BOARD_H
