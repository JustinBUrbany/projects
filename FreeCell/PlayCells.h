/*************************************************************
* Author:		Justin.Urbany
* Filename:		PlayCells.h
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef PLAYCELLS_H
#define PLAYCELLS_H
#include "Array.h"
#include "Stackll.h"
#include "card.h"
#include "deck.h"
/************************************************************************
* Class: PlayCells
*
* Purpose: The Purpose of PlayCells is to contain an Array of link list
*			Stacks that Can hold lists of cards that are used to play
*			the game Free Cell
*
* Manager functions:
* 	PlayCells(): Createss an Array of Stack linked list of Cards
*	~PlayCells() Deletes the Array and all it contains
* Methods:
*		void PopulatePlayCells(Deck & deck)
*			Deals out the cards to intialize the game freecell
*		void printPlayCells()
*			Displays the playcells and contents
*		bool MoveCardPlay(Card & card, int column)
*			Takes Card column if valid places card and returns validitity
*		Card MoveCardout(int column)
*			Takes column if not empty returns top of stack card
*		void MoveMultipleCards(int column, int openspaces);
*			takes column that you want to move from and the number of
*			open cells you have
*		bool GameOver():
*			Check if Play_cells are empty if yes game if over
*		int Get_Open_Play_Cellss()
*			returns number of open play cells
*************************************************************************/
class PlayCells
{
public:
	PlayCells();
	~PlayCells();
	void PopulatePlaycells(Deck & deck);
	void PrintPlayCells();
	bool MoveCardPlay(Card & card, int column);
	void Reset(Card & card, int column);
	bool PlayCellEmpty(int column);
	Card MoveCardOut(int column);
	void MoveMultipleCards(int column, int openspaces);
	bool GameOver();
	int Get_Open_Play_Cells();
private:
	Array<Stackll<Card>> m_Play_Cells;
	int m_Open_Play_Cells = 0;
};

#endif