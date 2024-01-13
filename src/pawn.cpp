#include "Pawn.h"

Pawn::Pawn(bool _color, bool _moved):Piece(_color, _moved){
}

Pawn::~Pawn(){
}

string Pawn::getType(){
    return type;
}

int Pawn::getTypeInt(){
    return TypeInt;
}
