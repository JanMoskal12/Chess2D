#include "Piece.h"

Piece::Piece(bool _color, bool _moved){
    color = _color;
    moved = _moved;
}

Piece::~Piece(){
}

bool Piece::getColor(){
    return color;
}

bool Piece::getMoved(){
    return moved;
}

void Piece::setMoved(){
    moved = true;
}


