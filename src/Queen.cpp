#include "Queen.h"

Queen::Queen(bool _color, bool _moved, string _type):Piece(_color, _moved)
{
    type = _type;
}

Queen::~Queen()
{
    //dtor
}

string Queen :: getType(){
    return type;
}
