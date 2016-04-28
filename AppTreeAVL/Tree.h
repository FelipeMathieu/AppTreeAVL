#pragma once

#include <iostream>
#include<algorithm>

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
	void balance(Node *t);

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
	int height(Node *t);
	int difHeight(Node *t);
	void balanceTree(Node *t);
	void display(Node *t, int lvl);
	Node *rightRotate(Node *t);
	Node *leftRotate(Node *t);
};

