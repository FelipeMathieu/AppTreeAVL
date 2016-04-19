#include "Tree.h"

void main()
{
	Tree *A = NULL;

	A = new Tree();

	A->insert(5, A);
	A->insert(7, A);
	A->insert(3, A);
	A->search(5, A);
}