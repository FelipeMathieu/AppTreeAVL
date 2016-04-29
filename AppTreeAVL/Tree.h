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
	Node *insert(int e, Node *leaf);

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
	Node *balance(Node *t);
	void display(Node *t, int lvl);
	Node *rightRotate(Node *t);
	Node *leftRotate(Node *t);
	Node *leftRightRotate(Node *t);
	Node *rightLeftRotate(Node *t);
};

