#include "LinkedList.h"
#include <iostream>

Node::Node(int d, Node* n)
{
	data = d;
	next = n;
}

LinkedList::LinkedList()
{
	head = nullptr;
}

Node* LinkedList::last()
{
	if (getlenght() == 0)
	{
		print();
		return nullptr;
	}
	Node* t;
	t = head;
	while (t->next != nullptr)
	{
		t = t->next;
	}
	return t;
}

Node* LinkedList::prelast()
{
	Node* t;
	t = head;
	while (t->next->next != nullptr)
	{
		t = t->next;
	}
	return t;
}

Node* LinkedList::get_ptr(int n)
{
	if (!indexValid(n))
	{
		return nullptr;
	}
	Node* t;
	t = head;
	for (int i = 0; i < n; ++i)
	{
		t = t->next;
	}
	return t;
}

void LinkedList::add_after_first(int d)
{
	if (getlenght() == 0)
	{
		add_first(d);
	}
	else
	{
		Node* t;
		t = new Node(d, head->next);
		head->next = t;
	}
}

void LinkedList::add_last(int d)
{
	if (getlenght() == 0)
	{
		add_first(d);
	}
	else
	{
		last()->next = new Node(d);
	}
}

void LinkedList::del_last()
{
	Node* t;
	t = last();
	prelast()->next = nullptr;
	delete t;
}

int LinkedList::getlenght()
{
	Node* t;
	t = head;
	int i = 0;
	while (t != nullptr)
	{
		++i;
		t = t->next;
	}
	return i;
}

void LinkedList::add_first(int d)
{
	if (getlenght() == 0)
	{
		head = new Node(d);
	}
	else
	{
		Node* t;
		t = new Node(d, head);
		head = t;
	}
}

bool LinkedList::indexValid(int n)
{
	return n >= 0 && n < getlenght();
}

void LinkedList::print()
{
	if (getlenght() == 0)
	{
		std::cout << "There's nothing here" << std::endl;
	}
	else
	{
		Node* t;
		t = head;
		while (t != nullptr)
		{
			std::cout << t->data << "\t";
			t = t->next;
		}
	}
}


