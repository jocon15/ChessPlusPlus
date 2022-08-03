#pragma once
#include "piece.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include <memory>
#include <vector>

using namespace std;

class ChessGame {
private:
	vector<vector<Piece*>> board;
	vector<Piece*> allPieces;
	vector<Piece*> whitePieces;
	vector<Piece*> blackPieces;

	Piece* whitePawn1;
	Piece* whitePawn2;
	Piece* whitePawn3;
	Piece* whitePawn4;
	Piece* whitePawn5;
	Piece* whitePawn6;
	Piece* whitePawn7;
	Piece* whitePawn8;
	Piece* whiteRook1;
	Piece* whiteRook2;
	Piece* whiteKnight1;
	Piece* whiteKnight2;
	Piece* whiteBishop1;
	Piece* whiteBishop2;
	Piece* whiteQueen;
	Piece* whiteKing;

	Piece* blackPawn1;
	Piece* blackPawn2;
	Piece* blackPawn3;
	Piece* blackPawn4;
	Piece* blackPawn5;
	Piece* blackPawn6;
	Piece* blackPawn7;
	Piece* blackPawn8;
	Piece* blackRook1;
	Piece* blackRook2;
	Piece* blackKnight1;
	Piece* blackKnight2;
	Piece* blackBishop1;
	Piece* blackBishop2;
	Piece* blackQueen;
	Piece* blackKing;

	int moveCounter;
	

public:
	ChessGame(); //singleton constructor eventually
	~ChessGame(); //destructor
	vector<Piece*> getWhitePieces();
	vector<Piece*> getBlackPieces();
	void createChessGame();
	void buildPieces();
	void resetChessGame();
	vector<vector<Piece*>> getBoard();
	void movePiece(operation::Move* move);
	void printBoard();
	int getMoveCount();
	//addPiece();
};