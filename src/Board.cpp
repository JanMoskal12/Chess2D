#include "Board.h"

extern wxBitmapButton* board[8][8];
extern wxBitmap images[2][13];


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

bool Board::sameSquare(){
    return (this->destination == this->clickedSquare);
}

void Board::setDestination(int _nrBB){
    this->destination = this->squares[_nrBB/8][_nrBB%8];
}

void Board::setClickedSquare(int _nrBB){
    this->clickedSquare = this->squares[_nrBB/8][_nrBB%8];
}

bool Board::isPiece(){
   return !(this->clickedSquare->getPiece() == nullptr);
}


