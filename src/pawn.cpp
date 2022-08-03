#include "pawn.hpp"
#include "piece.hpp"
#include "moves.hpp"
#include <vector> 
#include <memory>

using namespace std; //anytime you're working with vectors

namespace Pawn {

	vector<operation::Move*> getPossibleMoves(vector<vector<Piece*>> board, Piece* piece) {
		int FORWARD_1; //use multipliers to get moves in any direction
		int GOAL_LINE;
		int HOME_GOAL_LINE;
		int SIDELINE_L = 0;
		int SIDELINE_R = 7;
		if (piece->getPieceColor() == 0) {
			FORWARD_1 = 1;	//black moves pos vector spaces
			GOAL_LINE = 7;
			HOME_GOAL_LINE = 0;
		}
		else {
			FORWARD_1 = -1;	//white moves neg vector spaces
			GOAL_LINE = 0;
			HOME_GOAL_LINE = 7;
		}
		int i;
		int targetRow;
		int targetCol;
		Piece* targetPiece = nullptr;
		operation::Move* newMove = new operation::Move;
		//create an empty vector of move pointers
		vector<operation::Move*> possibleMoves;

		//check pawn move type 1 - diagonal capture
		//diagonal capture left
		targetRow = piece->getCurrentRow() + FORWARD_1;
		targetCol = piece->getCurrentCol() - 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			//diag left is in bounds
			if (targetPiece != nullptr && targetPiece->getPieceColor() != piece->getPieceColor()) {
				//there is an enemy peice at the target
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}
		//diagonal capture right
		targetRow = piece->getCurrentRow() + FORWARD_1;
		targetCol = piece->getCurrentCol() + 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			//diag rigt is in bounds
			if (targetPiece != nullptr && targetPiece->getPieceColor() != piece->getPieceColor()) {
				//there is an enemy piece there
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		// pawn becomes queen 
		targetRow = piece->getCurrentRow() + FORWARD_1;
		targetCol = piece->getCurrentCol();
		if (targetRow == GOAL_LINE) {
			targetPiece = board.at(targetRow).at(targetCol);
			//if the target is the goal line
			if (targetPiece == nullptr) {
				//the pawn can move straight
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(),	piece->getCurrentCol(), targetRow, targetCol, 90));
			}
		}

		// pawn moves forward 1
		if (piece->getHasBeenMoved()) {
			//can only move 1 space
			targetRow = piece->getCurrentRow() + FORWARD_1;
			targetCol = piece->getCurrentCol();
			if (operation::isInBounds(targetRow, targetCol)) {	//this is move forward 1 that is not a pawn->queen to > goal line
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece != nullptr) {
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
			}
		}
		else {
			//can move 1 or 2 spaces
			targetRow = piece->getCurrentRow() + (2 * FORWARD_1);
			targetCol = piece->getCurrentCol();
			//NO NEED TO CHECK FOR BOUNDS BECAUSE THE PIECE HASN'T BEEN MOVED YET
			if (operation::isInBounds(targetRow, targetCol)) {
				targetPiece = board.at(targetRow).at(targetCol);
				int targetRow1 = piece->getCurrentRow() + FORWARD_1;
				if (operation::isInBounds(targetRow1, targetCol)) {
					Piece* targetPiece2 = board.at(targetRow1).at(targetCol);
					if (targetPiece == nullptr && targetPiece2 == nullptr) {
						//can move 2 forward
						possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol,5));
						//can also move 1 forward 
						targetRow = piece->getCurrentRow() + FORWARD_1;
						possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
					}
					else if (targetPiece != nullptr && targetPiece2 == nullptr) {
						//can move 1 forward (2 blocked)
						possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
					}
				}
			}
		}

		//check pawn move type 4 en passant
		//en passant left
		targetRow = piece->getCurrentRow();
		targetCol = piece->getCurrentCol() - 1;
		int moveRow = piece->getCurrentRow() + FORWARD_1;
		int moveCol = piece->getCurrentCol() - 1;
		if (operation::isInBounds(targetRow, targetCol) && operation::isInBounds(moveRow, moveCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			Piece* movePiece = board.at(moveRow).at(moveCol);
			if (targetPiece != nullptr && movePiece == nullptr) {
				if (piece->getPieceColor() != targetPiece->getPieceColor()) {
					//the target piece is an enemy piece
					if (targetPiece->getPieceType() == 6) {
						//the target piece is a pawn
						if (targetPiece->getPreviousRow() == targetRow - (2 * -FORWARD_1)) {
							//the target piece has previously moved forward 2
							possibleMoves.push_back(operation::createMove(
								piece->getCurrentRow(),
								piece->getCurrentCol(),
								moveRow,
								moveCol,
								operation::gradeCapture(targetPiece->getPieceType())));
						}
					}
				}
			}
		}

		//en passant right
		targetRow = piece->getCurrentRow();
		targetCol = piece->getCurrentCol() + 1;
		moveRow = piece->getCurrentRow() + FORWARD_1;
		moveCol = piece->getCurrentCol() + 1;
		if (operation::isInBounds(targetRow, targetCol) && operation::isInBounds(moveRow, moveCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			Piece* movePiece = board.at(moveRow).at(moveCol);
			if (targetPiece != nullptr && movePiece == nullptr) {
				if (piece->getPieceColor() != targetPiece->getPieceColor()) {
					//the target piece is an enemy piece
					if (targetPiece->getPieceType() == 6) {
						//the target piece is a pawn
						if (targetPiece->getPreviousRow() == targetRow - (2 * -FORWARD_1)) {
							//the target piece has previously moved forward 2
							possibleMoves.push_back(operation::createMove(
								piece->getCurrentRow(),
								piece->getCurrentCol(),
								moveRow,
								moveCol,
								operation::gradeCapture(targetPiece->getPieceType())));
						}
					}
				}
			}
		}
		return possibleMoves;
	}
}