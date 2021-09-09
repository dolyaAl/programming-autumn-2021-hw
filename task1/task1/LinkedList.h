#pragma once

struct Node
{
	int data;
	Node* next;
	Node(int d = 0, Node* n = nullptr);
};

struct LinkedList
{
	Node* head;
	LinkedList();

	Node* last();
	Node* prelast();
	Node* get_ptr(int n = 0);
	void add_after_first(int d);
	void add_last(int d);
	void del_last();
	int getlenght();
	void add_first(int d);
	bool indexValid(int n);
	void print();
};