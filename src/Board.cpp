#include "Board.h"

extern wxBitmapButton* board[64];

Board::Board()
{

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------





         squares = new Square*[64];

         for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if((i+j)%2 == 0){
                    squares[8*i + j] = new Square(i, j , true, nullptr, board[8*i+j]);
                }else{
                    squares[8*i + j] = new Square(i, j , false, nullptr,board[8*i+j]);
                }

            }

         }


	        pieces = new Piece*[12];

            pieces[0] = new Pawn(0 , 0);
            pieces[1] = new Rook(0 , 0);
            pieces[2] = new Knight(0 , 0);
            pieces[3] = new Bishop(0 , 0);
            pieces[4] = new Queen(0 , 0);
            pieces[5] = new King(0 , 0);
            pieces[6] = new Pawn(1 , 0);
            pieces[7] = new Rook(1 , 0);
            pieces[8] = new Knight(1 , 0);
            pieces[9] = new Bishop(1 , 0);
            pieces[10] = new Queen(1 , 0);
            pieces[11] = new King(1 , 0);

            //Pawns
            for(int i = 0; i < 8; i++){
                squares[i + 8]->setPiece(pieces[0]);
                squares[i + 48]->setPiece(pieces[6]);
            }

            //Pieces

                squares[0]->setPiece(pieces[1]);
                squares[1]->setPiece(pieces[2]);
                squares[2]->setPiece(pieces[3]);
                squares[3]->setPiece(pieces[4]);
                squares[4]->setPiece(pieces[5]);
                squares[5]->setPiece(pieces[3]);
                squares[6]->setPiece(pieces[2]);
                squares[7]->setPiece(pieces[1]);
                squares[56]->setPiece(pieces[7]);
                squares[57]->setPiece(pieces[8]);
                squares[58]->setPiece(pieces[9]);
                squares[59]->setPiece(pieces[10]);
                squares[60]->setPiece(pieces[11]);
                squares[61]->setPiece(pieces[9]);
                squares[62]->setPiece(pieces[8]);
                squares[63]->setPiece(pieces[7]);


}

Board::~Board()
{
    for(int i = 0 ; i <12 ; i++){
        delete pieces[i];
    }
    delete[] pieces;

    for(int i = 0 ; i <64 ; i++){
        delete squares[i];
    }
    delete[] squares;


}
