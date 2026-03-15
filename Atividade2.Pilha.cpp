/* As rotinas que imprimem mensagens na tela estão comentadas pois
   elas são usadas na função verifica. */

#include <iostream>

using namespace std;

const int TAM = 10;
int pilha[TAM];
int topoP=-1;

void push(int valor) {
    if (topoP==TAM-1) {
//        cout << "Pilha cheia" << endl;
        return;
    }
    topoP++;
    pilha[topoP]=valor;
//    cout << "Elemento inserido" << endl;
}

bool vazia() {
    if (topoP==-1)
        return true;
    else return false;
}

void pop() {
    if (vazia()) {
//        cout << "Pilha vazia" << endl;
        return;
    }
    topoP--;
//    cout << "Elemento removido" << endl;
}

void topo() {
    if (vazia()) {
        cout << "Pilha vazia" << endl;
        return;
    }
    cout << "Topo da pilha: " << pilha[topoP] << endl;
}

//Bônus
void verifica() {
    string expr = "(a+b)(";
    int tamanho = expr.size();
    for (int i=0; i<tamanho; i++) {
        if (expr[i]=='(')
            push('(');
        if (expr[i]==')') {
            if (vazia()) {
                cout << "Expressao Errada" << endl;
                return;
            }
            pop();
        }
    }
    if (vazia())
        cout << "Expressao Correta" << endl;
    else cout << "Expressao Errada" << endl;

}

int main() {
    verifica();
}
