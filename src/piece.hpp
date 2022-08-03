#pragma once
#include <vector>
#include <string>
#include "moves.hpp" 

using namespace std;

class Piece {
private:
	int id;
	int type;
	int color;
	int currentRow;
	int currentCol;
	int previousRow;
	int previousCol;
	bool hasBeenMoved;
	string name;
	int number;

public:
	//constructors
	Piece(int type, int color, int row, int col, string name, int number);
	//accessors
	int getPieceId();
	int getPieceType();
	int getPieceColor();
	string getName();
	string getPieceBoardName();
	int getCurrentRow();
	int getCurrentCol();
	int getPreviousRow();
	int getPreviousCol();
	bool getHasBeenMoved();
	//mutators
	void setPieceType(int type);
	void setHasBeenMoved();
	//auxillary
	void movePiece(int row, int col);
	bool inCheck(vector<vector<Piece*>> board);
	vector<operation::Move*> getPossibleMoves(vector<vector<Piece*>> board, bool inCheck = false);
};