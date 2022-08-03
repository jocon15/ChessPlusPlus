#include <vector>
#include "chess_game.hpp"
#include "moves.hpp"
#include "piece.hpp"
#include "king.hpp"

using namespace std;

namespace blackTeam {
	vector<operation::Move*> getPossibleMoves(ChessGame* game) {
		//this is what you call from the main method
		// first, we get all of our pieces from the board
		// find the king
		int i;
		int j;
		int k;
		bool kingInCheck;
		Piece* currentPiece;
		vector<Piece*> pieces;
		vector<operation::Move*> pieceMoves;
		vector<operation::Move*> possibleMoves;


		pieces = game->getBlackPieces();


		for (i = 0; i < pieces.size(); i++) {
			currentPiece = pieces.at(i);
			if (currentPiece->getPieceType() == 1) {
				//we have found the king

				// see if king in check
				kingInCheck = King::inCheck(game->getBoard(), currentPiece);

				if (kingInCheck) {
					// call king in check possible moves (return all possible moves with adjusted score for blocking)
					return currentPiece->getPossibleMoves(game->getBoard(), kingInCheck);
				}
				else {
					// call king not in check 
					// call rest of the pieces possible moves
					for (j = 0; j < pieces.size(); j++) {
						pieceMoves = pieces.at(j)->getPossibleMoves(game->getBoard(), kingInCheck);
						// loop through that peices moves
						for (k = 0; k < pieceMoves.size(); k++) {
							// add the move to the possible moves
							possibleMoves.push_back(pieceMoves.at(k));
						}
					}
					return possibleMoves;
				}
			}
		}
	}

	operation::Move* getBestMove(vector<operation::Move*> moves) {
		operation::Move* bestMove = moves.at(0);
		for (int i = 1; i < moves.size(); i++) {
			if (moves.at(i)->score > bestMove->score) {
				bestMove = moves.at(i);
			}
		}
		return bestMove;
	}
}