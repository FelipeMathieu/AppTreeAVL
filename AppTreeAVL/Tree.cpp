#include "Tree.h"

Tree::Tree()
{
	this->root = NULL;
}

Tree::~Tree()
{
}

void Tree::insert(int e)
{
	if (this->root != NULL)
	{
		this->insert(e, this->root);
	}
	else
	{
		this->root = new Node();
		this->root->element = e;
	}
}

void Tree::insert(int e, Node *leaf)
{
	Node *aux = NULL;
	

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
			aux->right = new Node();
			aux->right->element = e;
		}
		else if (e < aux->element)
		{
			aux->left = new Node();
			aux->left->element = e;
		}
}

void Tree::search(int e, Tree *aux)
{
	if (aux != NULL)
	{
		if (e == aux->root->element)
		{
			cout << "Elemento " << e << " existe!" << endl;
			return;
		}
		else if(e < aux->root->element)
		{
			search(e, (Tree *)aux->root->left);
		}
		else
		{
			search(e, (Tree *)aux->root->right);
		}
	}
	else
	{
		cout << "Elemento nao existe!" << endl;
	}
}

void Tree::printPreOrder(Node *t)
{
	if (t != NULL)
	{
		cout << t->element << " |";
		printPreOrder(t->left);
		printPreOrder(t->right);
	}
}

void Tree::printInOrder(Node *t)
{
	if (t != NULL)
	{
		printInOrder(t->left);
		cout << t->element << " |";
		printInOrder(t->right);
	}
}

void Tree::printPostOrder(Node *t)
{
	if (t != NULL)
	{
		printPostOrder(t->left);
		printPostOrder(t->right);
		cout << t->element << " |";
	}
}