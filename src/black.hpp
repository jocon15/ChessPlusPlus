#pragma once
#include <vector>
#include "chess_game.hpp"
#include "moves.hpp"
#include "piece.hpp"

using namespace std;

namespace blackTeam {
	vector<operation::Move*> getPossibleMoves(ChessGame* game);
	operation::Move* getBestMove(vector<operation::Move*> moves);
}