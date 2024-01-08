#include "Square.h"

Square::Square(int _col, int _row, bool _backgroundColor, Piece* _piece = nullptr){
    col = _col;
    row = _row;
    backgroundColor = _backgroundColor;
    piece = _piece;
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
