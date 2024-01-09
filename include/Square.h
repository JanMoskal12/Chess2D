#ifndef SQUARE_H
#define SQUARE_H

#include "../Chess2DMain.h"
#include <wx/wx.h>
#include <wx/bmpbuttn.h>
#include "piece.h"

class Square
{
    public:
        friend class Board;
        Square(int _col, int _row, bool _backgroundColor, Piece* _piece, wxBitmap* _button);
        ~Square();
        int getCol();
        int getRow();
        wxBitmap* getButton();
        bool getBackgroundColor();
        Piece* getPiece();
        void setPiece(Piece* _piece);

    protected:
        wxBitmap* button;
        Piece* piece = nullptr;
        int col;
        int row;
        bool backgroundColor;
};

#endif // SQUARE_H
