/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#define _CRTDBG_MAP_ALLOC
#include "FreeCell.h"
#include <crtdbg.h>
/*************************************************************
*
* Lab/Assignment: Lab 3-FreeCell
*
* Overview:
*	This program will create a deck of cards and 3 areas of
*	play. The freecell area will consist of an array of 4
*	cards that can a card can be place each time a part of the
*	array is empty. The Home area will consist of an array of
*	length 4 which each part of the array is a stack of size 13
*	where cards that are numerically acsending and have the same
*	suit can be stacked on top of each other. The play cell
*	will contain an array of linked list where the deck will
*	orginally be populate and the user will have to move all
*	the cards out of the play cell area in order to win the game
* Input:
*   The input consists of  user selecting the are they want to
*	play from and where they want to play too along with the 
*	number of cards the user wants to select as well as the 
*	what column they want to play from and which column they want 
*	play too.
*
* Output:
*   The output of this program is to display each area of
*	the game as well as the current card in each area. Also
*	the game will display a menu and various choices for the
*	user to select from in order to move cards into other areas
*	and specific columns
************************************************************/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //memory leak checker

	FreeCell Game;

	return 0;
}