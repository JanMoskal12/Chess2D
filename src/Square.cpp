#include "Square.h"

Square::Square(int _row, int _col, bool _backgroundColor, wxBitmapButton* _button, Piece* _piece){
    col = _col;
    row = _row;
    backgroundColor = _backgroundColor;
    piece = _piece;
    button = _button;
}

Square::~Square(){
}

int Square::getRow(){
    return row;
}

int Square::getCol(){
    return col;
}

bool Square::getBackgroundColor(){
    return backgroundColor;
}

wxBitmapButton* Square::getButton(){
    return button;
}

Piece* Square::getPiece(){
    return piece;
}

void Square::setPiece(Piece* _piece){
    piece = _piece;
}
