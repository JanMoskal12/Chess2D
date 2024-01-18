#include "Board.h"



extern wxBitmapButton* board[8][8];
extern wxBitmap images[2][13];
extern int whiteOrBlack;

Board::Board(int i)
{


         for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if((i+j) % 2 == 0){
                    squares[i][j] = new Square(i, j , true, board[i][j]);
                }else{
                    squares[i][j] = new Square(i, j , false, board[i][j]);
                }
            }
         }


            pieces[0][0] = new Pawn(false);
            pieces[0][1] = new Rook(false);
            pieces[0][2] = new Knight(false);
            pieces[0][3] = new Bishop(false);
            pieces[0][4] = new Queen(false);
            pieces[0][5] = new King(false);
            pieces[1][0] = new Pawn(true);
            pieces[1][1] = new Rook(true);
            pieces[1][2] = new Knight(true);
            pieces[1][3] = new Bishop(true);
            pieces[1][4] = new Queen(true);
            pieces[1][5] = new King(true);



            //Pawns
            for(int i = 0; i < 8; i++){
                squares[1][i]->setPiece(pieces[0][0]);
                squares[6][i]->setPiece(pieces[1][0]);
            }

            //Other Pieces
                squares[0][0]->setPiece(pieces[0][1]);
                squares[0][1]->setPiece(pieces[0][2]);
                squares[0][2]->setPiece(pieces[0][3]);
                squares[0][3]->setPiece(pieces[0][4]);
                squares[0][4]->setPiece(pieces[0][5]);
                squares[0][5]->setPiece(pieces[0][3]);
                squares[0][6]->setPiece(pieces[0][2]);
                squares[0][7]->setPiece(pieces[0][1]);
                squares[7][0]->setPiece(pieces[1][1]);
                squares[7][1]->setPiece(pieces[1][2]);
                squares[7][2]->setPiece(pieces[1][3]);
                squares[7][3]->setPiece(pieces[1][4]);
                squares[7][4]->setPiece(pieces[1][5]);
                squares[7][5]->setPiece(pieces[1][3]);
                squares[7][6]->setPiece(pieces[1][2]);
                squares[7][7]->setPiece(pieces[1][1]);

                whiteKing = squares[7][4];
                blackKing = squares[0][4];

}

Board::~Board()
{

}

void Board::swapSquares(){
    this->destination->setPiece(this->clickedSquare->getPiece());
    this->destination->getButton()->SetBitmap(images[this->clickedSquare->getPiece()->getColor()][this->clickedSquare->getPiece()->getTypeInt()+1-this->destination->getBackgroundColor()]);
    this->clickedSquare->setPiece(nullptr);
    this->clickedSquare->getButton()->SetBitmap(images[this->clickedSquare->getBackgroundColor()][0]);
}

void Board::setDestination(int _nrBB){
    this->destination = this->squares[_nrBB/8][_nrBB%8];
}

void Board::setClickedSquare(int _nrBB){
    this->clickedSquare = this->squares[_nrBB/8][_nrBB%8];
}

bool Board::isClickedPiece(){
   return !(this->clickedSquare->getPiece() == nullptr);
}

bool Board::isDestinationPiece(){
   return !(this->destination->getPiece() == nullptr);
}

bool Board::isSameColor(){
    return (this->clickedSquare->getPiece()->getColor() == this->destination->getPiece()->getColor());
}

 bool Board::isKing(){
    return ((this->blackKing == this->clickedSquare) + (this->whiteKing == this->clickedSquare));
 }

bool Board::isGoodColorMoving(){
    return (this->clickedSquare->getPiece()->getColor() == whiteOrBlack);
}

void Board::wasKingMoving(){
    if(this->isKing()){
        if(whiteOrBlack%2 == 1){
            this->whiteKing = this->destination;
            //auto test = _B->isKingInCheck(_B->whiteKing);
            //wxLogMessage("White king moving");
            return;
        }
    this->blackKing = this->destination;
    //wxLogMessage("Black king moving");
    }
}
int Board::whereIsKing(){
    if(whiteOrBlack == 1){
        return (8*this->whiteKing->getRow() + this->whiteKing->getCol());
    }
    return (8*this->blackKing->getRow() + this->blackKing->getCol());
}

void Board::whereICanMove(){
    int _col = this->clickedSquare->getCol();
    int _row = this->clickedSquare->getRow();
    this->setOfMoves.clear();
    switch(this->clickedSquare->getPiece()->getTypeInt()){
        case 1:
            if(this->pawnPieceInFront()){
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
                    if(_row + i <= 10 && _row + i >=2 && _col + j <= 6 && _col + j >=1 ){
                        this->setOfMoves.insert(8*_row + _col + 8*i + j - 17);
                    }
                    if(_row + j <= 8 && _row + j >=1 && _col + i <= 10 && _col + i >= 2){
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
           break;


    }
}

bool Board::isInSetOfMoves(){
    return (this->setOfMoves.find(8*this->destination->getRow() + this->destination->getCol()) != this->setOfMoves.end());
}

bool Board::pawnPieceInFront(){
        return (this->isDestinationPiece());
}





void Board::pawnMovesButNothingIsInFront(){
int _col = this->clickedSquare->getCol();
int _row = this->clickedSquare->getRow();

if(this->clickedSquare->getPiece()->getColor() == 1){
                this->setOfMoves.insert(8*_row + _col - 8);
            }else{
                this->setOfMoves.insert(8*_row + _col + 8);
            }


if(this->clickedSquare->getPiece()->getColor() == 1){
    if(this->clickedSquare->getRow() == 6){
        this->setOfMoves.insert(8*_row + _col - 8*2);
    }
    }else{
        if(this->clickedSquare->getRow() == 1){
            this->setOfMoves.insert(8*_row + _col + 8*2);
        }
    }

}

void Board::pawnTakes(){
    int _col = this->clickedSquare->getCol();
    int _row = this->clickedSquare->getRow();
    if((this->destination->getRow()-_row  == -1) && (std::abs(this->destination->getCol()-_col ) == 1 ) && this->clickedSquare->getPiece()->getColor() == 1){
        this->setOfMoves.insert(8*this->destination->getRow() + this->destination->getCol());
    }
    if((this->destination->getRow()-_row  == 1) && (std::abs(this->destination->getCol()-_col ) == 1 ) && this->clickedSquare->getPiece()->getColor() == 0){
        this->setOfMoves.insert(8*this->destination->getRow() + this->destination->getCol());
    }
}



bool Board::isSomethingBetween(){
    int _col = this->clickedSquare->getCol();
    int _row = this->clickedSquare->getRow();
    int wsp_col = - (_col - this->destination->getCol())/abs(_col - this->destination->getCol());
    switch(this->clickedSquare->getPiece()->getTypeInt()){
        case 1:
            if(abs(_row - this->destination->getRow()) == 2 && this->clickedSquare->getPiece()->getColor() == 1){
                if(this->squares[ 5 ][_col]->getPiece() != nullptr){
                    return true;
                }
            }
            if(abs(_row - this->destination->getRow()) == 2 && this->clickedSquare->getPiece()->getColor() == 0){
                if(this->squares[ 2 ][_col]->getPiece() != nullptr){
                    return true;
                }
            }
            return false;
            break;
        case 3://40 50 60
            if(_col - this->destination->getCol() == 0){
                for(int row = _row - (_row - this->destination->getRow())/abs(_row - this->destination->getRow()); abs(row - this->destination->getRow()) >0; row = row - (row - this->destination->getRow())/abs(row - this->destination->getRow())){
                    if(this->squares[row][_col]->getPiece() != nullptr){
                        return true;
                    }
                }
                return false;
            }
            if(_row - this->destination->getRow() == 0){
                for(int col = _col - (_col - this->destination->getCol())/abs(_col - this->destination->getCol()); abs(col - this->destination->getCol()) >0; col = col - (col - this->destination->getCol())/abs(col - this->destination->getCol())){
                    if(this->squares[_row][col]->getPiece() != nullptr){
                       return true;
                    }
                }
                return false;
            }

           break;

        case 7:
            for(int wsp = _row - (_row - this->destination->getRow())/abs(_row - this->destination->getRow()); abs(wsp - this->destination->getRow()) >0; wsp = wsp - (wsp - this->destination->getRow())/abs(wsp - this->destination->getRow())){
                if(this->squares[wsp][_col + wsp_col]->getPiece() != nullptr){
                       return true;
                }else{
                _col = wsp_col + _col;
                }
            }
            return false;
            break;

        case 9:
            wsp_col = - (_col - this->destination->getCol())/abs(_col - this->destination->getCol());
            if(_col - this->destination->getCol() == 0){
                for(int row = _row - (_row - this->destination->getRow())/abs(_row - this->destination->getRow()); abs(row - this->destination->getRow()) >0; row = row - (row - this->destination->getRow())/abs(row - this->destination->getRow())){
                    if(this->squares[row][_col]->getPiece() != nullptr){
                        return true;
                    }
                }
                return false;
            }
            if(_row - this->destination->getRow() == 0){
                for(int col = _col - (_col - this->destination->getCol())/abs(_col - this->destination->getCol()); abs(col - this->destination->getCol()) >0; col = col - (col - this->destination->getCol())/abs(col - this->destination->getCol())){
                    if(this->squares[_row][col]->getPiece() != nullptr){
                       return true;
                    }
                }
                return false;
            }
            for(int wsp = _row - (_row - this->destination->getRow())/abs(_row - this->destination->getRow()); abs(wsp - this->destination->getRow()) >0; wsp = wsp - (wsp - this->destination->getRow())/abs(wsp - this->destination->getRow())){
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
return true;
}


bool Board::isMyKingInCheck(){
    int _col = this->clickedSquare->getCol();
    int _row = this->clickedSquare->getRow();
    int kingRow;
    int kingCol;
    if(this->clickedSquare->getPiece()->getColor() == 1){
        kingRow = this->whiteKing->getRow();
        kingCol = this->whiteKing->getCol();
    }else{
        kingRow = this->blackKing->getRow();
        kingCol = this->blackKing->getCol();
    }


}
