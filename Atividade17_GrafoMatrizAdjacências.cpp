#include <iostream>
#include <clocale>

using namespace std;

const int TAM = 10;

int vertice[TAM];
int adj[TAM][TAM];
int n_vertices=0;


void iniciaGrafo() {
    for (int i=0; i<TAM; i++)
        for (int j=0; j<TAM; j++) {
            adj[i][j]=0;
        }
}

void insere(int valor) {
    if (n_vertices<TAM) {
        for (int i=0; i<n_vertices; i++)
            if (vertice[i]==valor) {
                cout << "Vertice repetido" << endl;
                return;
            }
        vertice[n_vertices]=valor;
        n_vertices++;
    } else cout << "Não há mais espaço para vértices" << endl;
}

void insereAresta(int orig, int dest) {
    int i=0;
    int j=0;

    while (i<n_vertices && vertice[i]!=orig)
        i++;
    if (i==n_vertices) {
        cout << "Nao existe no de origem\n";
        return;
    }
    while (j<n_vertices && vertice[j]!=dest)
        j++;
    if (j==n_vertices) {
        cout << "Nao existe no de destino\n";
        return;
    }
    adj[i][j]=1;
    adj[j][i]=1;
}

void removeAresta(int orig, int dest) {
    int i=0;
    int j=0;

    while (i<n_vertices && vertice[i]!=orig)
        i++;
    if (i==n_vertices) {
        cout << "Nao existe no de origem\n";
        return;
    }
    while (j<n_vertices && vertice[j]!=dest)
        j++;
    if (j==n_vertices) {
        cout << "Nao existe no de destino\n";
        return;
    }
    if (adj[i][j]==0)
        cout << "Não existe aresta!\n";
    else adj[i][j]=0;
}

void imprimeGrafo() {

    cout << "\nGrafo e: " << endl;
    for (int i=0; i<n_vertices; i++) {
        cout << vertice[i] << " -> " ;
        for (int j=0; j<n_vertices; j++)
            if (adj[i][j]!=0)
                cout << "<" << vertice[i] << "," << vertice[j] << "> ";
        cout << endl;
    }
}


int main() {

    insere(10);
    insere(20);
    insere(30);
    insere(40);
    insere(50);
    insereAresta(10,40);
    insereAresta(10,50);
    removeAresta(10,40);
    imprimeGrafo();

}
