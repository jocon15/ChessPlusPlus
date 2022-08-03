#include <iostream>
#include <vector>
#include <memory>
#include <windows.h>
#include <cstdlib>
#include "chess_game.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "pawn.hpp"

using namespace std;


ChessGame::ChessGame() {
	//check that a ChessGame instance does not already exist
	
	this->moveCounter = 0;
	buildPieces();
	resetChessGame();
}

void ChessGame::createChessGame() {
	ChessGame(); //singleton later

	resetChessGame();
}

ChessGame::~ChessGame() {
	//UNIQUE POINTERS ARE GARBAGE COLLECTED
	for (int i = 0; i < allPieces.size(); i++) {
		delete allPieces.at(i);
	}
}

void ChessGame::buildPieces() {
	// piece:					type, color, row, col, name, number
	this->whitePawn1 =   new Piece(6, 1, 6, 0, "WhitePawn", 1);
	this->whitePawn2 =   new Piece(6, 1, 6, 1, "WhitePawn", 2);
	this->whitePawn3 =   new Piece(6, 1, 6, 2, "WhitePawn", 3);
	this->whitePawn4 =   new Piece(6, 1, 6, 3, "WhitePawn", 4);
	this->whitePawn5 =   new Piece(6, 1, 6, 4, "WhitePawn", 5);
	this->whitePawn6 =   new Piece(6, 1, 6, 5, "WhitePawn", 6);
	this->whitePawn7 =   new Piece(6, 1, 6, 6, "WhitePawn", 7);
	this->whitePawn8 =   new Piece(6, 1, 6, 7, "WhitePawn", 8);
	this->whiteRook1 =   new Piece(5, 1, 7, 0, "WhiteRook", 1);
	this->whiteRook2 =   new Piece(5, 1, 7, 7, "WhiteRook", 2);
	this->whiteKnight1 = new Piece(4, 1, 7, 1, "WhiteKnight", 1);
	this->whiteKnight2 = new Piece(4, 1, 7, 6, "WhiteKnight", 2);
	this->whiteBishop1 = new Piece(3, 1, 7, 2, "WhiteBishop", 1);
	this->whiteBishop2 = new Piece(3, 1, 7, 5, "WhiteBishop", 2);
	this->whiteQueen =	 new Piece(2, 1, 7, 3, "WhiteQueen", 1);
	this->whiteKing =    new Piece(1, 1, 7, 4, "WhiteKing", 1);

	this->blackPawn1 =   new Piece(6, 0, 1, 0, "BlackPawn", 1);
	this->blackPawn2 =   new Piece(6, 0, 1, 1, "BlackPawn", 2);
	this->blackPawn3 =   new Piece(6, 0, 1, 2, "BlackPawn", 3);
	this->blackPawn4 =   new Piece(6, 0, 1, 3, "BlackPawn", 4);
	this->blackPawn5 =   new Piece(6, 0, 1, 4, "BlackPawn", 5);
	this->blackPawn6 =   new Piece(6, 0, 1, 5, "BlackPawn", 6);
	this->blackPawn7 =   new Piece(6, 0, 1, 6, "BlackPawn", 7);
	this->blackPawn8 =   new Piece(6, 0, 1, 7, "BlackPawn", 8);
	this->blackRook1 =   new Piece(5, 0, 0, 0, "BlackRook", 1);
	this->blackRook2 =   new Piece(5, 0, 0, 7, "BlackRook", 2);
	this->blackKnight1 = new Piece(4, 0, 0, 1, "BlackKnight", 1);
	this->blackKnight2 = new Piece(4, 0, 0, 6, "BlackKnight", 2);
	this->blackBishop1 = new Piece(3, 0, 0, 2, "BlackBishop", 1);
	this->blackBishop2 = new Piece(3, 0, 0, 5, "BlackBishop", 2);
	this->blackQueen =   new Piece(2, 0, 0, 3, "BlackQueen", 1);
	this->blackKing =    new Piece(1, 0, 0, 4, "BlackKing", 1);

	this->allPieces.push_back(whitePawn1);
	this->allPieces.push_back(whitePawn2);
	this->allPieces.push_back(whitePawn3);
	this->allPieces.push_back(whitePawn4);
	this->allPieces.push_back(whitePawn5);
	this->allPieces.push_back(whitePawn6);
	this->allPieces.push_back(whitePawn7);
	this->allPieces.push_back(whitePawn8);
	this->allPieces.push_back(whiteRook1);
	this->allPieces.push_back(whiteKnight1);
	this->allPieces.push_back(whiteBishop1);
	this->allPieces.push_back(whiteQueen);
	this->allPieces.push_back(whiteKing);
	this->allPieces.push_back(whiteBishop2);
	this->allPieces.push_back(whiteKnight2);
	this->allPieces.push_back(whiteRook2);

	this->allPieces.push_back(blackPawn1);
	this->allPieces.push_back(blackPawn2);
	this->allPieces.push_back(blackPawn3);
	this->allPieces.push_back(blackPawn4);
	this->allPieces.push_back(blackPawn5);
	this->allPieces.push_back(blackPawn6);
	this->allPieces.push_back(blackPawn7);
	this->allPieces.push_back(blackPawn8);
	this->allPieces.push_back(blackRook1);
	this->allPieces.push_back(blackKnight1);
	this->allPieces.push_back(blackBishop1);
	this->allPieces.push_back(blackQueen);
	this->allPieces.push_back(blackKing);
	this->allPieces.push_back(blackBishop2);
	this->allPieces.push_back(blackKnight2);
	this->allPieces.push_back(blackRook2);
}

void ChessGame::resetChessGame() {


	this->moveCounter = 0;
	// this is the correct implementation for building a pointer to a chess piece
	// Piece* pawn = new Piece(6, 0);	// pice type, piece team


	// I think this is using unsafe pointers
	//unique_ptr<Piece> blackPawn1 (new Piece(6, 0, 0, 0));
	

	//build the board
	board = {
		{blackRook1, blackKnight1, blackBishop1, blackQueen, blackKing, blackBishop2, blackKnight2, blackRook2},
		{blackPawn1, blackPawn2, blackPawn3, blackPawn4, blackPawn5, blackPawn6, blackPawn7, blackPawn8},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{whitePawn1, whitePawn2, whitePawn3, whitePawn4, whitePawn5, whitePawn6, whitePawn7, whitePawn8},
		{whiteRook1, whiteKnight1, whiteBishop1, whiteQueen, whiteKing, whiteBishop2, whiteKnight2, whiteRook2}
	};
	
	whitePieces = {whitePawn1, whitePawn2, whitePawn3, whitePawn4, whitePawn5, whitePawn6, whitePawn7, whitePawn8,
		whiteRook1, whiteKnight1, whiteBishop1, whiteQueen, whiteKing, whiteBishop2, whiteKnight2, whiteRook2};

	blackPieces = {blackPawn1, blackPawn2, blackPawn3, blackPawn4, blackPawn5, blackPawn6, blackPawn7, blackPawn8, 
		blackRook1, blackKnight1, blackBishop1, blackQueen, blackKing, blackBishop2, blackKnight2, blackRook2};


	//build the board
	//board = {
	//	{new Piece(5, 0, 0, 0), new Piece(4, 0, 0, 1), new Piece(3, 0, 0, 2), new Piece(2, 0, 0, 3), new Piece(1, 0, 0, 4), new Piece(3, 0, 0, 5), new Piece(4, 0, 0, 6), new Piece(5, 0, 0, 7)},
	//	{new Piece(6, 0, 0, 0), new Piece(6, 0, 0, 1), new Piece(6, 0, 0, 2), new Piece(6, 0, 0, 3), new Piece(6, 0, 0, 4), new Piece(6, 0, 0, 5), new Piece(6, 0, 0, 6), new Piece(6, 0, 0, 7)},
	//	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	//	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	//	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	//	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	//	{new Piece(6, 1, 6, 0), new Piece(6, 1, 6, 1), new Piece(6, 1, 6, 2), new Piece(6, 1, 6, 3), new Piece(6, 1, 6, 4), new Piece(6, 1, 6, 5), new Piece(6, 0, 6, 6), new Piece(6, 1, 6, 7)},
	//	{new Piece(5, 1, 6, 0), new Piece(4, 1, 6, 1), new Piece(3, 1, 6, 2), new Piece(2, 1, 6, 3), new Piece(1, 1, 6, 4), new Piece(3, 1, 6, 5), new Piece(4, 0, 6, 6), new Piece(5, 1, 6, 7)}
	//};
}

vector<vector<Piece*>> ChessGame::getBoard() {
	return board;
}

void ChessGame::movePiece(operation::Move* move) {
	//get the piece at the origin
	int i;
	int FORWARD_1;
	Piece* originPiece = board.at(move->originRow).at(move->originCol);
	Piece* targetPiece = board.at(move->destinationRow).at(move->destinationCol);

	if (originPiece->getPieceColor() == 0) 
		FORWARD_1= 1;
	else
		FORWARD_1 = -1;
	

	//check if there's a piece in the destination
	if (targetPiece == nullptr) {
		//no capture
		//move the piece to the destination
		
		// en passant logic
		if (originPiece->getPieceType() == 6) {
			int posPawnRow = move->destinationRow + -FORWARD_1;
			int posPawnCol = move->destinationCol;
			if (operation::isInBounds(posPawnRow, posPawnCol)) {
				Piece* possiblePawn = board.at(posPawnRow).at(posPawnCol);
				if (possiblePawn != nullptr) {
					if (possiblePawn->getPieceType() == 6) {
						if (possiblePawn->getPreviousRow() == move->destinationRow - (-FORWARD_1)) {
							// capture
							if (possiblePawn->getPieceColor() == 0) {
								//target is black
								for (i = 0; i < blackPieces.size(); i++) {
									if (blackPieces.at(i) == possiblePawn) {
										//remove the balck piece from black's pieces
										blackPieces.erase(remove(blackPieces.begin(), blackPieces.end(), possiblePawn), blackPieces.end());
										break;
									}
								}
							}
							else {
								//target is white
								for (i = 0; i < whitePieces.size(); i++) {
									if (whitePieces.at(i) == possiblePawn) {
										//remove the white piece from white's pieces
										whitePieces.erase(remove(whitePieces.begin(), whitePieces.end(), possiblePawn), whitePieces.end());
										break;
									}
								}
							}
							// capture the possible pawn
							board.at(posPawnRow).at(posPawnCol) = nullptr;

							// move the piece to the desintation
							originPiece->movePiece(move->destinationRow, move->destinationCol);
						}
					}
				}
			}
		}
	}
	else {
		//capture
		if (targetPiece->getPieceColor() == 0) {
			//target is black
			for (i = 0; i < blackPieces.size(); i++) {
				if (blackPieces.at(i) == targetPiece) {
					//remove the balck piece from black's pieces
					blackPieces.erase(remove(blackPieces.begin(), blackPieces.end(), targetPiece), blackPieces.end());
				}
			}
		}
		else {
			//target is white
			for (i = 0; i < whitePieces.size(); i++) {
				if (whitePieces.at(i) == targetPiece) {
					//remove the white piece from white's pieces
					whitePieces.erase(remove(whitePieces.begin(), whitePieces.end(), targetPiece), whitePieces.end());
				}
			}
		}
	}

	//move the piece to the desintation
	originPiece->movePiece(move->destinationRow, move->destinationCol);
	
	// if the piece is a pawn that finished its first move
	if (originPiece->getPieceType() == 6) {
		originPiece->setHasBeenMoved();
	}

	//move the piece on the board
	board.at(move->destinationRow).at(move->destinationCol) = originPiece;
	//set the previous spot to null
	board.at(move->originRow).at(move->originCol) = nullptr;
	//update the move counter
	moveCounter++;
}	

void ChessGame::printBoard() {
	//    0   1   2   3   4   5   6   7
	//	-------------------------------
	//	0 | BR1 | BK1 | BB1 | BQ | BK | BB2 | BK2 | BR2 |
	//	1 | BP1 | BP2 | BP3 | BP4 | BP5 | BP6 | BP7 | BP8 |
	//	2 |   |   |   |   |   |   |   |   |
	//	3	|   |   |   |   |   |   |   |   |
	//	4	|   |   |   |   |   |   |   |   |
	//	5	|   |   |   |   |   |   |   |   |
	//	6 | WP1 | WP2 | WP3 | WP4 | WP5 | WP6 | WP7 | WP8 |
	//	7 | WR1 | WK1 | WB1 | WQ | WK | WB2 | WK2 | WR2 |
	//	-------------------------------
	//system("Color 07");
	cout << "     0   1   2   3   4   5   6   7" << endl;
	cout << "   ---------------------------------" << endl;
	int row;
	int col;
	//https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
	Piece* currentPiece;
	for (row = 0; row < board.size(); row++) {
		cout << " " << row << " ";
		for (col = 0; col < board[0].size(); col++) {
			cout << "|";
			if (board.at(row).at(col) == nullptr) {
				cout << "   ";
			}
			else {
				currentPiece = board.at(row).at(col);
				/*if (currentPiece->getPieceColor() == 1)
					system("Color 0A");
				else
					system("Color 0C");*/
				cout << currentPiece->getPieceBoardName();
				// system("Color 07");
				//cout << "|";
			}
		}
		cout << "|" << endl;
	}
	cout << "   ---------------------------------" << endl;
}

vector<Piece*> ChessGame::getWhitePieces() {
	return whitePieces;
}

vector<Piece*> ChessGame::getBlackPieces() {
	return blackPieces;
}


int ChessGame::getMoveCount() {
	return moveCounter;
}