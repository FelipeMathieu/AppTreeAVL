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
		root = insert(e, root);
	}
	else
	{
		root = new Node();
		root->element = e;
	}
}

Node *Tree::insert(int e, Node *leaf)
{
	if (leaf == NULL)
	{
		leaf = new Node();
		leaf->element = e;
		return leaf;
	}

	if (e >= leaf->element)
	{
		leaf->right = insert(e, leaf->right);
		leaf = balance(leaf);
	}
	else if (e < leaf->element)
	{
		leaf->left = insert(e, leaf->left);
		leaf = balance(leaf);
	}

	return leaf;
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

Node *Tree::balance(Node *t)
{
	int bFactor;
	Node *aux;

	if (t != NULL)
	{
		balance(t->left);
		balance(t->right);
		bFactor = difHeight(t);

		if (bFactor > 1)
		{
			if (t->left != NULL)
			{
				aux = t->left;
			}
			else
			{
				aux = NULL;
			}
			if (difHeight(aux) < 0)
			{
				t = leftRightRotate(t);
			}
			else
			{
				t = rightRotate(t);
			}
		}
		else if (bFactor < -1)
		{
			if (t->right != NULL)
			{
				aux = t->right;
			}
			else
			{
				aux = NULL;
			}
			if (difHeight(aux) > 0)
			{
				t = rightLeftRotate(t);
			}
			else
			{
				t = leftRotate(t);
			}
		}
	}

	return t;
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

	/*t->height = max(height(t->left), height(t->right)) + 1;
	q->height = max(height(q->left), height(q->right)) + 1;*/

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

	/*t->height = max(height(t->left), height(t->right)) + 1;
	q->height = max(height(q->left), height(q->right)) + 1;*/

	cout << "Simple Left Rotate." << endl;

	return q;
}

Node *Tree::leftRightRotate(Node *t)
{
	t->left = leftRotate(t->left);
	return rightRotate(t);
}

Node *Tree::rightLeftRotate(Node *t)
{
	t->right = rightRotate(t->right);
	return leftRotate(t);
}