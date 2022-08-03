#pragma once
#include <vector>
#include "piece.hpp"
#include "moves.hpp"

using namespace std;

namespace King {
	//any function signatures that go with the pawn cpp file

	bool inCheck(vector<vector<Piece*>> board, Piece* piece);
	vector<vector<Piece*>> movePiece(vector<vector<Piece*>> board, operation::Move* move);
	vector<operation::Move*> getPossibleMoves(vector<vector<Piece*>> board, Piece* piece);
	vector<operation::Move*> getPossibleMoves1(vector<vector<Piece*>> board, Piece* piece);
}