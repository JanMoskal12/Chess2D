#include "Bishop.h"

Bishop::Bishop(bool _color, bool _moved):Piece(_color, _moved)
{

}

Bishop::~Bishop()
{
    //dtor
}

string Bishop:: getType(){
    return type;
}
