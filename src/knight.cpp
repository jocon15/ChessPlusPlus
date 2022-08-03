#include <vector>
#include "knight.hpp"
#include "moves.hpp"
#include "piece.hpp"

using namespace std;


namespace Knight {
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


		//top left
		targetRow = piece->getCurrentRow() + (2 * FORWARD_1);
		targetCol = piece->getCurrentCol() - 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece != nullptr) {
				//piece at target
				if (targetPiece->getPieceColor() != piece->getPieceColor()) {
					//enemy piece at target
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
			}
			else {
				//empty space
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
		}

		targetRow = piece->getCurrentRow() + FORWARD_1;
		targetCol = piece->getCurrentCol() - 2;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece != nullptr) {
				//piece at target
				if (targetPiece->getPieceColor() != piece->getPieceColor()) {
					//enemy piece at target
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
			}
			else {
				//empty space
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
		}

		//top right
		targetRow = piece->getCurrentRow() + (2 * FORWARD_1);
		targetCol = piece->getCurrentCol() + 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece != nullptr) {
				//piece at target
				if (targetPiece->getPieceColor() != piece->getPieceColor()) {
					//enemy piece at target
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
			}
			else {
				//empty space
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
		}

		targetRow = piece->getCurrentRow() + FORWARD_1;
		targetCol = piece->getCurrentCol() + 2;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece != nullptr) {
				//piece at target
				if (targetPiece->getPieceColor() != piece->getPieceColor()) {
					//enemy piece at target
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
			}
			else {
				//empty space
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
		}

		//down left
		targetRow = piece->getCurrentRow() + (2 * -FORWARD_1);
		targetCol = piece->getCurrentCol() - 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece != nullptr) {
				//piece at target
				if (targetPiece->getPieceColor() != piece->getPieceColor()) {
					//enemy piece at target
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
			}
			else {
				//empty space
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
		}

		targetRow = piece->getCurrentRow() + -FORWARD_1;
		targetCol = piece->getCurrentCol() - 2;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece != nullptr) {
				//piece at target
				if (targetPiece->getPieceColor() != piece->getPieceColor()) {
					//enemy piece at target
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
			}
			else {
				//empty space
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
		}

		//down right
		targetRow = piece->getCurrentRow() + (2 * -FORWARD_1);
		targetCol = piece->getCurrentCol() + 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece != nullptr) {
				//piece at target
				if (targetPiece->getPieceColor() != piece->getPieceColor()) {
					//enemy piece at target
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
			}
			else {
				//empty space
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
		}

		targetRow = piece->getCurrentRow() + -FORWARD_1;
		targetCol = piece->getCurrentCol() + 2;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece != nullptr) {
				//piece at target
				if (targetPiece->getPieceColor() != piece->getPieceColor()) {
					//enemy piece at target
					possibleMoves.push_back(operation::createMove(
						piece->getCurrentRow(),
						piece->getCurrentCol(),
						targetRow,
						targetCol,
						operation::gradeCapture(targetPiece->getPieceType())));
				}
			}
			else {
				//empty space
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
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