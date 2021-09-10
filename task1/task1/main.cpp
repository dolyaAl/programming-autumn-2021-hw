#include "LinkedList.h"
#include <iostream>


void fill(LinkedList& list)
{
	std::cout << "Adding first" << std::endl;
	list.add_first(0);
	list.print();
	std::cout << std::endl;

	std::cout << "Adding after first" << std::endl;
	for (int i = 5; i > 0; --i)
	{
		list.add_after_first(i);
		list.print();
		std::cout << std::endl;
	}
	std::cout << "Adding from the end" << std::endl;
	for (int i = 6; i < 10; ++i)
	{
		list.add_last(i);
		list.print();
		std::cout << std::endl;
	}
}

bool ifing(Node* t)
{
	return t->data % 2 == 0;
}

int main()
{
	LinkedList list;
	std::cout << "First print: ";
	list.print();
	std::cout << "trying to fill the list:" << std::endl;
	fill(list);

	if (list.last() != nullptr)
	{
		std::cout << "get last() = " << list.last()->data << std::endl;
	}
	if (list.prelast() != nullptr)
	{
		std::cout << "get last() = " << list.prelast()->data << std::endl;
	}
	if (list.get_ptr(5) != nullptr)
	{
		std::cout << "get_ptr(5) = " << list.get_ptr(5)->data << std::endl;
	}

	std::cout << "delete last:" << std::endl;
	list.del_last();
	list.print();
	std::cout << std::endl;

	std::cout << "insertptr(10,5):" << std::endl;
	list.insertptr(10, 5);
	list.print();
	std::cout << std::endl;

	std::cout << "delptr(10,5):" << std::endl;
	list.delptr(5);
	list.print();
	std::cout << std::endl;

	std::cout << "reverse():" << std::endl;
	list.reverse();
	list.print();
	std::cout << std::endl;

	std::cout << "remove_if() [t->data % 2 == 0]:" << std::endl;
	list.remove_if(ifing);
	list.print();
	std::cout << std::endl;

	return 1;
}