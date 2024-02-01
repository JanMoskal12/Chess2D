#include "Pawn.h"

Pawn::Pawn(bool _color, bool _moved):Piece(_color, _moved){
}

Pawn::~Pawn(){
}

int Pawn::getTypeInt(){
    return TypeInt;
}
