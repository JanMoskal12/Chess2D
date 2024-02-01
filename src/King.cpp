#include "King.h"

King::King(bool _color, bool _moved):Piece(_color, _moved){
}

King::~King(){
}

int King::getTypeInt(){
    return TypeInt;
}
