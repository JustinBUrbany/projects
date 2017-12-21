/*************************************************************
* Author:		Justin.Urbany
* Filename:		FreeCell.cpp
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#include "FreeCell.h"
#include <iostream>
using std::cout;
using std::cin;
/**********************************************************************
* Purpose: Create a New board then Call Deal
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
FreeCell::FreeCell()
{
	m_board = new Board;
	Deal();
}
/**********************************************************************
* Purpose: Delete the Board and all of its contents
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
FreeCell::~FreeCell()
{
	delete m_board;
}
/**********************************************************************
* Purpose: Deal and then when done call Play again
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void FreeCell::Deal()
{
	m_board->Deal();
	PlayAgain();
}
/**********************************************************************
* Purpose: Asks user if they want to play again if yes then they can
*	Play again else Program exits
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void FreeCell::PlayAgain()
{
	char selection = '\0';
	while (selection != 'n' && selection != 'y')
	{
		cout << "would you like to play again?(y,n):";
		cin >> selection;
	}

	if (selection == 'y')
	{
		delete m_board;
		m_board = new Board;
		Deal();
	}
}