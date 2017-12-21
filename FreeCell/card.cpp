/*************************************************************
* Author:		Justin.Urbany
* Filename:		card.cpp
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include "card.h"
#include <iostream>
#include <iomanip>
using std::setw;
using std::cin;
/**********************************************************************
* Purpose:Multi arg constructor intialize suit and rank of a card
*
* Precondition: pass in a suit and a rank
*
* Postcondition: intialize the object
*
************************************************************************/
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit)
{
	SetConsoleTextAttribute(hStdout, 15);
}
/**********************************************************************
* Purpose:The purpose of this function is to display the card to the
screen
*
* Precondition: be called within a card object
*
* Postcondition: have displayed a card to the screen
*
************************************************************************/
void Card::DisplayCard()
{
	const char*rank_txt[] = { "A","2", "3", "4", "5", "6", "7", "8",
		"9", "10", "J", "Q","K" };
	if (m_suit == 3)
	{
		SetConsoleTextAttribute(hStdout, 12);
	}
	else if (m_suit == 4)
	{
		SetConsoleTextAttribute(hStdout, 4);
	}
	else if (m_suit == 5)
	{
		SetConsoleTextAttribute(hStdout, 7);
	}

	//cout <<setw(8)<<" "<< rank_txt[m_rank - 1] << static_cast<char>(m_suit);
	cout << setw(8) << m_rank << " " << static_cast<char>(m_suit);
	SetConsoleTextAttribute(hStdout, 15);
}
/**********************************************************************
* Purpose:default destructor delete a card clean up memory
*
* Precondition: called when a card is going out of close
*
* Postcondition: the card no longer exsits
*
************************************************************************/
Card::~Card()
{

}
/**********************************************************************
* Purpose:This function is to set the rank of your cards private member
rank
*
* Precondition: called within a card and pass in a rank
*
* Postcondition: set m_rank to the rank
*
************************************************************************/
void Card::SetRank(Rank rank)
{
	m_rank = rank;
}
/**********************************************************************
* Purpose:This function is to set the suit of your cards data member
suit
*
* Precondition:called within a card and pass in a suit
*
* Postcondition: set the private member suit to the value that was
passed in
*
************************************************************************/
void Card::SetSuit(Suit suit)
{
	m_suit = suit;

}
/**********************************************************************
* Purpose: Returns thte private rank member of your cards
*
* Precondition: get called within a card object
*
* Postcondition: return the private data member m_rank
*
************************************************************************/
//Card::Rank 
int Card::GetRank()
{
	int tempvalue = 0;
	if (m_rank == ACE)
	{
		tempvalue = 1;
	}
	else if (m_rank == DEUCE)
	{
		tempvalue = 2;
	}
	else if (m_rank == TREY)
	{
		tempvalue = 3;
	}
	else if (m_rank == FOUR)
	{
		tempvalue = 4;
	}
	else if (m_rank == FIVE)
	{
		tempvalue = 5;
	}
	else if (m_rank == SIX)
	{
		tempvalue = 6;
	}
	else if (m_rank == SEVEN)
	{
		tempvalue = 7;
	}
	else if (m_rank == EIGHT)
	{
		tempvalue = 8;
	}
	else if (m_rank == NINE)
	{
		tempvalue = 9;
	}
	else if (m_rank == TEN)
	{
		tempvalue = 10;
	}
	else if (m_rank == JACK)
	{
		tempvalue = 11;
	}
	else if (m_rank == QUEEN)
	{
		tempvalue = 12;
	}
	else if (m_rank == KING)
	{
		tempvalue = 13;
	}
	else if (m_rank == INVALID)
	{
		tempvalue = 15;
	}

	return tempvalue;

}



/**********************************************************************
* Purpose:This is a getter for the card class that returns the private
member m_suit
*
* Precondition: get called within a card object
*
* Postcondition: must return the private member m_suit
*
************************************************************************/
Card::Suit Card::GetSuit()
{

	return m_suit;

}