// ListProcessor.cpp

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.

#include "stdafx.h"
#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl;
	cout << "cows list size  :  " << cows.size() << endl;
	cout << "cows list sum  :  " << cows.sum() << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cout << "cows list  :  " << cows << endl;
	cout << "cows list size  :  " << cows.size() << endl;
	cout << "cows list sum  :  " << cows.sum() << endl;
	cows.insertAsLast(3.45);
	cout << "cows list  :  " << cows << endl;
	cout << "cows list size  :  " << cows.size() << endl;
	cout << "cows list sum  :  " << cows.sum() << endl << endl;

	cows.removeFirst();
	cout << "cows list  :  " << cows << endl;
	cout << "cows list size  :  " << cows.size() << endl;
	cout << "cows list sum  :  " << cows.sum() << endl << endl;

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list  :  " << horses << endl;
	cout << "horses list size :  " << horses.size() << endl;
	cout << "horses list sum  :  " << horses.sum() << endl << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list  :  " << horses << endl;
	cout << "cows list size  :  " << cows.size() << endl;
	cout << "horses list size :  " << horses.size() << endl;
	cout << "cows list sum  :  " << cows.sum() << endl;
	cout << "horses list sum  :  " << horses.sum() << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list  :  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl;
	cout << "pigs list size  :  " << pigs.size() << endl;
	cout << "pigs list sum  :  " << pigs.sum() << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list  :  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl;
	cout << "pigs list size  :  " << pigs.size() << endl;
	cout << "pigs list sum  :  " << pigs.sum() << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list  :  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl;
	cout << "pigs list size  :  " << pigs.size() << endl;
	cout << "pigs list sum  :  " << pigs.sum() << endl << endl;

	List sheep;
	cout << "sheep list  :  " << sheep << endl;
	sheep.insertAsLast(42);
	cout << "sheep list  :  " << sheep << endl;
	sheep.insertAsLast(51);
	cout << "sheep list  :  " << sheep << endl;
	sheep.insertAsLast(60);
	cout << "sheep list  :  " << sheep << endl;
	sheep.insertAsFirst(33);
	cout << "sheep list  :  " << sheep << endl << endl;

	cout << "End of code" << endl;

	return 0;
}

