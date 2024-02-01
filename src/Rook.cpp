#include "Rook.h"

Rook::Rook(bool _color, bool _moved):Piece(_color, _moved){
}

Rook::~Rook(){
}

int Rook::getTypeInt(){
    return TypeInt;
}
