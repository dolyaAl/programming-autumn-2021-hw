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
	void insertptr(int d, int n);
	void delptr(int n);
	void reverse();
	void remove_if(bool (*fnc)(Node*));

	void insert(int n, Node*t);
	int getlenght();
	void add_first(int d);
	bool indexValid(int n);
	void print();
};