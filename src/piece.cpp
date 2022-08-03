#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "piece.hpp"
#include "chess_game.hpp"
#include "moves.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

using namespace std;

Piece::Piece(int type, int color, int row, int col, string name, int number) {
	if (type <= -1 || type > 7) {
		cout << "ivalid piece number" << endl;
		return;
	}
	//good piece
	this->type = type;
	this->id = rand() % 1000 + 1;	//random id
	this->color = color;			//0 black 1 white
	this->currentRow = row;			//the current coordinates of the piece
	this->currentCol = col;
	this->previousRow = row;
	this->previousCol = col;
	this->name = name;
	this->number = number;
	this->hasBeenMoved = false;		//the piece has not been moved yet

	//1 king
	//2 queen
	//3 bishop
	//4 knight
	//5 rook
	//6 pawn
}

int Piece::getPieceId() {
	return id;
}

int Piece::getPieceType() {
	return type;
}

int Piece::getPieceColor() {
	return color;
}

string Piece::getName() {
	return name;
}

string Piece::getPieceBoardName() {
	switch (this->type) {
	case 1:
		//FIXME add implementation for king
		if (color == 1)
			return "WK ";
		else
			return "BK ";
		break;
	case 2:
		//FIXME add implementation for queena
		if (color == 1)
			return "WQ ";
		else
			return "BQ ";
		break;
	case 3:
		//FIXME add implementation for bishop
		if (color == 1)
			return "WB" + to_string(number);
		else
			return "BB" + to_string(number);
		break;
	case 4:
		//FIXME add implementation for knight
		if (color == 1)
			return "WK" + to_string(number);
		else
			return "BK" + to_string(number);
		break;
	case 5:
		//FIXME add implementation for rook
		if (color == 1)
			return "WR" + to_string(number);
		else
			return "BR" + to_string(number);
		break;
	default:
		if (color == 1)
			return "WP" + to_string(number);
		else
			return "BP" + to_string(number);
		break;
	}
}

int Piece::getCurrentRow() {
	return currentRow;
}

int Piece::getCurrentCol() {
	return currentCol;
}

int Piece::getPreviousRow() {
	return previousRow;
}

int Piece::getPreviousCol() {
	return previousCol;
}

bool Piece::getHasBeenMoved() {
	return hasBeenMoved;
}

void Piece::setPieceType(int type) {
	this->type = type;
}

void Piece::setHasBeenMoved() {
	this->hasBeenMoved = true;
}

void Piece::movePiece(int row, int col) {
	//store the old location
	previousRow = currentRow;
	previousCol = currentCol;
	//update the new location
	currentRow = row;
	currentCol = col;
}

bool Piece::inCheck(vector<vector<Piece*>> board) {
	if (this->type != 1) {
		throw exception("called inCheck() on a piece that is not the king");
	}
	return King::inCheck(board, this);
}

vector<operation::Move*> Piece::getPossibleMoves(vector<vector<Piece*>> board, bool inCheck) {
	//here we sort the piece by it's type then call the getBest move function 
	//in each piece namespace
	switch (this->type) {
	case 1:
		if (inCheck) {
			/*cout << "King special started" << endl;*/
			return King::getPossibleMoves1(board, this);
		}
		else {
			/*cout << "King normal started" << endl;*/
			return King::getPossibleMoves(board, this);
		}
		break;
	case 2:
		/*cout << "Queen started" << endl;*/
		return Queen::getPossibleMoves(board, this);
		break;
	case 3:
		/*cout << "Bishop started" << endl;*/
		return Bishop::getPossibleMoves(board, this);
		break;
	case 4:
		/*cout << "Knight started" << endl; */
		return Knight::getPossibleMoves(board, this);
		break;
	case 5:
		/*cout << "Rook started" << endl;*/
		return Rook::getPossibleMoves(board, this);
		break;
	default:
		/*cout << "Pawn started" << endl;*/
		return Pawn::getPossibleMoves(board, this);	//pass the current board and the current piece
		break;
	}
}