#include <iostream>

using namespace std;

const int TAM = 100;

int tabela[TAM];
int colisoes;

void inicia()
{
    for (int i = 0; i < TAM; i++)
        tabela[i] = -1;
}

int espalha(int chave)
{ // h(chave) = chave%TAM
    return chave % TAM;
}

int reespalha(int pos)
{ // rh(pos) = (pos+1)%TAM
    return (pos + 1) % TAM;
}

void insere(int chave)
{
    int pos;
    int cont = 0;

    pos = espalha(chave);
    while (tabela[pos] != -1 && cont != TAM) {
        pos = reespalha(pos);
        cont++;
    }
    if (cont == TAM)
        cout << "Tabela cheia" << endl;
    else
        tabela[pos] = chave;
}

void busca(int chave)
{
    int pos;
    int cont = 0;

    pos = espalha(chave);
    while (tabela[pos] != chave && tabela[pos] != -1 && cont != TAM) {
        pos = reespalha(pos);
        cont++;
        colisoes++;
    }
    if (tabela[pos] == chave)
        cout << "Encontrei chave na posicao " << pos << endl;
    else
        cout << "Nao encontrei a chave" << endl;
}

void avalia(int total)
{
    colisoes = 0;
    inicia();
    for (int i = 0; i < total; i++)
        insere(rand());
    for (int i = 0; i < 100; i++)
        busca(rand());
    cout << "Inseri " << total << " chaves e ocorreram, em media, " << (float)colisoes / 100 << " colisoes" << endl;
}

int main()
{
    inicia();
    avalia(60);
    return 0;
}