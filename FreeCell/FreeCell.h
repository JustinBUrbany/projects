/*************************************************************
* Author:		Justin.Urbany
* Filename:		FreeCell.h
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef FREECELL_H
#define FREECELL_H
#include "Board.h"
/************************************************************************
* Class: FreeCell
*
* Purpose: Hold a Board pointer so can Delete Board and create a new Board
*		For every consecuitive game
*
* Manager functions:
* 	FreeCell(): Creates a newBoard and Calls Deal
*	~FreeCell() Deletes a Board and everything it contains
* Methods:
*	Void Deal:
*		Calls Board.Deal();
*		Calls Playagain();
*	PlayAgain:
*		Asks user if they want to play again if yes deletes current Board
*		then makes another Board
*************************************************************************/
class FreeCell
{
public:
	FreeCell();
	~FreeCell();
	void Deal();
	void PlayAgain();
private:
	Board * m_board;

};


#endif // !FREECELL_H