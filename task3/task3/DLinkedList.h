#pragma once

#pragma once

struct DNode
{
	int data;
	DNode* next;
	DNode* prev;
	DNode(int d = 0, DNode* n = nullptr, DNode* p = nullptr);
};

struct DLinkedList
{
	DNode* head;
	DNode* tail;

	DLinkedList();
	DLinkedList(const DLinkedList& list);
	~DLinkedList();

	void add_last(int d);
	void add_after_firs(int d);
	void del_last();
	void del_second();
	void insertp(int n = 0, int d = 0);
	void delp(int n = 0);
	void reverse();
	void remove_if(bool (*fnc)(DNode*));

	DNode* last();

	int getlenght();
	bool indexValid(int n);
	void print();
	void del();

	DLinkedList& operator= (const DLinkedList& list);
};

DNode* copy(DNode* x);
