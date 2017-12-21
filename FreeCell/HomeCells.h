/*************************************************************
* Author:		Justin.Urbany
* Filename:		HomeCells.h
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef HOMECELLS_H
#define HOMECELLS_H
#include "Stack.h"
#include "Array.h"
#include "card.h"
/************************************************************************
* Class:
*
* Purpose: Hold an Array of Stacks of Cards to put in ascending order
*			Cards of same suit and help gamem play
*
* Manager functions:
* 	HomeCells(): Createss an Array of Stacks of Cards
*	~HomeCells() The Array and all it contains
* Methods:
*		MoveHome(Card, int)
*			Takes in a Card if valid move sets the card. Returns if
*			Was a valid move or not.
*		MoveOutofHome(int column)
*			Takes in a column and gets the top of the stack at that part
*			of the Array.
*		bool CheckAllCells();
*			check if all cells are empty
*		bool CheckSingleCell(int column)
*			checks if a single homecell is empty
*		void PrintHomeCells()
*			prints contents of homecells
*************************************************************************/
class HomeCells
{
public:
	HomeCells();
	~HomeCells();
	bool MoveHome(Card & card, int column);
	Card MoveOutofHome(int column);
	bool CheckAllCells();
	bool CheckSingleCell(int column);
	void PrintHomeCells();

private:
	Array<Stack<Card>> m_Home_Cells;

};


#endif