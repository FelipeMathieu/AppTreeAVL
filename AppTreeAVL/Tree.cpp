#include "Tree.h"

Tree::Tree()
{
	this->element = NULL;
	this->left = NULL;
	this->right = NULL;
}
Tree::~Tree()
{
}

void Tree::insert(int e, Tree *leaf)
{
	Tree *aux = new Tree();

	if (leaf == NULL)
	{
		leaf = new Tree();
		leaf->element = e;
		leaf->left = NULL;
		leaf->right = NULL;
	}
	else
	{
		while (leaf != NULL)
		{
			aux = leaf;
			if (e < leaf->element)
			{
				leaf = leaf->left;
			}
			else if (e >= leaf->element)
			{
				leaf = leaf->right;
			}
		}

		if (e >= aux->element)
		{
			aux->right = new Tree();
			aux->right->element = e;
			aux->right->right = NULL;
			aux->right->left = NULL;
		}
		else if (e < aux->element)
		{
			aux->left = new Tree();
			aux->left->element = e;
			aux->left->left = NULL;
			aux->left->right = NULL;
		}
	}
}

void Tree::search(int e, Tree *aux)
{
	if (aux != NULL)
	{
		if (e == aux->element)
		{
			cout << "Elemento " << e << " existe!" << endl;
			return;
		}
		else if(e < aux->element)
		{
			search(e, aux->left);
		}
		else
		{
			search(e, aux->right);
		}
	}
	else
	{
		cout << "Elemento nao existe!" << endl;
	}
}