#include <iostream>

using namespace std;

const int TAM = 10;

char vertice[TAM];
int adj[TAM][TAM];
int n_vertices=0;

bool visitado[TAM];

// No da fila
struct noF {
    int dado;
    struct noF *prox;
};

// Ponteiros para o inicio e para o fim da fila
struct noF *inicio=NULL, *fim=NULL;

// Verifica se a fila esta vazia
bool vazia() {
    if (inicio==NULL)
        return true;
    else return false;
}

// Insere um novo valor no fim da fila
void enqueue(int valor) {
    struct noF *novo;

    novo = new(struct noF);
    novo->dado = valor;
    novo->prox = NULL;
    if (fim == NULL) {
        fim = novo;
        inicio = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
}

// Remove e retorna valor no inicio da fila
int dequeue() {
    struct noF *apaga;
    int valor;

    apaga = inicio;
    valor=inicio->dado;
    inicio = inicio->prox;
    if (inicio==NULL)
        fim=NULL;
    delete(apaga);
    return valor;
}

void zeraVetorVisitado() {
    for (int i=0; i<TAM; i++)
        visitado[i] = false;
}

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

void BFS(int inicial) {
    int v;
    visitado[inicial] = true;
    cout << vertice[inicial] << " ";
    enqueue(inicial);
    
    while (!vazia()) {
        v = dequeue();
        for (int a=0; a<TAM; a++)
            if (adj[v][a]==1 && visitado[a]==false) {
                cout << vertice[a] << " ";
                visitado[a] = true;
                enqueue(a);
            }
    }
}

void DFS(int vert) {
    visitado[vert] = true;
    cout << vertice[vert] << " ";
    for (int a=0; a<TAM; a++)
        if (adj[vert][a]==1 && visitado[a]==false)
            DFS(a);
}


int main() {
    iniciaGrafo();
    insere('A');
    insere('B');
    insere('C');
    insere('D');
    insere('E');
    insere('F');
    insere('G');
    insere('X');
    insere('Y');
    insere('Z');
    insereAresta('A','E');
    insereAresta('A','B');
    insereAresta('E','G');
    insereAresta('G','F');
    insereAresta('D','C');
    insereAresta('E','D');
    insereAresta('B','X');
    insereAresta('B','Y');
    insereAresta('B','Z');
    imprimeGrafo();
    zeraVetorVisitado();
    cout << "Percurso em largura (BFS)" << endl;
    BFS(0);
    cout << endl;
    zeraVetorVisitado();
    cout << "Percurso em comprimento (DFS)" << endl;
    DFS(0);
    return 0;
}

