#pragma once

#include <iostream>

using namespace std;

class Tree
{
private:

	int element;
	Tree *root, *right, *left;

public:
	Tree();
	~Tree();

	void insert(int e, Tree *leaf);
	void search(int e, Tree *aux);
	void printTree(Tree *r, int i);
};

