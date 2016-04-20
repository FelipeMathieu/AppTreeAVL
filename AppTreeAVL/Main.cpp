#include "Tree.h"

void main()
{
	Tree *A = new Tree();

	A->insert(5);
	A->insert(7);
	A->insert(3);
	A->search(5, A);
	cout << endl;
	cout << "Imprime em PreOrder:" << endl;
	A->printPreOrder(A->Root());
	cout << endl;
	cout << "Imprime em InOrder:" << endl;
	A->printInOrder(A->Root());
	cout << endl;
	cout << "Imprime em PostOrder:" << endl;
	A->printPostOrder(A->Root());
	cout << endl;

	int i = 0;
	int option = 0;
	int e = 0;
	char p;

	do
	{
		cout << "Deseja efetuar qual operacao:" << endl;
		cout << "1-> Inserir novo elemento;" << endl;
		cout << "2-> Imprimir em PreOrder;" << endl;
		cout << "3-> Imprimir em PostOrder;" << endl;
		cout << "4-> Imprimir em InOrder;" << endl;
		cout << "5-> Sair do programa;" << endl;
		cin >> option;
		switch (option)
		{
		default:
			break;
		case 1:
			cout << "Informe o elemento: ";
			cin >> e;
			A->insert(e);
			break;
		case 2:
			A->printPreOrder(A->Root());
			break;
		case 3:
			A->printPostOrder(A->Root());
			break;
		case 4:
			A->printInOrder(A->Root());
			break;
		case 5:
			i = 1;
			break;
		}
		if (i != 1)
		{
			cout << "Deseja efetuar mais alguma operacao (S/N): ";
			cin >> p;
			switch (p)
			{
			default:
				break;
			case 's':
				system("cls");
				break;
			case 'S':
				system("cls");
				break;
			case 'N':
				i = 1;
				break;
			case 'n':
				i = 1;
				break;
			}
		}
	} while (i == 0);
}