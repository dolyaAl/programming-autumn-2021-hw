#include <iostream>
#include "DLinkedList.h"


void fill_after_first(DLinkedList& l)
{
	for (int i = 4; i >= 0; --i)
	{
		l.add_after_firs(i);
	}	
}

void fill_last(DLinkedList& l)
{
	for (int i = 5; i < 10; ++i)
	{
		l.add_last(i);
	}
}

bool ifing(DNode* x)
{
	if (x->data % 2 == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	DLinkedList l;
	fill_after_first(l);
	fill_last(l);
	l.print();
	std::cout << std::endl;

	l.del_last();
	l.print();
	std::cout << std::endl;

	l.del_second();
	l.print();
	std::cout << std::endl;

	l.insertp(3, 3);
	l.print();
	std::cout << std::endl;

	l.delp(3);
	l.print();
	std::cout << std::endl;

	//l.reverse();
	//l.print();
	//std::cout << std::endl;

	l.remove_if(ifing);
	l.print();
	std::cout << std::endl;

	DLinkedList a(l);
	a.print();
	std::cout << std::endl;

	DLinkedList b;
	b = a;
	b.print();
	std::cout << std::endl;
	


	return EXIT_SUCCESS;
}