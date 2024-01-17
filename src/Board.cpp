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
    this->destination->getPiece()->setMoved();
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
    switch(this->clickedSquare->getPiece()->getTypeInt()){
        case 1:
            for(int i = 0; i < 3; i++){
                for(int j = 0; j< 3; j++){
                    if( _row + i == 0  || _row + i == 10 || _col + j == 10  || _col + j  == 0 ){
                        return;
                    }else{
                        this->setOfMoves.insert(8*(_row) + (_col) + 8*i + j - 9);
                    }
                }

}            break;
        case 3:
            break;
        case 5:
            break;
        case 7:
            break;
        case 9:
            break;
        case 11:

            for(int i = 0; i < 3; i++){
                for(int j = 0; j< 3; j++){
                    if( _row + i - 1 == -1  || _row + i - 1 == 8 || _col + j - 1 == -1  || _col + i - 1 == 8 ){
                    }else{
                        this->setOfMoves.insert(8*_row + _col + 8*i + j - 9);
                    }
                }
            }
            break;


    }
}

bool Board::isInSetOfMoves(){
    return (this->setOfMoves.find(8*this->destination->getRow() + this->destination->getCol()) != this->setOfMoves.end());
}

 /*
 bool Board::isKingInCheck(Square* king){

 }
*/
