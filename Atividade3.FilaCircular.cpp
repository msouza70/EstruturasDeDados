#include <iostream>
using namespace std;

const int TAM = 4;

int fila[TAM];
int inicioF=0, fimF=0;
int contador=0;

bool vazia() {
    if (contador==0)
        return true;
    else return false;
}

void enqueue(int valor)
{
   if (contador==TAM) {
      cout << "Fila cheia" << endl;
      return;
   }
   contador++;
   fila[fimF]=valor;
   if (fimF==TAM-1)
      fimF=0;
    else fimF++;
    cout << "Elemento inserido" << endl;
}

void dequeue()
{
     if (vazia()) {
        cout << "Fila vazia" << endl;
        return;
     };
     contador--;
     if (inicioF==TAM-1)
        inicioF=0;
    else inicioF++;
    cout << "Elemento removido" << endl;
}

void inicio()
{
     if (vazia())
         cout << "Fila vazia" << endl;
     else cout << "Inicio da fila: " << fila[inicioF] << endl;
}

void imprime()
{
     int i, j;
     if (vazia()) {
        cout << "Fila vazia" << endl;
        return;
     }
     cout << "Fila: ";
     i=inicioF;
     for (j=0; j< contador; j++) {
        cout << fila[i] << " ";
        if (i==TAM-1)
           i=0;
           else i++;
     }
     cout << endl;
}

// Bônus
// Esta função só existe em uma deque, na qual é permitido imprimir o
// valor que está no fim da fila
void fim()
{
     if (vazia()) {
         cout << "Fila vazia" << endl;
         return;
     }
     if (fimF==0)
         cout << "Fim da fila e " << fila[TAM-1] << endl;
     else cout << "Fim da fila e " << fila[fimF-1] << endl;
}

// Bônus
// Esta função só existe em uma deque, na qual é permitido remover o
// valor que está no fim da fila
void dequeueEnd()
{
     if (vazia()) {
        cout << "Fila vazia" << endl;
        return;
     };
     contador--;
     if (fimF==0)
        fimF=TAM-1;
    else fimF--;
    cout << "Elemento removido do fim" << endl;
}

// Bônus
// Esta função só existe em uma deque, na qual é permitido inserir um
// valor no início da fila
void enqueueFront(int valor) {
    if (contador==TAM) {
        cout << "Fila cheia" << endl;
        return;
    }
    contador++;
    if (inicioF==0)
        inicioF=TAM-1;
    else inicioF--;
    fila[inicioF]=valor;
    cout << "Elemento inserido no inicio" << endl;
}

int main()
{
    imprime();
    inicio();
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    inicio();
    imprime();
    dequeue();
    enqueue(4);
    inicio();
    imprime();
    dequeue();
    inicio();
    imprime();
    return 0;
}

