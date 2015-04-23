#include <iostream>
#include "LinkedList.h"
using namespace std;


int main ()
{
	Link L;
	L.Insert(1);
	L.Insert(2);
	L.Insert(3);
	L.Insert(4);
	L.Insert(5);
	L.Insert(6);
	L.Insert(7);
	L.Insert(8);
	L.Insert(9);
	//L.Delete(9);
	//L.Invert();
	L.Print();
	return 0;
}
