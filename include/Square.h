#ifndef SQUARE_H
#define SQUARE_H

#include <wx/wx.h>
#include <wx/bmpbuttn.h>
#include "Piece.h"

class Square
{
    public:
        friend class Board;
        Square(int _row, int _col, bool _backgroundColor, wxBitmapButton* _button, Piece* _piece = nullptr);
        ~Square();
        int getRow();
        int getCol();
        bool getBackgroundColor();
        wxBitmapButton* getButton();
        Piece* getPiece();
        void setPiece(Piece* _piece);

    protected:
        int row;
        int col;
        bool backgroundColor;
        wxBitmapButton* button;
        Piece* piece;
};

#endif // SQUARE_H
