/*************************************************************
* Author:		Justin.Urbany
* Filename:		Board.h
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "OpenCells.h"
#include "HomeCells.h"
#include "PlayCells.h"
#include "deck.h"
/************************************************************************
* Class: Board
*
* Purpose: Creates a 1 dimenional dynamic array of any type
*
* Manager functions:
* 	Board() Creates a new board calls All other class ctors
*	~Board() Deletes a Board and everything it contains
* Methods:
*	Void Deal:
*		populates the PlayCells with the deck of cards;
*	Playgame();
*		loops until game over printing out board and game options
*	PrintBoard():
*		Displays the HomeCell OpenCell and PlayCell objects
*	CheckWin():
*		Checks to see if player won the game
*************************************************************************/
class Board
{
public:
	Board();
	~Board();
	void Deal();
	void PlayGame();
	void PrintBoard();
	bool CheckWin();
private:
	HomeCells m_home_cells;
	OpenCells m_open_cells;
	PlayCells m_play_cells;
	Deck m_deck;
};

#endif BOARD_H