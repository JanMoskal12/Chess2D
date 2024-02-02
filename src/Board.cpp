#include "Board.h"



extern wxBitmapButton* board[8][8];
extern wxBitmap images[2][13];
extern int counter;
extern int whiteOrBlack;

Board::Board(int i){
    creatingSquares();
    creatingPieces();
    assigningPieces();
}

Board::~Board(){
    cleaning();
}

void Board::cleaning(){
    // Setting nullptr for each Piece in Square
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            squares[i][j]->setPiece(nullptr);
        }
    }

    //Deleting Squares
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            delete squares[i][j];
        }
    }

    // Deleting Pieces
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 7; ++j){
            delete pieces[i][j];
        }
    }
}

void Board::creatingSquares(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i+j) % 2 == 0){
                squares[i][j] = new Square(i, j , true, board[i][j]);
            }else{
                squares[i][j] = new Square(i, j , false, board[i][j]);
            }
        }
    }
}

void Board::creatingPieces(){
    pieces[0][0] = new Pawn(false);
    pieces[0][1] = new Rook(false);
    pieces[0][2] = new Knight(false);
    pieces[0][3] = new Bishop(false);
    pieces[0][4] = new Queen(false);
    pieces[0][5] = new King(false);
    pieces[0][6] = new Rook(false);
    pieces[1][0] = new Pawn(true);
    pieces[1][1] = new Rook(true);
    pieces[1][2] = new Knight(true);
    pieces[1][3] = new Bishop(true);
    pieces[1][4] = new Queen(true);
    pieces[1][5] = new King(true);
    pieces[1][6] = new Rook(true);

}

void Board::assigningPieces(){
    // Assigning Pawns to Squares
    for(int i = 0; i < 8; i++){
        squares[1][i]->setPiece(pieces[0][0]);
        squares[6][i]->setPiece(pieces[1][0]);
    }

    // Assigning other Pieces to Squares
    squares[0][0]->setPiece(pieces[0][1]);
    squares[0][1]->setPiece(pieces[0][2]);
    squares[0][2]->setPiece(pieces[0][3]);
    squares[0][3]->setPiece(pieces[0][4]);
    squares[0][4]->setPiece(pieces[0][5]);
    squares[0][5]->setPiece(pieces[0][3]);
    squares[0][6]->setPiece(pieces[0][2]);
    squares[0][7]->setPiece(pieces[0][6]);
    squares[7][0]->setPiece(pieces[1][1]);
    squares[7][1]->setPiece(pieces[1][2]);
    squares[7][2]->setPiece(pieces[1][3]);
    squares[7][3]->setPiece(pieces[1][4]);
    squares[7][4]->setPiece(pieces[1][5]);
    squares[7][5]->setPiece(pieces[1][3]);
    squares[7][6]->setPiece(pieces[1][2]);
    squares[7][7]->setPiece(pieces[1][6]);

    // Assigning Kings to additional info Squares
    whiteKing = squares[7][4];
    blackKing = squares[0][4];
}

void Board::restart(){
    whiteOrBlack = 1;
    counter = 1;
    clicked = nullptr;
    destination = nullptr;
    whiteKing = nullptr;
    blackKing = nullptr;
    setOfMoves.clear();
    squareBetween = nullptr;;

    cleaning();
    creatingSquares();
    creatingPieces();
    assigningPieces();

    squares[0][0]->getButton()->SetBitmap(images[whiteOrBlack-1][3]);
    squares[0][1]->getButton()->SetBitmap(images[whiteOrBlack-1][6]);
    squares[0][2]->getButton()->SetBitmap(images[whiteOrBlack-1][7]);
    squares[0][3]->getButton()->SetBitmap(images[whiteOrBlack-1][10]);
    squares[0][4]->getButton()->SetBitmap(images[whiteOrBlack-1][11]);
    squares[0][5]->getButton()->SetBitmap(images[whiteOrBlack-1][8]);
    squares[0][6]->getButton()->SetBitmap(images[whiteOrBlack-1][5]);
    squares[0][7]->getButton()->SetBitmap(images[whiteOrBlack-1][4]);

    for(int j = 0; j < 8; j++){
        if(j%2 == 0){
            squares[1][j]->getButton()->SetBitmap(images[whiteOrBlack-1][2]);
        }else{
            squares[1][j]->getButton()->SetBitmap(images[whiteOrBlack-1][1]);
        }
    }

    for(int i = 2; i < 6; i++){
        for(int j = 0; j < 8; j++){
            if((i+j)%2 == 0){
                squares[i][j]->getButton()->SetBitmap(images[whiteOrBlack][0]);
            }else{
                squares[i][j]->getButton()->SetBitmap(images[(whiteOrBlack+1)%2][0]);
            }
        }
    }

    for(int j = 0; j < 8; j++){
        if((j)%2 != 0){
            squares[6][j]->getButton()->SetBitmap(images[whiteOrBlack][2]);
        }else{
            squares[6][j]->getButton()->SetBitmap(images[whiteOrBlack][1]);
        }
    }

    squares[7][0]->getButton()->SetBitmap(images[whiteOrBlack][4]);
    squares[7][1]->getButton()->SetBitmap(images[whiteOrBlack][5]);
    squares[7][2]->getButton()->SetBitmap(images[whiteOrBlack][8]);
    squares[7][3]->getButton()->SetBitmap(images[whiteOrBlack][9]);
    squares[7][4]->getButton()->SetBitmap(images[whiteOrBlack][12]);
    squares[7][5]->getButton()->SetBitmap(images[whiteOrBlack][7]);
    squares[7][6]->getButton()->SetBitmap(images[whiteOrBlack][6]);
    squares[7][7]->getButton()->SetBitmap(images[whiteOrBlack][3]);

}

void Board::setClicked(int _nrBB){
    this->clicked = this->squares[_nrBB/8][_nrBB%8];
}

void Board::setDestination(int _nrBB){
    this->destination = this->squares[_nrBB/8][_nrBB%8];
}

bool Board::isClickedPiece(){
    return !(this->clicked->getPiece() == nullptr);
}

bool Board::isDestinationPiece(){
    return !(this->destination->getPiece() == nullptr);
}

bool Board::ArePiecesSameColor(){
    return (this->clicked->getPiece()->getColor() == this->destination->getPiece()->getColor());
}

bool Board::isGoodColorMoving(){
    return (this->clicked->getPiece()->getColor() == whiteOrBlack);
}

void Board::updateSquares(Square* _clicked, Square* _destination){
    this->destination->setPiece(this->clicked->getPiece());
    this->destination->getButton()->SetBitmap(images[this->clicked->getPiece()->getColor()][this->clicked->getPiece()->getTypeInt()+1-this->destination->getBackgroundColor()]);
    this->destination->getPiece()->setMoved();
    this->clicked->setPiece(nullptr);
    this->clicked->getButton()->SetBitmap(images[this->clicked->getBackgroundColor()][0]);
}

bool Board::isKingInside(){
    return ((this->blackKing == this->clicked) + (this->whiteKing == this->clicked));
}

void Board::wasKingMoving(){
    if(this->isKingInside()){
        if(whiteOrBlack == 1){
            this->whiteKing = this->destination;
            return;
        }
        this->blackKing = this->destination;
    }
}

int Board::whereIsKing(){
    if(whiteOrBlack == 1){
        return (8*this->whiteKing->getRow() + this->whiteKing->getCol());
    }
    return (8*this->blackKing->getRow() + this->blackKing->getCol());
}

bool Board::castling(){
    if(this->clicked != this->squares[whereIsKing()/8][whereIsKing()%8]){
        return 0;
    }

    if(abs((this->destination->getCol() - this->squares[whereIsKing()/8][whereIsKing()%8]->getCol())) == 2){
        if(this->destination->getCol() == 2){
            if(this->squares[this->destination->getRow()][0]->getPiece()->getMoved() == false){
                if(this->isSomethingBetween(this->clicked,this->squares[this->destination->getRow()][0],3 ) == false){
                    this->squares[this->destination->getRow()][3]->setPiece(pieces[this->clicked->getPiece()->getColor()][1]);
                    if(!(this->isBeatable(this->clicked)) && !(this->isBeatable(this->squares[this->destination->getRow()][3]))){
                        this->squares[this->destination->getRow()][3]->setPiece(this->squares[this->destination->getRow()][0]->getPiece());
                        this->squares[this->destination->getRow()][3]->getButton()->SetBitmap(images[this->squares[this->destination->getRow()][0]->getPiece()->getColor()][this->squares[this->destination->getRow()][0]->getPiece()->getTypeInt()+1-this->squares[this->destination->getRow()][3]->getBackgroundColor()]);
                        this->squares[this->destination->getRow()][3]->getPiece()->setMoved();
                        this->squares[this->destination->getRow()][0]->setPiece(nullptr);
                        this->squares[this->destination->getRow()][0]->getButton()->SetBitmap(images[this->squares[this->destination->getRow()][0]->getBackgroundColor()][0]);
                        return 0;
                    }
                }
            }
        }else if(this->destination->getCol() == 6){
            if(this->squares[this->destination->getRow()][7]->getPiece()->getMoved() == false){
                if(this->isSomethingBetween(this->clicked,this->squares[this->destination->getRow()][7], 3) == false){
                    this->squares[this->destination->getRow()][5]->setPiece(pieces[this->clicked->getPiece()->getColor()][1]);
                    if(!(this->isBeatable(this->clicked)) && !(this->isBeatable(this->squares[this->destination->getRow()][3]))){
                        this->squares[this->destination->getRow()][5]->setPiece(this->squares[this->destination->getRow()][7]->getPiece());
                        this->squares[this->destination->getRow()][5]->getButton()->SetBitmap(images[this->squares[this->destination->getRow()][7]->getPiece()->getColor()][this->squares[this->destination->getRow()][7]->getPiece()->getTypeInt()+1-this->squares[this->destination->getRow()][5]->getBackgroundColor()]);
                        this->squares[this->destination->getRow()][5]->getPiece()->setMoved();
                        this->squares[this->destination->getRow()][7]->setPiece(nullptr);
                        this->squares[this->destination->getRow()][7]->getButton()->SetBitmap(images[this->squares[this->destination->getRow()][7]->getBackgroundColor()][0]);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

bool Board::pawnBlockedByPieceInFront(){
    return (this->isDestinationPiece());
}

void Board::pawnMovesButNothingIsInFront(){
    int _col = this->clicked->getCol();
    int _row = this->clicked->getRow();
    if(this->clicked->getPiece()->getColor() == 1){
        this->setOfMoves.insert(8*_row + _col - 8);
    }else{
        this->setOfMoves.insert(8*_row + _col + 8);
    }

    if(this->clicked->getPiece()->getColor() == 1){
        if(this->clicked->getRow() == 6){
            this->setOfMoves.insert(8*_row + _col - 8*2);
        }
    }else{
        if(this->clicked->getRow() == 1){
            this->setOfMoves.insert(8*_row + _col + 8*2);
        }
    }

}

void Board::pawnTakes(){
    int _col = this->clicked->getCol();
    int _row = this->clicked->getRow();
    if((this->destination->getRow()-_row  == -1) && (std::abs(this->destination->getCol()-_col ) == 1 ) && this->clicked->getPiece()->getColor() == 1){
        this->setOfMoves.insert(8*this->destination->getRow() + this->destination->getCol());
    }
    if((this->destination->getRow()-_row  == 1) && (std::abs(this->destination->getCol()-_col ) == 1 ) && this->clicked->getPiece()->getColor() == 0){
        this->setOfMoves.insert(8*this->destination->getRow() + this->destination->getCol());
    }
}

void Board::pawnPromotion(){
    if(this->destination->getPiece()->getTypeInt() == 1 && this->destination->getRow() == 7){
        this->destination->setPiece(this->pieces[0][4]);
        this->destination->getButton()->SetBitmap(images[0][10 - this->destination->getBackgroundColor()]);
    }
    if(this->destination->getPiece()->getTypeInt() == 1 && this->destination->getRow() == 0){
        this->destination->setPiece(this->pieces[1][4]);
        this->destination->getButton()->SetBitmap(images[1][10 - this->destination->getBackgroundColor()]);
    }
}

void Board::whereICanMove(){
    int _col = this->clicked->getCol();
    int _row = this->clicked->getRow();
    this->setOfMoves.clear();
    switch(this->clicked->getPiece()->getTypeInt()){
        case 1:
            if(this->pawnBlockedByPieceInFront()){
                this->pawnTakes();
                return;
            }
            this->pawnMovesButNothingIsInFront();
            break;
        case 3:
            for(int i = 0; i < 8; i++){
                this->setOfMoves.insert(8*i + _col);
                this->setOfMoves.insert(8*_row + i);
            }
            break;
        case 5:
            for(int i = 0; i < 5; i = i+4){
                for(int j = 0; j < 3; j = j+2){
                    if(_row + i  <= 9 && _row + i >=2 && _col + j <= 8 && _col + j >=1 ){
                        this->setOfMoves.insert(8*_row + _col + 8*i + j - 17);
                    }
                    if(_row + j <= 8 && _row + j >=1 && _col + i <= 9 && _col + i >= 2){
                        this->setOfMoves.insert(8*_row + _col + 8*j + i - 10);
                    }
                }
            }
            break;
        case 7:
            for(int i = 1; i < 8; i++){
                if((_row)- i >=0 && _col-i >=0){
                    this->setOfMoves.insert(8*(_row) + (_col) - 8*i -i);
                    }
                if((_row)- i >=0 && _col+i <=7){
                    this->setOfMoves.insert(8*(_row) + (_col) - 8*i +i);
                    }
                if((_row)+ i <=7 && _col+i <=7){
                    this->setOfMoves.insert(8*(_row) + (_col) + 8*i +i);
                }
                if((_row)+i <=7 && _col-i >=0){
                    this->setOfMoves.insert(8*(_row) + (_col) + 8*i -i);
                }
            }
            break;
        case 9:
            for(int i = 1; i < 8; i++){
                if((_row)- i >=0 && _col-i >=0){
                    this->setOfMoves.insert(8*(_row) + (_col) - 8*i -i);
                }
                if((_row)- i >=0 && _col+i <=7){
                    this->setOfMoves.insert(8*(_row) + (_col) - 8*i +i);
                }
                if((_row)+ i <=7 && _col+i <=7){
                    this->setOfMoves.insert(8*(_row) + (_col) + 8*i +i);
                }
                if((_row)+i <=7 && _col-i >=0){
                    this->setOfMoves.insert(8*(_row) + (_col) + 8*i -i);
                }
            }
            for(int i = 0; i < 8; i++){
                this->setOfMoves.insert(8*i + _col);
                this->setOfMoves.insert(8*_row + i);
            }
            break;
        case 11:
            for(int i = 0; i < 3; i++){
                for(int j = 0; j< 3; j++){
                    if( _row + i == 0  || _row + i == 10 || _col + j == 10  || _col + j  == 0 ){
                    }else{
                        this->setOfMoves.insert(8*(_row) + (_col) + 8*i + j - 9);
                    }
                }
           }
           if(this->clicked->getPiece()->getMoved()){
           }else{
                this->setOfMoves.insert(8*(_row) + (_col) + 2);
                this->setOfMoves.insert(8*(_row) + (_col) - 2);
           }
           break;
    }
}

bool Board::isInSetOfMoves(){
    return (this->setOfMoves.find(8*this->destination->getRow() + this->destination->getCol()) != this->setOfMoves.end());
}

bool Board::isSomethingBetween(Square* _squareOne, Square* _squareTwo, int _typeInt){
    int _col = _squareOne->getCol();
    int _row = _squareOne->getRow();
    int wsp_col = - (_col - _squareTwo->getCol())/abs(_col - _squareTwo->getCol());
    this->squareBetween = squares[this->whereIsKing()/8][this->whereIsKing()%8];
    switch(_typeInt){
        case 1:
            if(abs(_row - _squareTwo->getRow()) == 2 && this->clicked->getPiece()->getColor() == 1){
                if(this->squares[ 5 ][_col]->getPiece() != nullptr){
                    return true;
                }
            }
            if(abs(_row - _squareTwo->getRow()) == 2 && this->clicked->getPiece()->getColor() == 0){
                if(this->squares[ 2 ][_col]->getPiece() != nullptr){
                    return true;
                }
            }
            return false;
            break;
        case 3:
            if(_col - _squareTwo->getCol() == 0){
                for(int row = _row - (_row - _squareTwo->getRow())/abs(_row - _squareTwo->getRow()); abs(row - _squareTwo->getRow()) >0; row = row - (row - _squareTwo->getRow())/abs(row - _squareTwo->getRow())){
                    if(this->squares[row][_col]->getPiece() != nullptr){
                        this->squareBetween = this->squares[row][_col];
                        return true;
                    }
                }
                return false;
            }
            if(_row - _squareTwo->getRow() == 0){
                for(int col = _col - (_col - _squareTwo->getCol())/abs(_col - _squareTwo->getCol()); abs(col - _squareTwo->getCol()) >0; col = col - (col - _squareTwo->getCol())/abs(col - _squareTwo->getCol())){
                    if(this->squares[_row][col]->getPiece() != nullptr){
                       this->squareBetween = this->squares[_row][col];
                       return true;
                    }
                }
                return false;
            }
           break;
        case 7:
            for(int wsp = _row - (_row - _squareTwo->getRow())/abs(_row - _squareTwo->getRow()); abs(wsp - _squareTwo->getRow()) >0; wsp = wsp - (wsp - _squareTwo->getRow())/abs(wsp - _squareTwo->getRow())){
                if(this->squares[wsp][_col + wsp_col]->getPiece() != nullptr){
                    this->squareBetween = this->squares[wsp][_col + wsp_col];
                    return true;
                }else{
                    _col = wsp_col + _col;
                }
            }
            return false;
            break;
        case 9:
            wsp_col = - (_col - _squareTwo->getCol())/abs(_col - _squareTwo->getCol());
            if(_col - _squareTwo->getCol() == 0){
                for(int row = _row - (_row - _squareTwo->getRow())/abs(_row - _squareTwo->getRow()); abs(row - _squareTwo->getRow()) >0; row = row - (row - _squareTwo->getRow())/abs(row - _squareTwo->getRow())){
                    if(this->squares[row][_col]->getPiece() != nullptr){
                        return true;
                    }
                }
                return false;
            }
            if(_row - _squareTwo->getRow() == 0){
                for(int col = _col - (_col - _squareTwo->getCol())/abs(_col - _squareTwo->getCol()); abs(col - _squareTwo->getCol()) >0; col = col - (col - _squareTwo->getCol())/abs(col - _squareTwo->getCol())){
                    if(this->squares[_row][col]->getPiece() != nullptr){
                       return true;
                    }
                }
                return false;
            }
            for(int wsp = _row - (_row - _squareTwo->getRow())/abs(_row - _squareTwo->getRow()); abs(wsp - _squareTwo->getRow()) >0; wsp = wsp - (wsp - _squareTwo->getRow())/abs(wsp - _squareTwo->getRow())){
                if(this->squares[wsp][_col + wsp_col]->getPiece() != nullptr){
                    return true;
                }else{
                    _col = wsp_col + _col;
                }
            }
            return false;
            break;

        default:
            return false;
    }
    return false;
}



bool Board::isBeatable(Square* _square){
    int _Row = _square->getRow();
    int _Col = _square->getCol();

    //is Rook checking us
    for(int i = 0; i < 8; i = i+7){
         if(_Row != i && isSomethingBetween(squares[_Row][_Col], squares[i][_Col], 3)){
            if(this->squareBetween->getPiece()->getTypeInt() == 3 || this->squareBetween->getPiece()->getTypeInt() == 9){
                if(this->squares[_Row][_Col]->getPiece()->getColor() != this->squareBetween->getPiece()->getColor()){
                    return true;
                }
            }
         }else{
            if(_Row != i && this->squares[i][_Col]->getPiece() != nullptr && this->squares[_Row][_Col]->getPiece()->getColor() != this->squares[i][_Col]->getPiece()->getColor()){
                if(this->squares[i][_Col]->getPiece()->getTypeInt() == 9 || this->squares[i][_Col]->getPiece()->getTypeInt() == 3){
                    return true;
                }
            }
         }
         if(_Col != i && isSomethingBetween(squares[_Row][_Col], squares[_Row][i], 3)){
            if(this->squareBetween->getPiece()->getTypeInt() == 3 || this->squareBetween->getPiece()->getTypeInt() == 9){
                if(this->squares[_Row][_Col]->getPiece()->getColor() != this->squareBetween->getPiece()->getColor()){
                    return true;
                }
            }
         }else{
            if(_Col != i && this->squares[_Row][i]->getPiece() != nullptr && this->squares[_Row][_Col]->getPiece()->getColor() != this->squares[_Row][i]->getPiece()->getColor()){
                if(this->squares[_Row][i]->getPiece()->getTypeInt() == 9 || this->squares[_Row][i]->getPiece()->getTypeInt() == 3){
                    return true;
                }
            }
         }

    }

    //is Bishop checking us
    for(int i = 1; i < 8; i++){
        if((_Row)- i >=0 && _Col-i >=0){
            if(squares[_Row-i][_Col-i]->getPiece() != nullptr){
                if(this->squares[_Row][_Col]->getPiece()->getColor()!= this->squares[_Row-i][_Col-i]->getPiece()->getColor()){
                    if(this->squares[_Row-i][_Col-i]->getPiece()->getTypeInt() == 7 || this->squares[_Row-i][_Col-i]->getPiece()->getTypeInt() == 9){
                        return true;
                    }
                }
                i = i+10;
            }
        }
    }

    for(int i = 1; i < 8; i++){
        if((_Row)- i >=0 && _Col+i <=7){
            if(squares[_Row-i][_Col+i]->getPiece() != nullptr){
                if(this->squares[_Row][_Col]->getPiece()->getColor()!= this->squares[_Row-i][_Col+i]->getPiece()->getColor()){
                    if(this->squares[_Row-i][_Col+i]->getPiece()->getTypeInt() == 7 || this->squares[_Row-i][_Col+i]->getPiece()->getTypeInt() == 9){
                        return true;
                    }
                }
                i = i+10;
            }
        }
    }

    for(int i = 1; i < 8; i++){
        if((_Row)+ i <=7 && _Col+i <=7){
            if(squares[_Row+i][_Col+i]->getPiece() != nullptr){
                if(this->squares[_Row][_Col]->getPiece()->getColor()!= this->squares[_Row+i][_Col+i]->getPiece()->getColor()){
                    if(this->squares[_Row+i][_Col+i]->getPiece()->getTypeInt() == 7 || this->squares[_Row+i][_Col+i]->getPiece()->getTypeInt() == 9){
                        return true;
                    }
                }
                i = i+10;
            }
        }
    }

    for(int i = 1; i < 8; i++){
        if((_Row)+ i <=7 && _Col-i >=0){
            if(squares[_Row+i][_Col-i]->getPiece() != nullptr){
                if(this->squares[_Row][_Col]->getPiece()->getColor()!= this->squares[_Row+i][_Col-i]->getPiece()->getColor()){
                    if(this->squares[_Row+i][_Col-i]->getPiece()->getTypeInt() == 7 || this->squares[_Row+i][_Col-i]->getPiece()->getTypeInt() == 9){
                        return true;
                    }
                }
                i = i+10;
            }
        }
    }

    //is Pawn checking us
    for(int i = -1; i < 2; i = i + 2){
        if(_Row == 0){
        }else{
            if(squares[_Row - 1][_Col - i]->getPiece() != nullptr){
                if(this->squares[_Row][_Col]->getPiece()->getColor() != this->squares[_Row - 1][_Col - i]->getPiece()->getColor()){
                    if(this->squares[_Row - 1][_Col - i]->getPiece()->getTypeInt() == 1 && this->squares[_Row - 1][_Col - i]->getPiece()->getColor() == 0){
                        return true;
                    }
                }
            }
        }
    }

    for(int i = -1; i < 2; i = i + 2){
        if(_Row == 7){
        }else{
            if(squares[_Row + 1][_Col - i]->getPiece() != nullptr){
                if(this->squares[_Row][_Col]->getPiece()->getColor()!= this->squares[_Row + 1][_Col - i]->getPiece()->getColor()){
                    if(this->squares[_Row + 1][_Col - i]->getPiece()->getTypeInt() == 1 && this->squares[_Row + 1][_Col - i]->getPiece()->getColor() == 1){
                        return true;
                    }
                }
            }
        }
    }

    // is Knight checking us
    for(int i = 0; i < 5; i = i+4){
        for(int j = 0; j < 3; j = j+2){
            if(_Row + i  <= 9 && _Row + i >=2 && _Col + j <= 8 && _Col + j >=1 ){
                if(squares[_Row + i - 2][_Col + j - 1]->getPiece() != nullptr){
                    if(this->squares[_Row][_Col]->getPiece()->getColor()!= this->squares[_Row + i - 2][_Col + j - 1]->getPiece()->getColor()){
                        if(this->squares[_Row + i - 2][_Col + j - 1]->getPiece()->getTypeInt() == 5){
                            return true;
                        }
                    }
                }
            }
            if(_Row + j <= 8 && _Row + j >=1 && _Col + i <= 9 && _Col + i >= 2){
                if(squares[_Row + j - 1][_Col + i - 2]->getPiece() != nullptr){
                    if(this->squares[_Row][_Col]->getPiece()->getColor()!= this->squares[_Row + j - 1][_Col + i - 2]->getPiece()->getColor()){
                        if(this->squares[_Row + j - 1][_Col + i - 2]->getPiece()->getTypeInt() == 5){
                            return true;
                        }
                    }
                }
            }
        }
    }

    // is King checking us
    if(abs(this->whiteKing->getCol()-this->blackKing->getCol())<=1 && abs(this->whiteKing->getRow()-this->blackKing->getRow())<=1){
        return true;
    }
    return false;
}

bool Board::moveSimulation(){
    bool x = false;
    this->wasKingMoving();
    Square* pieceStorage = new Square(-1, -1, 0, board[0][0], nullptr);
    if(this->destination->getPiece() != nullptr){
        pieceStorage->setPiece(this->destination->getPiece());
    }
    this->destination->setPiece(this->clicked->getPiece());
    this->clicked->setPiece(nullptr);
    if(this->isBeatable(this->squares[whereIsKing()/8][whereIsKing()%8])){
        x = true;
    }
    this->clicked->setPiece(this->destination->getPiece());
    if(pieceStorage->getPiece() == nullptr){
        this->destination->setPiece(nullptr);
    }else{
        this->destination->setPiece(pieceStorage->getPiece());
    }
    if((this->blackKing == this->destination) + (this->whiteKing == this->destination) == 1){
        if(whiteOrBlack == 1){
            this->whiteKing = this->clicked;
        }else{
            this->blackKing = this->clicked;
        }
    }
    delete pieceStorage;
    return x;
}
