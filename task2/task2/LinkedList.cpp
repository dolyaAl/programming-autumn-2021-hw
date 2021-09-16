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

LinkedList::LinkedList(const LinkedList& list)
{
	Node* t;
	t = list.head;
	head = copy(t);
}

LinkedList::~LinkedList()
{
	del();
}

LinkedList& LinkedList::operator=(const LinkedList& list)
{
	Node* t;
	t = list.head;
	this->head = copy(t);
	return *this;
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

void LinkedList::insertptr(int d, int n)
{
	if (n == 0)
	{
		add_first(d);
		return;
	}
	else if (n == getlenght())
	{
		add_last(d);
		return;
	}
	else if (!indexValid(n))
	{
		return;
	}
	get_ptr(n - 1)->next = new Node(d, get_ptr(n));

}

void LinkedList::delptr(int n)
{
	if (!indexValid(n))
	{
		return;
	}
	else if (n == 0)
	{
		Node* t;
		t = get_ptr(n);
		head = head->next;
		delete t;
		return;
	}
	Node* t;
	t = get_ptr(n);
	get_ptr(n - 1)->next = get_ptr(n)->next;
	delete t;
}

void LinkedList::reverse()
{
	Node* t;
	t = head;
	int i = 0;
	while (indexValid(i))
	{
		t = head;
		head = head->next;
		insert(getlenght() - i, t);
		++i;
	}
}

void LinkedList::remove_if(bool (*fnc)(Node*))
{
	Node* t;
	t = head;
	int i = 0;
	while (t != nullptr)
	{
		if (fnc(t))
		{
			t = t->next;
			delptr(i);
		}
		else
		{
			++i;
			t = t->next;
		}
	}
}

void LinkedList::del()
{
	if (getlenght() == 0)
	{
		return;
	}
	else
	{
		Node* t;
		t = head;
		while (t != nullptr)
		{
			Node* h;
			h = t;
			t = t->next;
			delete h;
		}
		head = t;
	}
}

void LinkedList::insert(int n, Node* ins)
{
	if (n == 0)
	{
		ins->next = head;
		head = ins;
		return;
	}
	else if (n == getlenght())
	{
		ins->next = nullptr;
		last()->next = ins;
		return;
	}
	else if (!indexValid(n))
	{
		return;
	}
	ins->next = get_ptr(n);
	get_ptr(n - 1)->next = ins;
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

Node* copy(Node*& x)
{
	Node* t;
	t = nullptr;
	if (x != nullptr)
	{
		t = new Node(x->data, copy(x->next));
	}
	return t;
}
