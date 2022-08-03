#include "moves.hpp"

namespace operation {
	//any function implementations go here (not structs)

	bool isInBounds(int row, int col) {
		// does the checking for inbounds
		if (0 <= row && row <= 7) {
			if (0 <= col && col <= 7)
				return true;
			else 
				return false;
		}
		return false;
	}

	Move* createMove(int originRow, int originCol, int destinationRow, int destinationCol, int score) {
		Move* newMove = new Move;
		newMove->originRow = originRow;
		newMove->originCol = originCol;
		newMove->destinationRow = destinationRow;
		newMove->destinationCol = destinationCol;
		newMove->score = score;
		return newMove;
	}

	int gradeCapture(int pieceType) {
		switch (pieceType) {
		case 1:
			// checkmate
			return 900;
			break;
		case 2:
			// queen capture
			return 90;
			break;
		case 3:
			// bishop capture
			return 30;
			break;
		case 4:
			// knight capture
			return 30;
			break;
		case 5:
			// rook capture
			return 50;
			break;
		default:
			// pawn capture
			return 15;
			break;
		}
	}

}