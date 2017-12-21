/*************************************************************
* Author:		Justin.Urbany
* Filename:		Board.cpp
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#include "Board.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
/**********************************************************************
* Purpose: Create a Board
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
Board::Board()
{
}
/**********************************************************************
* Purpose: Delete a Board and all its contents
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
Board::~Board()
{

}
/**********************************************************************
* Purpose: The purpose of this function is to pass the current Deck
*			To the Play_Cells class and have playcells populated with
*			Cards
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void Board::Deal()
{
	m_deck.Shuffle();
	m_play_cells.PopulatePlaycells(m_deck);
	PlayGame();
}
/**********************************************************************
* Purpose: This is the Driver of the game function it has an interactive
*			Menu that will allow the user to select from 3 different moves
*			which will have various options that he/she can chose from to
*			try and play the game. Also this function will call PrintBoard
*			After a move has been completed so the user can see their progress
*
* Precondtion: None
*
* Postcondition: The Game must be won to leave the function
*
************************************************************************/
void Board::PlayGame()
{
	char selection = '0';
	int playselect = 0;
	Card temp;
	bool gameover = false;
	while (gameover == false)
	{
		PrintBoard();
		cout << "From where would you like to Play?((a)PlayCells,(b)FreeCell,(c)HomeCell,(q)Quit):";
		cin >> selection;
		switch (selection)
		{
		case 'a':
		{
			//////////////////////////////////////////////////////////////////////////////////PLAY CELL/////////////////////////////////////////////////////////////////////////////////////
			cout << "Play Area selected\n";
			Card tempplaycard;
			int playcolumnselect = 0;
			while (playcolumnselect < 1 || playcolumnselect>8)
			{
				cout << "Which Play column would you like to Play from?(1,2,3....8):";
				cin >> playcolumnselect;
				while (playcolumnselect < 1 || playcolumnselect>8)
				{
					cout << "Not a valid Play Area Column\n";
				}
			}
			if (!m_play_cells.PlayCellEmpty(playcolumnselect - 1))
			{
				int playtoo = 0;
				while (playtoo < 1 || playtoo>3)
				{
					cout << "Where do you want to play too?(1Play,2Free,3Home):";
					cin >> playtoo;
					if (playtoo < 1 || playtoo>3)
					{
						cout << "Not a valid Play Area\n";
					}
				}
				if (playtoo == 1)
				{
					int singlecard = 0;
					while (singlecard < 1 || singlecard>2)
					{
						cout << "Do you want to play a single or multiple cards?(1single,2multiple)";
						cin >> singlecard;
						if (singlecard < 1 || singlecard>2)
						{
							cout << "Invalid Selection\n";
						}
					}
					if (singlecard == 1)
					{
						int playmoveincolumn = 0;
						while (playmoveincolumn < 1 || playmoveincolumn>8)
						{
							cout << "What column do you wish to play too?(1,2,3...8)";
							cin >> playmoveincolumn;
							if (playmoveincolumn < 1 || playmoveincolumn >8)
							{
								cout << "Invalid Column selected.\n";
							}
						}
						if (playmoveincolumn != playcolumnselect)
						{
							tempplaycard = m_play_cells.MoveCardOut(playcolumnselect - 1);
							if (!m_play_cells.MoveCardPlay(tempplaycard, playmoveincolumn - 1))
							{
								m_play_cells.Reset(tempplaycard, playcolumnselect - 1);
							}
						}
					}
					else
					{
						int openslots = m_open_cells.GetOpen();
						openslots += m_play_cells.Get_Open_Play_Cells();
						if (openslots == 0)
						{
							cout << "There are no free cells can only move 1 card.\n";
						}
						else
						{
							m_play_cells.MoveMultipleCards(playcolumnselect - 1, openslots);
						}
					}

				}
				else if (playtoo == 2)
				{
					if (m_open_cells.GetOpen() != 0)
					{
						int freeselect = 0;
						while (freeselect < 1 || freeselect>4)
						{
							cout << "Which Free Column would you like to select?(1,2,3,4)";
							cin >> freeselect;
							if (freeselect < 1 || freeselect>4)
							{
								cout << "Not a valid Free Column\n";
							}
						}
						Card tempfreecard = m_open_cells.GetCard(freeselect - 1);
						if (tempfreecard.GetRank() == 15/*tempfreecard.INVALID*/)
						{
							tempplaycard = m_play_cells.MoveCardOut(playcolumnselect - 1);
							m_open_cells.SetCard(tempplaycard, freeselect - 1);
						}
						else
						{
							cout << "That Free Cell has a card can't move there.\n";
							m_open_cells.SetCard(tempfreecard, freeselect - 1);
						}
					}
					else
					{
						cout << "Can't move to Free Cell All Free Cells are full.\n";
					}
				}
				else
				{
					//Home CEll from play
					int homeselect = 0;
					while (homeselect < 1 || homeselect>4)
					{
						cout << "Which Home Column would you like to select?(1,2,3,4)";
						cin >> homeselect;
						if (homeselect < 1 || homeselect>4)
						{
							cout << "Not a valid Home Column\n";
						}
					}
					tempplaycard = m_play_cells.MoveCardOut(playcolumnselect - 1);
					if (m_home_cells.MoveHome(tempplaycard, homeselect - 1))
					{
						cout << "\n\n Moved ";
						tempplaycard.DisplayCard();
						cout << " To Home Cell" << homeselect << "\n\n";
					}
					else
					{

						m_play_cells.Reset(tempplaycard, playcolumnselect - 1);
						cout << " \n\nCould not move ";
						tempplaycard.DisplayCard();
						cout << " To Home cell" << homeselect << "\n\n";
					}

				}
			}
			else
			{
				cout << "Can't move from an Empty Cell\n";
			}
			gameover = CheckWin();
			break;
		}
		case 'b':
		{
			////////////////////////////////////////////////////////////////////////////FREECELL///////////////////////////////////////////////////////////////////////////////////
			cout << "Free Cell selected\n";
			if (m_open_cells.GetOpen() == 4)
			{
				cout << "There are no cards in your free Cells Can't play from here\n";
			}
			else
			{
				int column = 0;
				while (column < 1 || column>4)
				{
					cout << "Which Free Cell Card would you like to Move(1,2,3,4):";
					cin >> column;
					if (column < 1 || column>4)
					{
						cout << "Not valid column \n";
					}
				}
				temp = m_open_cells.GetCard(column - 1);
				if (temp.GetRank() == 14)
				{
					cout << "There was no card In that column\n";
				}
				else
				{
					PrintBoard();
					cout << "Current Card selected is ";
					temp.DisplayCard();
					cout << " Moving from A free cell \n";
					int movetoo = 0;
					while (movetoo < 1 || movetoo>3)
					{
						cout << "Where would you like to move too?(1Play, 2Home,3 Free):";
						cin >> movetoo;
						if (movetoo < 1 || movetoo>3)
						{
							cout << "Invalid Selection\n";
						}
					}
					if (movetoo == 1)
					{
						int checkplay = 0;
						while (checkplay < 1 || checkplay>8)
						{
							cout << "Which Play cell would you like to move card too?(1,2...8)";
							cin >> checkplay;
							if (checkplay < 1 || checkplay>8)
							{
								cout << "Invalid Play Column\n";
							}
						}
						if (m_play_cells.MoveCardPlay(temp, checkplay - 1))
						{
							cout << "Valid move: Moved ";
							temp.DisplayCard();
							cout << "to Play column " << checkplay << ".\n";
						}
						else
						{
							m_open_cells.SetCard(temp, column - 1);
						}
					}
					else if (movetoo == 2)
					{
						int checkhome = 0;
						while (checkhome < 1 || checkhome>4)
						{
							cout << "Which Home Cell would you like to move too?(1,2,3,4):";
							cin >> checkhome;
							if (checkhome < 1 || checkhome>4)
							{
								cout << "Invalid Home Column\n";
							}
						}
						if (m_home_cells.MoveHome(temp, checkhome - 1))
						{
							cout << "Valid move: Moved ";
							temp.DisplayCard();
							cout << " to Home column " << checkhome << ".\n";
						}
						else
						{
							m_open_cells.SetCard(temp, column - 1);
						}
					}
					else
					{
						int checkfree = 0;
						while (checkfree < 1 || checkfree>4)
						{
							cout << "Moving to free. Which Column would you like to select(1,2,3,4)";
							cin >> checkfree;
							if (checkfree < 1 || checkfree>4)
							{
								cout << "Not valid Free column \n";
							}
						}
						Card tempfree = m_open_cells.GetCard(checkfree - 1);
						if (tempfree.GetRank() == 15)
						{
							m_open_cells.SetCard(temp, checkfree - 1);
						}
						else
						{
							m_open_cells.SetCard(temp, column - 1);
							cout << "That cell already had a card Reseting Move \n";
						}
					}

				}
			}
			gameover = CheckWin();
			break;
		}
		case 'c':
		{
			///////////////////////////////////////////////////HOMECELLL//////////////////////////////////////////////////////////////////////////////
			cout << "Home Cell selected \n";
			if (m_home_cells.CheckAllCells())
			{
				int homecellselect = 0;
				while (homecellselect < 1 || homecellselect>4)
				{
					cout << "Which HomeCell would you like to Select?(1,2,3,4";
					cin >> homecellselect;
					if (homecellselect < 1 || homecellselect>4)
					{
						cout << "That is not a Valid Home Cell.\n";
					}
				}
				if (m_home_cells.CheckSingleCell(homecellselect - 1))
				{
					Card temphomecell = m_home_cells.MoveOutofHome(homecellselect - 1);
					int playselect = 0;
					while (playselect < 1 || playselect>2)
					{
						cout << "Where would you like to Move?(1Play,2Free)";
						cin >> playselect;
						if (playselect < 1 || playselect>2)
						{
							cout << "Invalid place to move.\n";
						}
					}
					if (playselect == 1)
					{
						int cellselect = 0;
						while (cellselect < 1 || cellselect>8)
						{
							cout << "Which Play cell would you like to move card too?(1,2...8)";
							cin >> cellselect;
							if (cellselect < 1 || cellselect>8)
							{
								cout << "Invalid Play Column\n";

							}
						}
						if (m_play_cells.MoveCardPlay(temphomecell, cellselect - 1))
						{
							cout << "Valid move: Moved ";
							temphomecell.DisplayCard();
							cout << "to Play column " << cellselect << ".\n";
						}
						else
						{
							m_home_cells.MoveHome(temphomecell, homecellselect - 1);
						}

					}
					else
					{
						if (m_open_cells.GetOpen() != 0)
						{
							int checkfree = 0;
							while (checkfree < 1 || checkfree>4)
							{
								cout << "Moving to free. Which Column would you like to select(1,2,3,4)";
								cin >> checkfree;
								if (checkfree < 1 || checkfree>4)
								{
									cout << "Not valid Free column \n";
								}
							}
							Card tempOpen = m_open_cells.GetCard(checkfree - 1);
							if (tempOpen.GetRank() == 15)
							{
								m_open_cells.SetCard(temphomecell, checkfree - 1);
							}
							else
							{
								m_open_cells.SetCard(tempOpen, checkfree - 1);
								m_home_cells.MoveHome(temphomecell, homecellselect - 1);
							}
						}
						else
						{
							cout << "Can't Move to a free Cell they are all full.\n";
						}
					}
				}
				else
				{
					cout << "That Home Cell is Empty.\n";
				}

			}
			else
			{
				cout << "All your Home Cells are Empty Can't Move from home\n";
			}
		}
		gameover = CheckWin();
		break;
		case 'q':
		{
			gameover = true;
			break;
		}
		default:
		{
			cout << "invalid Selection\n";
			break;
		}
		}

	}
}
/**********************************************************************
* Purpose: The purpose of this function is to jsut display the board
*
* Precondtion:None
*
* Postcondition:None
*
************************************************************************/
void Board::PrintBoard()
{
	int i = 1;
	while (i < 9)
	{
		if (i < 5)
		{
			cout << setw(9) << "Free " << i;
		}
		else
		{
			cout << setw(9) << "Home " << i;
		}
		++i;
	}
	cout << "\n";
	m_open_cells.PrintOpen();
	m_home_cells.PrintHomeCells();
	m_play_cells.PrintPlayCells();
}
/**********************************************************************
* Purpose: To Check if the Game Has been won
*
* Precondtion: None
*
* Postcondition: Return if the Game has been won
*
************************************************************************/
bool Board::CheckWin()
{

	return m_play_cells.GameOver();
}