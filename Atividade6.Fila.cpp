#include <iostream>

using namespace std;

struct no {
    int dado;
    struct no* prox;
};

struct no *inicioF = NULL, *fimF = NULL;

void enqueue(int valor)
{
    struct no* novo;

    novo = new (struct no);
    novo->dado = valor;
    novo->prox = NULL;
    if (fimF == NULL) {
        fimF = novo;
        inicioF = novo;
    } else {
        fimF->prox = novo;
        fimF = novo;
    }
    cout << "Elemento inserido" << endl;
}

void dequeue()
{
    struct no* apaga;

    if (inicioF == NULL) {
        cout << "Fila vazia\n";
        return;
    }
    apaga = inicioF;
    inicioF = inicioF->prox;
    if (inicioF == NULL)
        fimF = NULL;
    delete (apaga);
}

void inicio()
{
    if (inicioF == NULL) {
        cout << "Fila vazia" << endl;
        return;
    }
    cout << "Topo da fila e " << inicioF->dado << endl;
}

void imprime()
{
    struct no* atual;

    if (inicioF == NULL) {
        cout << "Fila vazia" << endl;
        return;
    }
    cout << "Fila e: ";
    atual = inicioF;
    while (atual != NULL) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    inicio();
    imprime();
    dequeue();
    inicio();
    dequeue();
    inicio();
}
