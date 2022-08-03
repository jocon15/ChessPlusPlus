#include "rook.hpp"
#include "piece.hpp"
#include "moves.hpp"
#include <vector> 
#include <memory>

using namespace std; //anytime you're working with vectors


namespace Rook {
	vector<operation::Move*> getPossibleMoves(vector<vector<Piece*>> board, Piece* piece) {

		//The direction of the piece moevemnts isn't going to matter because we have
		//the rook moving in both horiz and both vert directions so all locations
		//will be checked, we don't need to have seperate bounds
		//rook movement is symmetrical so no 
		int FORWARD_1 = 1; //use multipliers to get moves in any direction
		int GOAL_LINE = 7;
		int HOME_GOAL_LINE = 0;
		int SIDELINE_L = 0;
		int SIDELINE_R = 7;
		int i;
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