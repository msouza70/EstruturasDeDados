#include <iostream>

using namespace std;

const int TAM=10;

struct no {
    int destino;
    struct no *prox;
};

struct no *arestas[TAM];

int vertice[TAM];

int n_vertices=0;

void iniciaGrafo() {
    for (int i=0; i<TAM; i++)
        arestas[i]=NULL;
};

void insere(int valor) {
    if (n_vertices<TAM) {
        for (int i=0; i<n_vertices; i++)
            if (vertice[i]==valor) {
                cout << "Vertice repetido" << endl;
                return;
            }
        vertice[n_vertices]=valor;
        n_vertices++;
        cout << "Vertice inserido" << endl;
    } else cout << "Não ha mais espaço para vertices" << endl;
}


void insere_aresta(int orig, int dest) {
    int i=0;
    int j=0;
    struct no *atual, *anterior, *novo;

    while (i<n_vertices && vertice[i]!=orig)
        i++;
    if (i==n_vertices) {
        cout << "Nao existe vertice de origem" << endl;
        return;
    }
    while (j<n_vertices && vertice[j]!=dest)
        j++;
    if (j==n_vertices) {
        cout << "Nao existe vertice de destino" << endl;
        return;
    }
    atual = arestas[i];
    while (atual!=NULL) {
        if (atual->destino == dest) {
            cout << "Aresta repetida" << endl;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    novo = new (struct no);
    novo->destino = dest;
    novo->prox = NULL;
    if (arestas[i] == NULL)
        arestas[i] = novo;
    else anterior->prox = novo;
    cout << "Aresta inserida" << endl;
}

void remove_aresta(int orig, int dest) {
    int i=0;
    int j=0;
    struct no *atual, *anterior;

    while (i<n_vertices && vertice[i]!=orig)
        i++;
    if (i==n_vertices) {
        cout << "Nao existe vertice de origem" << endl;
        return;
    }
    while (j<n_vertices && vertice[j]!=dest)
        j++;
    if (j==n_vertices) {
        cout << "Nao existe vertice de destino" << endl;
        return;
    }
    atual = arestas[i];
    while (atual!=NULL) {
        if (atual->destino = dest) {
            if (arestas[i] == atual)
                arestas[i] = arestas[i]->prox;
            else anterior->prox = atual->prox;
            delete (atual);
            cout << "Aresta apagada" << endl;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    cout << "Aresta nao encontrada" << endl;
}

void imprimeGrafo() {

     struct no *atual;

     for (int i=0;i<n_vertices;i++) {
         cout << vertice[i] << " -> " ;
         for (atual=arestas[i];atual!=NULL;atual=atual->prox)
            cout << "<" << vertice[i] << "," << atual->destino << "> ";
         cout << endl;
     }
}

int main() {

    insere(10);
    insere(20);
    insere(30);
    insere(40);
    insere(50);
    insere_aresta(10,40);
    insere_aresta(10,50);
    remove_aresta(10,40);
    imprimeGrafo();

}



