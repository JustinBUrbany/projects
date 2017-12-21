/*************************************************************
* Author:		Justin.Urbany
* Filename:		OpenCells.h
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef OPENCELLS_H
#define OPENCELLS_H
#include "Array.h"
#include "card.h"
/************************************************************************
* Class: OpenCells
*
* Purpose: Holds an array of Cards that resemble free cells in Free Cell
*
* Manager functions:
* 	OpenCells(): Createss an Array of Cards
*	~HomeCells() Deletes an array of Cards
* Methods:
*		void PrintOpen();
*			Prints out the OpenCells
*		int GetOpen()
*			returns number of open free cells
*		void SetCard(Card & card, int column)
*			takes in a Card and a column sets card at column
*		Card & GetCard(int column)
*			takes in Column and returns card at that column
*************************************************************************/
class OpenCells
{
public:
	OpenCells();
	~OpenCells();
	void PrintOpen();
	int GetOpen();
	void SetCard(Card & card, int column);
	Card & GetCard(int column);
private:
	Array<Card> m_Open_Cells;
	int m_open = 4;
};

#endif OPENCELLS_H