#pragma once
#include <vector>
#include "moves.hpp"
#include "piece.hpp"

using namespace std;

namespace Pawn {
	//any function signatures that go with the pawn cpp file
	vector<operation::Move*> getPossibleMoves(vector<vector<Piece*>> board, Piece* piece);
}