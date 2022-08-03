#pragma once
#include <vector>
#include "moves.hpp"
#include "piece.hpp"

using namespace std;

namespace Rook {
	vector<operation::Move*> getPossibleMoves(vector<vector<Piece*>> board, Piece* piece);
}