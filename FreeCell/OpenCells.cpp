/*************************************************************
* Author:		Justin.Urbany
* Filename:		OpenCells.cpp
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#include "OpenCells.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;
/**********************************************************************
* Purpose: The purpose of this function is to create the open cells 
*			and set the array length of the open cells to 4
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
OpenCells::OpenCells()
{
	m_Open_Cells.setLength(4);
}
/**********************************************************************
* Purpose: The purpose of this function is to clean up any memory and
*			delete the opencells when it goes out of scope
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
OpenCells::~OpenCells()
{
}
/**********************************************************************
* Purpose: The purpose of this function is to print all the open cells
*			and there values to the screen if they are valid values
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void OpenCells::PrintOpen()
{

	for (int i = 0; i<4; ++i)
	{
		//if(m_Open_Cells[i].GetSuit==Diamond)
		if (m_Open_Cells[i].GetRank() == 15)
		{
			cout << setw(10) << "Open";
		}
		else
		{
			m_Open_Cells[i].DisplayCard();
		}
	}



}
/**********************************************************************
* Purpose: The purpose of this function is to return the number of open
*			cells in your open cell area
*
* Precondtion: None
*
* Postcondition: Return the number of open cells
*
************************************************************************/
int OpenCells::GetOpen()
{
	return m_open;
}
/**********************************************************************
* Purpose: The purpose of this function is to set a card into an open
*			Cell if no card is in that open cell
*
* Precondtion: Takes in the column number and the card being placed in
*				that cell
*
* Postcondition: None
*
************************************************************************/
void OpenCells::SetCard(Card & card, int column)
{
	if (m_Open_Cells[column].GetRank() == 15)
	{
		m_Open_Cells[column] = card;
		m_open--;
	}
	else
	{
		cout << "Already a Card in that cell\n";
	}
}
/**********************************************************************
* Purpose: This function takes in a column and returns the card in that
*			column
*
* Precondtion: Takes in the column that is going to be looked at
*
* Postcondition: Returns the card from the passed in column
*
************************************************************************/
Card & OpenCells::GetCard(int column)
{
	Card temp = m_Open_Cells[column];
	m_Open_Cells[column].SetRank(m_Open_Cells[column].INVALID);
	if (temp.GetRank() != 15)
	{
		m_open++;
	}

	return temp;
}