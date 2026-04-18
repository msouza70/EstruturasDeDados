#include <iostream>

using namespace std;

struct no {
    int dado;
    struct no* prox;
};

struct no* pilha = NULL;

void push(int valor)
{
    struct no* novo;

    novo = new (struct no);
    novo->dado = valor;
    novo->prox = pilha;
    pilha = novo;
    cout << "Elemento inserido" << endl;
}

void pop()
{
    struct no* apaga;

    if (pilha == NULL) {
        cout << "Pilha vazia" << endl;
        return;
    }
    apaga = pilha;
    pilha = pilha->prox;
    delete (apaga);
    cout << "Elemento removido" << endl;
}

void topo()
{
    if (pilha == NULL) {
        cout << "Pilha vazia" << endl;
        return;
    }
    cout << "Topo da pilha e " << pilha->dado << endl;
}

void imprime()
{
    struct no* atual;

    if (pilha == NULL) {
        cout << "Pilha vazia" << endl;
        return;
    }
    cout << "Pilha e: ";
    atual = pilha;
    while (atual != NULL) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    topo();
    imprime();
    pop();
    topo();
    pop();
    topo();
}
