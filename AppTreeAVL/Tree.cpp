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

		balanceTree(root);
	}
	else if (e < aux->element)
	{
		aux->left = new Node();
		aux->left->element = e;

		balanceTree(root);
	}
}

void Tree::search(int e, Node *aux)
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

int Tree::height(Node *t)
{
	int h = 0, leftHeight, rightHeight, maxHeight;

	if (t != NULL)
	{
		leftHeight = height(t->left);
		rightHeight = height(t->right);
		maxHeight = max(leftHeight, rightHeight);
		h = maxHeight + 1;
	}

	return h;
}

int Tree::difHeight(Node *t)
{
	int x, y, z;
	
	x = height(t->left);
	y = height(t->right);
	z = x - y;

	return z;
}

void Tree::balanceTree(Node *t)
{
	if (t != NULL)
	{
		balanceTree(t->left);
		balanceTree(t->right);
		balance(t);
	}
}

void Tree::balance(Node *t)
{
	int bFactor, bFactor2;
	Node *aux = NULL;

	if (t != NULL)
	{
		bFactor = difHeight(t);

		if (bFactor == 2)
		{
			if (t->left != NULL)
			{
				bFactor2 = difHeight(t->left);
			}
			else
			{
				bFactor2 = 0;
			}
			if (bFactor2 == -1)
			{
				aux = t->left;
				t->left = leftRotate(aux);
				root = rightRotate(root);
			}
			else
			{
				root = rightRotate(root);
			}
		}

		if (bFactor == -2)
		{
			if (t->right != NULL)
			{
				bFactor2 = difHeight(t->right);
			}
			else
			{
				bFactor2 = 0;
			}
			if (bFactor2 == 1)
			{
				aux = t->right;
				t->right = rightRotate(aux);
				root = leftRotate(root);
			}
			else
			{
				root = leftRotate(root);
			}
		}
	}
}

void Tree::display(Node *t, int lvl)
{
	int i;

	if (t != NULL)
	{
		display(t->right, lvl + 1);
		cout << endl;
		if (t == root)
		{
			cout << "Root -> ";
		}
		for (i = 0; i < lvl && t != root; i++)
		{
			cout << "        ";
		}
		cout << t->element;
		display(t->left, lvl + 1);
	}
}

Node *Tree::rightRotate(Node *t)
{
	Node *q;
	Node *aux;

	q = t->left;
	aux = q->right;
	q->right = t;
	t->left = aux;

	cout << "Simple Right Rotate." << endl;

	return q;
}

Node *Tree::leftRotate(Node *t)
{
	Node *q;
	Node *aux;

	q = t->right;
	aux = q->left;
	q->left = t;
	t->right = aux;

	cout << "Simple Left Rotate." << endl;

	return q;
}