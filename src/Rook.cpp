#include "Rook.h"

Rook::Rook(bool _color, bool _moved):Piece(_color, _moved)
{
    //ctor
}

Rook::~Rook()
{
    //dtor
}

string Rook:: getType(){
    return type;
}

int Rook::getTypeInt(){
    return TypeInt;
}
