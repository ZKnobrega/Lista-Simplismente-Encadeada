#include <iostream>
#include <locale>
#include <stdlib.h>

using namespace std;

typedef struct no
{
	int valor;
	struct no *prox;
} no;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int cont;
	no *lista;
	lista = NULL;
	no *novo;

	int num;
	int sai = 0; // Usado para sair do Programa

	no *aux; //usado em excluir e pesquisar
	int op;
inicio:
	cout << "Escolha a opção desejada: \n1 - Inserir." << endl;
	cout << "2 - Excluir." << endl;
	cout << "3 - Listar." << endl;
	cout << "4 - limpar." << endl;
	cout << "5 - Sair." << endl;
	cout << "Opção : ";
	cin >> op;
	switch (op)
	{
	case 1:
		//inserir;

		cout << "Digite um valor inteiro para inserir na lista: ";
		cin >> num;
		novo = (no *)malloc(sizeof(no)); //O ponteiro 'novo' recebe o local indicado por malloc(); do tamanho definido por sizeof();
		novo->valor = num;
		novo->prox = lista; //Lista inicialmente vale NULL, depois de ser inserido algum valor 'lista' vai ser igual ao ptr anterior
		lista = novo;
		cout << "\n\n";
		goto inicio;
	case 2:
		//excluir;
		int ind;
		no *morta;
		aux = novo;
		cout << "Digite o índice do valor a ser excluido: ";
		cin >> ind;
        if (ind !=1)
        {
            for (int i = 0; i < ind - 2; i++)
            {
                aux = aux->prox;
            }
            morta = aux->prox;
            aux->prox = morta->prox;
            cout << "\n\n";
        }
        else
        {
            novo = aux -> prox;
        }

		goto inicio;

		break;
	case 3:
		//listar();

		if (lista == NULL)
		{
			cout << "Lista vazia!" << endl;
		}
		else
		{
			cout << "\n\n"
				 << endl;
			aux = novo;
			int cont = 0;
			do
			{
				cout << cont + 1 << "º " << aux->valor << " | ";
				aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
				cont++;
			} while (aux != NULL);
			cout << "\n\n";
			cout << "A lista possui " << cont << " valores." << endl;
		}
		cout << "\n\n";
		goto inicio;
		break;
	case 4:
		//limpar;
		lista = NULL; //perde-se o local do ultimo valor informado
		cout << "\n\n";
		goto inicio;
		break;
	case 5:
		//Sair
		cout << "Obrigado Por usar o Programa.";

		break;
	default:
		cout << "Opção inválida!" << endl;
		goto inicio; //
	}
}
