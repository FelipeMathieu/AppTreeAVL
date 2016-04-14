#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
}

void Tree::insert(int e, Tree *leaf)
{
	if (e < leaf->element)
	{
		if (leaf->left != NULL)
		{
			insert(e, leaf->left);
		}
		else
		{
			leaf->left = new Tree();
			leaf->left->element = e;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (e >= leaf->element)
	{
		if (leaf->right != NULL)
		{
			insert(e, leaf->right);
		}
		else
		{
			leaf->right = new Tree();
			leaf->right->element = e;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

void Tree::printTree(Tree *r, int i)
{
	if (r == NULL)
	{
		cout << "Arvore vazia!" << endl;
		return;
	}
	else
	{
		printTree(r->left, i);

		i++;
		cout << i << ' ' << r->element << endl;
		printTree(r->right, i);
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