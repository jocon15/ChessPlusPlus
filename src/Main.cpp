#include <iostream>
#include <vector>
#include <memory>
#include "chess_game.hpp"
#include "black.hpp"
#include "white.hpp"
#include "piece.hpp"	//this is temporary for board vector debug

using namespace std;

int main() {
	ChessGame gameBoard = ChessGame();	//create the chess game
	ChessGame* game = &gameBoard;		//create a pointer to the game class

	// non-pointer
	//gameBoard.resetChessGame();			//reset the board
	//gameBoard.printBoard();				//print out the board
	
	// pointer
	game->resetChessGame();
	//game->printBoard();

	//everything should be done through the gameBoard class
	// so that we can encapsulate and ensure the correct processes get followed
	// - making moves
	// - geting a vector of your pieces

	//vector<vector<Piece*>> board = gameBoard.getBoard();
	// vector<Piece*> whitePieces = gameBoard.getWhitePieces();
	// vector<Piece*> blackPieces = gameBoard.getBlackPieces();

	// this is the new way of calling the get possible moves
	// calling it through the whiteTeam namespace makes it so that
	// that fucntion can handle the king getting selected first
	//vector<operation::Move*> moves = whiteTeam::getPossibleMoves(game);


	/*vector<operation::Move*> moves = board.at(7).at(6)->getPossibleMoves(board);*/

	/*cout << "\nPiece: " << board.at(7).at(6)->getName() << endl;*/
	/*cout << "Total moves: " << moves.size() << "\n" << endl;
	for (int i = 0; i < moves.size(); i++) {
		cout << "Origin Row: " << moves.at(i)->originRow << endl;
		cout << "Origin Col: " << moves.at(i)->originCol << endl;
		cout << "Destination Row: " << moves.at(i)->destinationRow << endl;
		cout << "Destination Col: " << moves.at(i)->destinationCol << endl;
		cout << endl;
	}*/

	vector<operation::Move*> whiteMoves;
	vector<operation::Move*> blackMoves;
	operation::Move* bestMove;
	
	string input;
	bool whitesTurn = true;
	while (true) {
		game->printBoard();
		cout << "Execute next move?";
		cin >> input;
		if (whitesTurn) {
			whiteMoves = whiteTeam::getPossibleMoves(game);
			if (whiteMoves.size() == 0) {
				cout << "black is out of moves" << endl;
			}
			bestMove = whiteTeam::getBestMove(whiteMoves);
		}
		else {
			blackMoves = blackTeam::getPossibleMoves(game);
			if (blackMoves.size() == 0) {
				cout << "black is out of moves" << endl;
			}
			bestMove = blackTeam::getBestMove(blackMoves);
		}
		cout << "Executed move: " << endl;
		cout << "Origin Row: " << bestMove->originRow << endl;
		cout << "Origin Col: " << bestMove->originCol << endl;
		cout << "Destination Row: " << bestMove->destinationRow << endl;
		cout << "Destination Col: " << bestMove->destinationCol << endl;
		cout << endl;
		game->movePiece(bestMove);
		whitesTurn = !whitesTurn;
	}


	/*gameBoard.movePiece(moves.at(1));
	gameBoard.printBoard();*/

	//-----------delteing stuff ------------------------------------
	for (int i = 0; i < whiteMoves.size(); i++) {
		delete whiteMoves.at(i);
	}
	for (int i = 0; i < blackMoves.size(); i++) {
		delete blackMoves.at(i);
	}
	//delete game;
	gameBoard.~ChessGame();				//you technically don't need to do this but just in case
	return 0;
}