#include "Tree.h"

void main()
{
	Tree *A = new Tree();

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
		cout << "6-> Procurar elemento;" << endl;
		cout << "7-> Display;" << endl;
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
			cout << endl;
			break;
		case 3:
			A->printPostOrder(A->Root());
			cout << endl;
			break;
		case 4:
			A->printInOrder(A->Root());
			cout << endl;
			break;
		case 5:
			i = 1;
			break;
		case 6:
			cout << endl;
			cout << "Informe o elemento: ";
			cin >> e;
			A->search(e, A->Root());
			break;
		case 7:
			cout << endl;
			A->display(A->Root(), 1);
			cout << endl << endl << endl;
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