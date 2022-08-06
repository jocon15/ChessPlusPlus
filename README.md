# ChessPlusPlus
Chess in C++

## Introduction

ChessPlusPlus is a side project inspired by The Queen's Gambit on Netflix. I saw the game of chess as an opportunity to perhaps apply a binary search tree to analyze the tree of moves at any given board arrangement. In addition, I wanted to gain a better understanding of C++ topics like raw memory access, namespaces, etc. The best way to learn is to do so I did. I hope this project encourages you to actually go out and try something new that you learned.

## In Development
Currently, I'm working on ironing out the bugs in the piece movement. The main method is setup to run a simple simulated chess game move by move. Most of the pieces are working as expected and the simulation will go pretty far until it crashes.

The good news is that the move grading system, capture system, and inCheck systems are working. You can see them in action during the simulation.

## Progress
So far, I have created the game of chess in a way that was intuitive to me but also in ways that favor a specific area that I wanted to gain experience with.

Once the pieces will all move as expected, I can then try to enhance the move selection.

A milestone that preceds the one in the following paragraph is analyzing if the king is in check. You do that by looping through your opponent's possible moves and see if any of them would capture the king. This milestone is completed which opens the door to many other possibilities.

One of the milestones is to be able to simulate how a move is going to play out before actually selecting it. From my research and math alone, there are too many possibilities to simulate than there is time and resources. But simulating a few moves ahead would be cool.

## The Board and Pieces
When I was first conceptualizing this project, I knew I was going to have to create a board of pieces. I decided that I wanted the board to be a 2d vector so that I could easily iterate spaces with for loops. But vectors of what data type?

The traditional OOP approach would be to create a Piece class with subclasses for each type of piece, King, Rook, Pawn, etc... I knew that the differentiating factor between the types of pieces was going to be how each type can move. You could construct the pieces this way but then you can't use vectors because the data needs to all be the same type. Plus, I wanted to try namespaces out. So instead, I created a piece class with a switch case that calls the correct functionality for the given piece type. Essentially, a namespace of functions for each piece type.

Going back to the board, the type is ```vector<vector<Piece*>>```. The board is a 2d vector of Piece object pointers.

