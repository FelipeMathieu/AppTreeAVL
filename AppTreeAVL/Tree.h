//Class Tree

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
	void insertNode(int e, Node *leaf);
	Node *removeElement(Node *t, int e);

public:
	Tree();
	~Tree();

	void insert(int e);
	int search(int e, Node *aux);
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
	void remove(Node *t, int e);
};

