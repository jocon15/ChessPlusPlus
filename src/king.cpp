#include "piece.hpp"
#include "king.hpp"
#include "moves.hpp"
#include <string.h>
#include <vector> 
#include <memory>

using namespace std; //anytime you're working with vectors

namespace King {

	bool inCheck(vector<vector<Piece*>> board, Piece* piece) {
		int row;
		int col;
		int i;
		Piece* targetPiece = nullptr;
		vector<operation::Move*> targetMoves;
		// loop through every piece in the board
		for (row = 0; row < board.size(); row++) {
			for (col = 0; col < board.at(0).size(); col++) {
				// check that that piece is enemy
				targetPiece = board.at(row).at(col);
				if (targetPiece != nullptr && targetPiece->getPieceColor() != piece->getPieceColor()) {
					// get the enemy piece's moves
					targetMoves = targetPiece->getPossibleMoves(board);
					// loop through the target's moves
					for (i = 0; i < targetMoves.size(); i++) {
						// check for a checkable move
						if (targetMoves.at(i)->destinationRow == piece->getCurrentRow() && targetMoves.at(i)->destinationCol == piece->getCurrentCol()) {
							// the king is in check
							return true;
						}
					}
				}
			}
		}
		// no pieces have checkable moves
		// the king is not in check
		return false;
	}

	vector<vector<Piece*>> movePiece(vector<vector<Piece*>> board, operation::Move* move) {
		//get the piece at the origin
		int i;
		vector<vector<Piece*>> copyBoard = board;
		Piece* originPiece = copyBoard.at(move->originRow).at(move->originCol);
		Piece* targetPiece = copyBoard.at(move->originRow).at(move->originCol);

		//check if there's a piece in the destination
		if (targetPiece == nullptr) {
			//no capture
			//move the piece to the destination
			originPiece->movePiece(move->destinationRow, move->destinationCol);
		}
		else {
			//capture
			//if (targetPiece->getPieceColor() == 0) {
			//	//target is black
			//	for (i = 0; i < blackPieces.size(); i++) {
			//		if (blackPieces.at(i) == targetPiece) {
			//			//remove the balck piece from black's pieces
			//			blackPieces.erase(remove(blackPieces.begin(), blackPieces.end(), targetPiece), blackPieces.end());
			//		}
			//	}
			//}
			//else {
			//	//target is white
			//	for (i = 0; i < whitePieces.size(); i++) {
			//		if (whitePieces.at(i) == targetPiece) {
			//			//remove the white piece from white's pieces
			//			whitePieces.erase(remove(whitePieces.begin(), whitePieces.end(), targetPiece), whitePieces.end());
			//		}
			//	}
			//}
			//move the piece to the desintation
			originPiece->movePiece(move->destinationRow, move->destinationCol);
		}
		//move the piece on the board
		copyBoard.at(move->destinationRow).at(move->destinationCol) = originPiece;
		//set the previous spot to null
		copyBoard.at(move->originRow).at(move->originCol) = nullptr;
		return copyBoard;
	}

	vector<operation::Move*> getPossibleMoves(vector<vector<Piece*>> board, Piece* piece) {
		int FORWARD_1; //use multipliers to get moves in any direction
		if (piece->getPieceColor() == 0) {
			FORWARD_1 = 1;	//black moves pos vector spaces
		}
		else {
			FORWARD_1 = -1;	//white moves neg vector spaces
		}
		int i;
		int targetRow;
		int targetCol;
		Piece* targetPiece = nullptr;
		operation::Move* newMove = new operation::Move;
		//create an empty vector of move pointers
		vector<operation::Move*> possibleMoves;

		// forward
		targetRow = piece->getCurrentRow() + FORWARD_1;
		targetCol = piece->getCurrentCol();
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece == nullptr) {
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
			else if (targetPiece->getPieceColor() != piece->getPieceColor()) {
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		// backward
		targetRow = piece->getCurrentRow() + -FORWARD_1;
		targetCol = piece->getCurrentCol();
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece == nullptr) {
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
			else if (targetPiece->getPieceColor() != piece->getPieceColor()) {
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		// left
		targetRow = piece->getCurrentRow();
		targetCol = piece->getCurrentCol() - 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece == nullptr) {
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
			else if (targetPiece->getPieceColor() != piece->getPieceColor()) {
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		// right
		targetRow = piece->getCurrentRow();
		targetCol = piece->getCurrentCol() + 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece == nullptr) {
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
			else if (targetPiece->getPieceColor() != piece->getPieceColor()) {
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		//forward left
		targetRow = piece->getCurrentRow() + FORWARD_1;
		targetCol = piece->getCurrentCol() - 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece == nullptr) {
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
			else if (targetPiece->getPieceColor() != piece->getPieceColor()) {
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		// forward right
		targetRow = piece->getCurrentRow() + FORWARD_1;
		targetCol = piece->getCurrentCol() + 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece == nullptr) {
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
			else if (targetPiece->getPieceColor() != piece->getPieceColor()) {
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		// backward left
		targetRow = piece->getCurrentRow() + -FORWARD_1;
		targetCol = piece->getCurrentCol() - 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece == nullptr) {
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
			else if (targetPiece->getPieceColor() != piece->getPieceColor()) {
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		//backward right
		targetRow = piece->getCurrentRow() + -FORWARD_1;
		targetCol = piece->getCurrentCol() + 1;
		if (operation::isInBounds(targetRow, targetCol)) {
			targetPiece = board.at(targetRow).at(targetCol);
			if (targetPiece == nullptr) {
				possibleMoves.push_back(operation::createMove(piece->getCurrentRow(), piece->getCurrentCol(), targetRow, targetCol, 0));
			}
			else if (targetPiece->getPieceColor() != piece->getPieceColor()) {
				possibleMoves.push_back(operation::createMove(
					piece->getCurrentRow(),
					piece->getCurrentCol(),
					targetRow,
					targetCol,
					operation::gradeCapture(targetPiece->getPieceType())));
			}
		}

		return possibleMoves;
	}

	vector<operation::Move*> getPossibleMoves1(vector<vector<Piece*>> board, Piece* piece) {
		// here the king is in check
		// we need to find a move that gets us out of check/blocks
		int i;
		int row;
		int col;
		int row1;
		int col1;
		int targetRow;
		int targetCol;
		bool kingInCheck;
		vector<vector<Piece*>> copyBoard;
		Piece* targetPiece;
		vector<operation::Move*> moves;
		vector<operation::Move*> targetMoves;
		vector<operation::Move*> possibleMoves;
		// loop through all the pieces in the board
		for (row = 0; row < board.size(); row++) {
			for (col = 0; col < board.at(0).size(); col++) {
				targetPiece = board.at(row).at(col);
				if (targetPiece != nullptr) {
					// that are teammates
					if (targetPiece->getPieceColor() == piece->getPieceColor()) {
						// that are not the king
						if (targetPiece->getPieceType() != 1) {
							// get possible moves for teammate piece
							moves = targetPiece->getPossibleMoves(board);
							// loop through possible moves
							for (i = 0; i < moves.size(); i++) {
								// get the hypothetical board for that move
								copyBoard = movePiece(board, moves.at(i));
								// loop through the hypothetical board
								kingInCheck = false;
								for (row1 = 0; row1 < copyBoard.size(); row1++) {
									for (col1 = 0; col1 < copyBoard[0].size(); col1++) {
										targetPiece = board.at(row1).at(col1);
										// that are enemy pieces
										if (targetPiece != nullptr && targetPiece->getPieceColor() != piece->getPieceColor()) {
											// get possible moves of the enemy piece
											targetMoves = targetPiece->getPossibleMoves(board);
											// loop through the target's moves
											for (i = 0; i < targetMoves.size(); i++) {
												// check for a checkable move
												if (targetMoves.at(i)->destinationRow == piece->getCurrentRow() && targetMoves.at(i)->destinationCol == piece->getCurrentCol()) {
													// that piece has our king is in check
													kingInCheck = true;
												}
											}
										}
									}
								}
								targetRow = moves.at(i)->destinationRow;
								targetCol = moves.at(i)->destinationCol;
								if (kingInCheck) {
									//bad move
									possibleMoves.push_back(operation::createMove(targetPiece->getCurrentRow(), targetPiece->getCurrentCol(), targetRow, targetCol, 0));
								}
								else{
									//good move
									possibleMoves.push_back(operation::createMove(targetPiece->getCurrentRow(), targetPiece->getCurrentCol(), targetRow, targetCol, 900));
								}
							}
						}
					}
				}
			}
		}
		// now we check if the king can move
		// get the kings possible moves
		vector<operation::Move*> kingsMoves = piece->getPossibleMoves(board);
		// loop through the kings moves
		for (i = 0; i < kingsMoves.size(); i++) {
			// get the hypothetical board
			copyBoard = movePiece(board, moves.at(i));
			// loop through the hypothetical board
			kingInCheck = false;
			for (row1 = 0; row1 < copyBoard.size(); row1++) {
				for (col1 = 0; col1 < copyBoard[0].size(); col1++) {
					targetPiece = board.at(row1).at(col1);
					// that are enemy pieces
					if (targetPiece != nullptr && targetPiece->getPieceColor() != piece->getPieceColor()) {
						// get possible moves of the enemy piece
						targetMoves = targetPiece->getPossibleMoves(board);
						// loop through the target's moves
						for (i = 0; i < targetMoves.size(); i++) {
							// check for a checkable move
							if (targetMoves.at(i)->destinationRow == piece->getCurrentRow() && targetMoves.at(i)->destinationCol == piece->getCurrentCol()) {
								// that piece has our king is in check
								kingInCheck = true;
							}
						}
					}
				}
			}
			if (kingInCheck) {
				//bad move
				possibleMoves.push_back(operation::createMove(
					kingsMoves.at(i)->originRow, 
					kingsMoves.at(i)->originCol, 
					kingsMoves.at(i)->destinationRow, 
					kingsMoves.at(i)->destinationCol, 
					0));
			}
			else {
				//good move
				possibleMoves.push_back(operation::createMove(
					kingsMoves.at(i)->originRow,
					kingsMoves.at(i)->originCol,
					kingsMoves.at(i)->destinationRow,
					kingsMoves.at(i)->destinationCol,
					900));
			}
		}

		return possibleMoves;
	}	
}