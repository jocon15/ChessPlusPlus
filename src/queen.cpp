#include "queen.hpp"
#include "piece.hpp"
#include "moves.hpp"
#include <vector> 
#include <memory>

using namespace std;

namespace Queen {
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
		int targetRow;
		int targetCol;
		Piece* targetPiece = nullptr;
		operation::Move* newMove = new operation::Move;
		//create an empty vector of move pointers
		vector<operation::Move*> possibleMoves;

		//for loop going forward
		targetCol = piece->getCurrentCol();
		for (targetRow = piece->getCurrentRow() + FORWARD_1; targetRow <= GOAL_LINE; targetRow += FORWARD_1) {
			if (operation::isInBounds(targetRow, targetCol)) {
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece == nullptr) {
					//no piece in that spot
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
				else if (piece->getPieceColor() == targetPiece->getPieceColor()) {
					//blocked by teammate
					break;
				}
				else {
					//enemy piece in this direction
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
					break;
				}
			}
			else {
				// out of bounds, exit loop
				break;
			}
		}

		//for loop going backward
		targetCol = piece->getCurrentCol();
		for (targetRow = piece->getCurrentRow() - FORWARD_1; targetRow >= HOME_GOAL_LINE; targetRow -= FORWARD_1) {
			if (operation::isInBounds(targetRow, targetCol)) {
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece == nullptr) {
					//no piece in that spot
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
				else if (piece->getPieceColor() == targetPiece->getPieceColor()) {
					//blocked by teammate
					break;
				}
				else {
					//enemy piece in this direction
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
					break;
				}
			}
			else {
				// out of bounds, exit loop
				break;
			}
		}

		//for loop going left
		targetRow = piece->getCurrentRow();
		for (targetCol = piece->getCurrentCol() - FORWARD_1; targetCol >= SIDELINE_L; targetCol -= FORWARD_1) {
			if (operation::isInBounds(targetRow, targetCol)) {
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece == nullptr) {
					//no piece in that spot
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
				else if (piece->getPieceColor() == targetPiece->getPieceColor()) {
					//blocked by teammate
					break;
				}
				else {
					//enemy piece in this direction
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
					break;
				}
			}
			else {
				// out of bounds, exit loop
				break;
			}
		}

		//for loop going right
		targetRow = piece->getCurrentRow();
		for (targetCol = piece->getCurrentCol() + FORWARD_1; targetCol <= SIDELINE_R; targetCol += FORWARD_1) {
			if (operation::isInBounds(targetRow, targetCol)) {
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece == nullptr) {
					//no piece in that spot
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
				else if (piece->getPieceColor() == targetPiece->getPieceColor()) {
					//blocked by teammate
					break;
				}
				else {
					//enemy piece in this direction
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
					break;
				}
			}
			else {
				// out of bounds, exit loop
				break;
			}
		}

		//diagnoal forward left
		targetCol = piece->getCurrentCol() - FORWARD_1;
		for (targetRow = piece->getCurrentRow() + FORWARD_1; targetRow <= GOAL_LINE; targetRow += FORWARD_1) {
			if (operation::isInBounds(targetRow, targetCol)) {
				//target space is inbounds
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece == nullptr) {
					//empty space
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
				else if (piece->getPieceColor() != targetPiece->getPieceColor()) {
					//enemy piece
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
				else {
					//teammate (blocked)
					break;
				}
			}
			else {
				// out of bounds, exit loop
				break;
			}
			targetCol -= FORWARD_1;
		}

		//diagonal forward right
		targetCol = piece->getCurrentCol() + FORWARD_1;
		for (targetRow = piece->getCurrentRow() + FORWARD_1; targetRow <= GOAL_LINE; targetRow += FORWARD_1) {
			if (operation::isInBounds(targetRow, targetCol)) {
				//target space is in bounds
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece == nullptr) {
					//empty space
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
				else if (piece->getPieceColor() != targetPiece->getPieceColor()) {
					//enemy piece
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
				else {
					//teammate (blocked)
					break;
				}
			}
			else {
				// out of bounds, exit loop
				break;
			}
			targetCol += FORWARD_1;
		}

		//diagonal backward left
		targetCol = piece->getCurrentCol() - FORWARD_1;
		for (targetRow = piece->getCurrentRow() - FORWARD_1; targetRow >= HOME_GOAL_LINE; targetRow -= FORWARD_1) {
			if (operation::isInBounds(targetRow, targetCol)) {
				//target space is inbounds
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece == nullptr) {
					//empty space
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
				else if (piece->getPieceColor() != targetPiece->getPieceColor()) {
					//enemy piece
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
				else {
					//teammate (blocked)
					break;
				}
			}
			else {
				// out of bounds, exit loop
				break;
			}
			targetCol -= FORWARD_1;
		}

		//diagonal backward right
		targetCol = piece->getCurrentCol() + FORWARD_1;
		for (targetRow = piece->getCurrentRow() - FORWARD_1; targetRow >= HOME_GOAL_LINE; targetRow -= FORWARD_1) {
			if (operation::isInBounds(targetRow, targetCol)) {
				//target space is in bounds
				targetPiece = board.at(targetRow).at(targetCol);
				if (targetPiece == nullptr) {
					//empty space
					possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
				}
				else if (piece->getPieceColor() != targetPiece->getPieceColor()) {
					//enemy piece
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
				else {
					//teammate (blocked)
					break;
				}
			}
			else {
				// out of bounds, exit loop
				break;
			}
			targetCol += FORWARD_1;
		}
		return possibleMoves;
		////find the best move
		//operation::Move* bestMove = possibleMoves.at(0);
		//for (i = 1; i < possibleMoves.size(); i++) {
		//	if (possibleMoves.at(i)->score > bestMove->score) {
		//		bestMove = possibleMoves.at(i);
		//		//FIXME: What happens if two moves have the same score??? for now, we pick the first one
		//	}
		//}
		////free up the memory
		//for (i = 0; i < possibleMoves.size(); i++) {
		//	if (possibleMoves.at(i) != bestMove)
		//		delete possibleMoves.at(i);
		//}
		//delete targetPiece;
		////returns a pointer to the operation::Move struct of the best move
		//return bestMove;
	}
}