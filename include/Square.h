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
        int getCol();
        int getRow();
        bool getBackgroundColor();
        Piece* getPiece();
        void setPiece(Piece* _piece);
        wxBitmapButton* getButton();

    protected:
        Piece* piece;
        int col;
        int row;
        bool backgroundColor;
        wxBitmapButton* button;
};

#endif // SQUARE_H
