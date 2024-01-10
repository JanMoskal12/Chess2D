#include "Board.h"

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
                    squares[8*i + j] = new Square(i, j , true, nullptr);
                }else{
                    squares[8*i + j] = new Square(i, j , false, nullptr);
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

            for(int i = 0; i < 4; i++){
                squares[2*i + 8];
            }

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
