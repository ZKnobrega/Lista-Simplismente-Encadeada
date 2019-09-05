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
	no *lista;
	lista = NULL;
	no *novo;
	no *posi;

	int num, posicao;

	no *aux; //usado em excluir e pesquisar e inserir por posição.
	int op;
	int cont = 0;
inicio:
	cout << "Escolha a opção desejada: \n1 - Inserir." << endl;
	cout << "2 - Excluir." << endl;
	cout << "3 - Listar." << endl;
	cout << "4 - limpar." << endl;
	cout << "5 - Sair." << endl;
	cout << "6 - Inserir por Posição." << endl;
	cout << "Opção : ";
	cin >> op;
	switch (op)
	{
        cont = 0;
        do
			{
				cout << cont + 1 << "º " << aux->valor << endl;
				aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
				cont++;
			} while (aux != NULL);

	case 1:
		//inserir;

		cout << "Digite um valor inteiro para inserir na lista: ";
		cin >> num;
		novo = (no *)malloc(sizeof(no)); //O ponteiro 'novo' recebe o local indicado por malloc(); do tamanho definido por sizeof();
		novo -> valor = num;
		novo -> prox = lista; //Lista inicialmente vale NULL, depois de ser inserido algum valor 'lista' vai ser igual ao ptr anterior
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
        if (ind !=1&& ind <= cont)
        {
            for (int i = 0; i < ind - 2; i++)
            {
                aux = aux->prox;
            }
            morta = aux->prox;
            aux->prox = morta->prox;
            cout << "\n\n";
        }
        else if (ind == 1)
        {
            novo = aux -> prox;
        }
        else
        {
            cout << "Opção Invalida!!\n";
        }

		goto inicio;

		break;
	case 3:
		//listar

		if (lista == NULL)
		{
			cout << "Lista vazia!" << endl;
		}
		else
		{
			cout << "\n\n"
				 << endl;
			aux = lista;
			int cont = 0;
			do
			{
				cout << cont + 1 << "º " << aux->valor << endl;
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


    case 6:
        // inserir por posição
        aux = lista;
        cont = 0;
        do
			{
				aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
				cont++;
			} while (aux != NULL);
        no *anterior;
        cout << "Informe o Valor a ser inserido: \n";
		cin >> num;
        int posicao;
        cout << "Informe a posição a ser inserida: \n";
        cin >> posicao;
        novo = (no *)malloc(sizeof(no)); //O ponteiro 'novo' recebe o local indicado por malloc(); do tamanho definido por sizeof();
		novo->valor = num;

        if (posicao > 1 && posicao <= cont)
        {
            aux = lista;
            anterior = lista;
                for (int i=0; i<posicao; ++i)
                {
                    aux = aux -> prox;
                }

           // cout << aux->valor << endl;


            for (int i=0; i<posicao-1; ++i)
                {
                    anterior = anterior -> prox;
                }
            // cout << anterior->valor << endl;

            anterior -> prox = novo;

            if (posicao-1 == cont)
            {

                novo -> prox =NULL;
            }
            else
            {
                novo -> prox = aux;
            }


            //novo->prox = lista; //Lista inicialmente vale NULL, depois de ser inserido algum valor 'lista' vai ser igual ao ptr anterior
            //lista = novo;
        }

        else if(posicao == 1){
            novo -> valor = num;
            novo -> prox = lista; //Lista inicialmente vale NULL, depois de ser inserido algum valor 'lista' vai ser igual ao ptr anterior
            lista = novo;
        }
        else
            {
                cout << "Valor Invalido"<< endl;
            }
		goto inicio;
        break;


	default:
		cout << "Opção inválida!" << endl;

		goto inicio;
	}
}
