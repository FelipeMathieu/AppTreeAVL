#pragma once

#include <iostream>

using namespace std;

typedef struct Node
{
	int element;
	Node *right, *left;
};

class Tree
{

private:

	Node *root;
	void insert(int e, Node *leaf);

public:
	Tree();
	~Tree();

	void insert(int e);
	void search(int e, Node *aux);
	void printPreOrder(Node *t);
	void printInOrder(Node *t);
	void printPostOrder(Node *t);
	Node *Root()
	{
		return root;
	}
};

