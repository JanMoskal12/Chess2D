#include "Knight.h"

Knight::Knight(bool _color, bool _moved):Piece(_color, _moved){
}

Knight::~Knight(){
}

int Knight::getTypeInt(){
    return TypeInt;
}
