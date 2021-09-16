#include "LinkedList.h"
#include <iostream>
#include<omp.h>


void fill(LinkedList& list)
{
	list.add_first(0);

	for (int i = 5; i > 0; --i)
	{
		list.add_after_first(i);
	}

	for (int i = 6; i < 10; ++i)
	{
		list.add_last(i);
	}
}

void fill2(LinkedList& list)
{
	list.add_first(0);

	for (int i = 100; i > 0; --i)
	{
		list.add_after_first(i);
	}
}

int main()
{
	LinkedList list;
	fill(list);
	list.print();
	std::cout << std::endl;

	LinkedList list1(list);
	list.del();
	list1.print();
	std::cout << std::endl;
	

	LinkedList list2;
	list2 = list1;
	list2.print();
	std::cout << std::endl;

	//compare time...............................................................................
	std::cin.get();
	LinkedList TimeTestL;
	fill2(TimeTestL);
	int M[100]{ 0 };
	double t1 = omp_get_wtime();
	for (int i = 0; i < 2000; ++i)
	{
		std::cout << TimeTestL.get_ptr(50)->data << std::endl;
	}
	double t2 = omp_get_wtime();
	std::cout << "LinkedList time = " << t2 - t1 << std::endl;


	t1 = omp_get_wtime();
	for (int i = 0; i < 2000; ++i)
	{
		M[50];
	}
	t2 = omp_get_wtime();
	std::cout << "Massive time = " << t2 - t1 << std::endl;



	return 1;
}