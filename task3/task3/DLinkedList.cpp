#include "DLinkedList.h"
#include <iostream>

DNode::DNode(int d, DNode* n, DNode* p):data(d), next(n), prev(p) {}

DLinkedList::DLinkedList()
{
	tail = nullptr;
	head = nullptr;
}
DLinkedList::DLinkedList(const DLinkedList& list)
{
	head = copy(list.head);
	tail = last();
}
DLinkedList::~DLinkedList()
{
	del();
}
void DLinkedList::add_last(int d)
{
	if (tail == nullptr)
	{
		head = new DNode(d);
		tail = head;
		return;
	}
	tail->next = new DNode(d, nullptr, tail);
	tail = tail->next;
}
void DLinkedList::add_after_firs(int d)
{
	if (head == nullptr)
	{
		head = new DNode(d);
		tail = head;
		return;
	}
	DNode* t;
	t = new DNode(d, head->next, head);
	if (head->next != nullptr)
	{
		head->next->prev = t;
	}
	head->next = t;
	tail = last();
}
void DLinkedList::del_last()
{
	if (tail == nullptr)
	{
		return;
	}
	DNode* t;
	t = tail;
	if (tail == head)
	{
		head = nullptr;
		tail = nullptr;
		delete t;
		return;
	}
	t = t->prev;
	tail = t;
	delete t->next;
	t->next = nullptr;
}
void DLinkedList::del_second()
{
	if (getlenght() == 1)
	{
		return;
	}
	DNode* t;
	t = head->next;
	if (t->next == nullptr)
	{
		head->next = nullptr;
		delete t;
		return;
	}
	DNode* p;
	p = t->next;
	p->prev = head;
	head->next = p;
	delete t;
}
void DLinkedList::insertp(int n, int d)
{
	if (!indexValid(n))
	{
		return;
	}
	if (n == 0)
	{
		head->prev = new DNode(d, head, nullptr);
		head = head->prev;
		return;
	}
	if (n == getlenght())
	{
		tail->next = new DNode(d, nullptr, tail);
		tail = tail->next;
		return;
	}
	DNode* t;
	t = head;
	for (int i = 0; i < n; i++)
	{
		t = t->next;
	}
	DNode* p = new DNode(d, t, t->prev);
	t->prev->next = p;
	t->prev = p;
}
void DLinkedList::delp(int n)
{
	if (!indexValid(n))
	{
		return;
	}
	if (n == 0)
	{
		DNode* t = head;
		head = head->next;
		head->prev = nullptr;
		delete t;
		return;
	}
	if (n - 1 == getlenght())
	{
		DNode* t = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete t;
		return;
	}
	DNode* t;
	t = head;
	for (int i = 0; i < n - 1; i++)
	{
		t = t->next;
	}
	DNode* p;
	p = t->next;
	t->next = p->next;
	if (p->next != nullptr)
	{
		p->next->prev = t;
	}
	delete p;
	tail = last();
}
void DLinkedList::reverse()
{
	if (head == nullptr)
	{
		return;
	}
	if (getlenght() == 1)
	{
		return;
	}
	DNode* t = head;
	while (t->next != nullptr)
	{
		t->prev = t->next;
		t = t->next;
	}
	t->prev = nullptr;
	t = head;
	DNode* p = nullptr;
	
	while (t != nullptr)
	{
		t->next = p;
		p = t;
		t = t->prev;
	}
	t = head;
	head = tail;
	tail = t;
}
void DLinkedList::remove_if(bool (*fnc)(DNode*))
{
	DNode* t;
	t = head;
	int i = 0;
	while (t != nullptr)
	{
		if (fnc(t))
		{
			t = t->next;
			delp(i);
		}
		else
		{
			++i;
			t = t->next;
		}
	}
}
DNode* DLinkedList::last()
{
	DNode* t;
	t = head;
	while (t->next != nullptr)
	{
		t = t->next;
	}
	return t;
}
int DLinkedList::getlenght()
{
	DNode* t;
	t = head;
	int i = 0;
	while (t != nullptr)
	{
		++i;
		t = t->next;
	}
	return i;
}
bool DLinkedList::indexValid(int n)
{
	return n >= 0 && n < getlenght();
}
void DLinkedList::print()
{
	if (getlenght() == 0)
	{
		std::cout << "There's nothing here" << std::endl;
	}
	else
	{
		DNode* t;
		t = head;
		while (t != nullptr)
		{
			std::cout << t->data << "\t";
			t = t->next;
		}
		std::cout << std::endl;
		t = tail;
		while (t != nullptr)
		{
			std::cout << t->data << "\t";
			t = t->prev;
		}
	}
}
void DLinkedList::del()
{
	if (getlenght() == 0)
	{
		return;
	}
	else
	{
		DNode* t;
		t = head;
		while (t != nullptr)
		{
			DNode* h;
			h = t;
			t = t->next;
			delete h;
		}
		head = t;
		tail = nullptr;
	}
}
DLinkedList& DLinkedList::operator=(const DLinkedList& list)
{
	del();
	head = copy(list.head);
	tail = last();
	return *this;
}

DNode* copy(DNode* x)
{
	DNode* t;
	t = nullptr;
	if (x != nullptr)
	{
		t = new DNode(x->data, copy(x->next));
		if (t->next != nullptr)
		{
			t->next->prev = t;
		}
	}
	return t;
}