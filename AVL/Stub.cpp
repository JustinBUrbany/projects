/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	2/19/17
* Modifications:	2/21/17 -Built Test code
*					2/21/17 -added memory leak checker
*					2/22/17 -Added Comments
**************************************************************/
#define _CRTDB_MAP_ALLOC
#include <iostream>
using std::cout;
using std::endl;
#include "AVL.h"
#include <crtdbg.h>


/**********************************************************************
* Purpose: The purpose of this function is to Display a value that is
*	passed in to the screen
*
* Precondition: A value must be passed to the function to be displayed
*
* Postcondition: The value must be displayed to the screen
*
************************************************************************/
template<typename T>
void PrintTree(T data);

/*************************************************************
*
* Lab/Assignment: Lab 4-AVL Tree
*
* Overview:
*	The Idea of this program is to build an avl tree or
*	self balancing binary search tree. The AVL Tree inherits
*	from the binary search tree and adds the rebalancing
*	feature.
*
* Input:
*   This program doesn't take any input.
*
* Output:
*   The output of this program is speciffically designed to
*	print out all values in the tree in Breath First Order
************************************************************/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	AVL<int> testtree;
	AVL<int> testtree2;

	testtree.Insert(7);
	testtree.Insert(5);
	testtree.Insert(6);
	testtree.Print(PrintTree);
	cout << endl;

	testtree.Insert(15);
	testtree.Print(PrintTree);
	cout << endl;

	testtree.Insert(14);
	testtree.Print(PrintTree);
	cout << endl;

	testtree.Insert(25);
	testtree.Print(PrintTree);
	cout << endl;

	testtree.Insert(3);
	testtree.Print(PrintTree);

	testtree2 = testtree;

	cout << endl;

	testtree2.Print(PrintTree);

	cout << endl;

	testtree.Delete(14);

	cout << endl;
	testtree.Print(PrintTree);

	testtree.Insert(14);

	cout << endl;
	testtree.Print(PrintTree);

	testtree.Insert(12);

	cout << endl;
	testtree.Print(PrintTree);



	return 0;
}


template<typename T>
void PrintTree(T data)
{
	cout << data << ' ';
}