#define _CRTDBG_MAP_ALLOC

#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <crtdbg.h>

#include "List.h"
#include "Node.h"
#include "Exception.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	///*
	List<string> stringlist;
	List<string>secondstringlist = stringlist;

	//try
	//{
	//	stringlist.First();
	//}
	//catch (Exception &exception)
	//{
	//	cout << exception.getMessage();
	//}
	//try
	//{
	//	stringlist.Last();
	//}catch (Exception &exception)
	//{ 
	//	cout << exception.getMessage();
	//}

	stringlist.Append(string("1stAppend"));
	stringlist.Append(string("secondAppend"));
	stringlist.PrintForwards();
	cout << "\n";
	stringlist.Prepend("firstprepend");
	stringlist.Prepend("lastprepend");
	stringlist.PrintBackwards();
	cout << "\n";
	stringlist.PrintForwards();
	//try
	//{
	//	stringlist.Extract("Prepend should be in front");
	//}
	//catch (Exception &exception)
	//{
	//	cout << exception.getMessage();
	//}

	cout << "\n";
	stringlist.PrintForwards();
	cout << "\n";

	stringlist.InsertBefore("firstprepend", "Work");
	stringlist.InsertBefore("lastprepend", "insertbeforehead");
	stringlist.InsertBefore("secondAppend", "insertbeforeTail");

	cout << "\n";
	stringlist.PrintForwards();

	stringlist.InsertAfter("firstprepend", "Work");
	stringlist.InsertAfter("insertbeforehead", "insertafterhead");
	stringlist.InsertAfter("secondAppend", "insertaftertail");
	
	cout << "\n";
	stringlist.PrintForwards();

	stringlist.Extract("insertbeforehead");
	
	cout << "\n";
	stringlist.PrintForwards();
	


	cout << "\n";
	secondstringlist.PrintForwards();
	stringlist.Purge();
	secondstringlist.Append("Is this the trick");
	secondstringlist.PrintForwards();



	//cout << "\n" << secondstringlist.getHead() << ' ' << secondstringlist.getTail() << "\n";

	//*/

	/*

	//Test 2 with pointers works you don't new the secondlist so you don't have to delete it

	List<string> * stringlist = new List<string>;
	List<string> * secondlist = stringlist;
	//List<string> * secondlist = new List<string>; //doesn't work with the delete cause deleting memory you don't own
	//secondlist = stringlist;

	stringlist->Append(string("1stAppend"));
	stringlist->Append(string("secondAppend"));
	stringlist->PrintForwards();
	cout << "\n";
	stringlist->Prepend("firstprepend");
	stringlist->Prepend("lastprepend");
	stringlist->PrintBackwards();
	cout << "\n";
	stringlist->PrintForwards();

	cout << "\n";
	stringlist->PrintForwards();
	cout << "\n";

	stringlist->InsertBefore("firstprepend", "Work");
	stringlist->InsertBefore("lastprepend", "insertbeforehead");
	stringlist->InsertBefore("secondAppend", "insertbeforeTail");

	cout << "\n";
	stringlist->PrintForwards();

	stringlist->InsertAfter("firstprepend", "Work");
	stringlist->InsertAfter("insertbeforehead", "insertafterhead");
	stringlist->InsertAfter("secondAppend", "insertaftertail");

	cout << "\n";
	stringlist->PrintForwards();

	stringlist->Extract("insertbeforehead");

	cout << "\n";
	stringlist->PrintForwards();

	cout << "\n";
	secondlist->PrintForwards();
	cout << "\n" << secondlist->getHead() << ' ' << secondlist->getTail() << "\n";

	secondlist->Extract("insertaftertail");

	cout << "\n" << secondlist->First() << ' ' << secondlist->Last() << "\n";
	cout << "\n" << stringlist->First() << ' ' << stringlist->Last() << "\n";


	delete stringlist;
	stringlist = nullptr;
	//delete secondlist;
	//secondlist = nullptr;
	*/

	return 0;
}