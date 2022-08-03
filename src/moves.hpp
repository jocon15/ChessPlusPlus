#pragma once

namespace operation {
	struct Move {
		int originRow;
		int originCol;
		int destinationRow;
		int destinationCol;
		int score;
	};

	bool isInBounds(int row, int col);
	Move* createMove(int originRow, int originCol, int destinationRow, int destinationCol, int score);
	int gradeCapture(int peiceType);
}