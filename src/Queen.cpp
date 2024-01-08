#include "Queen.h"

Queen::Queen(bool _color, bool _moved):Piece(_color, _moved)
{

}

Queen::~Queen()
{
    //dtor
}

string Queen :: getType(){
    return type;
}
