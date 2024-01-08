#include "pawn.h"

Pawn::Pawn(bool _color, bool _moved, string _type):Piece(_color, _moved){
    type = _type;
}

Pawn::~Pawn(){
}

string Pawn::getType(){
    return type;
}
