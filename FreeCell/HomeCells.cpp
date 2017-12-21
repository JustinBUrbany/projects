/*************************************************************
* Author:		Justin.Urbany
* Filename:		Homecell.cpp
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#include "HomeCells.h"
#include <iostream>
#include <iomanip>
using std::setw;
using std::cout;
/**********************************************************************
* Purpose: The purpose of this function is to create home sells and
*			Intialize the array length to 4
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
HomeCells::HomeCells()
{
	m_Home_Cells.setLength(4);
	//m_Home_Cells
}
/**********************************************************************
* Purpose: The purpose of this function is to clean up memory from home
*			Cells
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
HomeCells::~HomeCells()
{
}
/**********************************************************************
* Purpose: The purpose of this function is to check if it is a valid
*			Move to move the passed in Card Home in that column and
*			Move that card home if it is valid
*
* Precondtion: Takes in the card that wants to be moved home and the
*				column that it is being moved too
*
* Postcondition: Returns true if the card was moved in and false if the
*					Card is not
*
************************************************************************/
bool HomeCells::MoveHome(Card & card, int column)
{
	bool validmove = false;
	if (!m_Home_Cells[column].isEmpty())
	{
		Card tempcard = m_Home_Cells[column].Peek();
		if ((card.GetRank() - 1) == tempcard.GetRank() && tempcard.GetSuit() == card.GetSuit())
		{
			m_Home_Cells[column].Push(card);
			validmove = true;
		}
		else
		{
			validmove = false;
		}
	}
	else if (m_Home_Cells[column].isEmpty() && card.GetRank() == card.ACE)
	{
		m_Home_Cells[column].Push(card);
		validmove = true;
	}
	else
	{
		validmove = false;
	}
	return validmove;
}
/**********************************************************************
* Purpose: The purpose of this Function is to Move a card out of home area
*
* Precondtion: takes in the column of the cell moving out of
*
* Postcondition: Returns the card and decrements the homecell
*
************************************************************************/
Card HomeCells::MoveOutofHome(int column)
{
	return m_Home_Cells[column].Pop();
}
/**********************************************************************
* Purpose: The purpose of this function is to see if all HomeCells are empty
*
* Precondtion: None
*
* Postcondition: Returns false if homecells aren't all empty else it
*					Returns true 
*
************************************************************************/
bool HomeCells::CheckAllCells()
{
	bool check_if_cards = false;

	for (int i = 0; i < 4; i++)
	{
		if (!m_Home_Cells[i].isEmpty())
		{
			check_if_cards = true;
		}
	}
	return check_if_cards;
}
/**********************************************************************
* Purpose: The purpose is to see if an individual home cell is empty
*
* Precondtion: takes in the column that is going to be checked
*
* Postcondition: Returns true if the home cell is not empty return
*				false if home cell is empty
*
************************************************************************/
bool HomeCells::CheckSingleCell(int column)
{
	bool check_if_card = true;
	if (m_Home_Cells[column].isEmpty())
	{
		check_if_card = false;
	}
	return check_if_card;
}
/**********************************************************************
* Purpose: The purpose of this function is to print out all the home
*			Cells and the last card that was put in the home cell if
*			it is not empty
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void HomeCells::PrintHomeCells()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_Home_Cells[i].isEmpty())
		{
			cout << setw(10) << "Open";
		}
		else
		{
			m_Home_Cells[i].Peek().DisplayCard();
		}
	}
	cout << "\n";
}