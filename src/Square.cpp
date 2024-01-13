#include "Square.h"


extern wxBitmapButton* board[64];

Square::Square(int _col, int _row, bool _backgroundColor, wxBitmapButton* _button, Piece* _piece){
    col = _col;
    row = _row;
    backgroundColor = _backgroundColor;
    piece = _piece;
    button = _button;
}

Square::~Square(){
}

int Square::getCol(){
    return col;
}

int Square::getRow(){
    return row;
}

bool Square::getBackgroundColor(){
    return backgroundColor;
}

Piece* Square::getPiece(){
    return piece;
}

void Square::setPiece(Piece* _piece){
    piece = _piece;
}

wxBitmapButton* Square::getButton(){
    return button;
}

