#include "Bishop.h"

Bishop::Bishop(bool _color, bool _moved):Piece(_color, _moved){
}

Bishop::~Bishop(){
}

int Bishop::getTypeInt(){
    return TypeInt;
}
