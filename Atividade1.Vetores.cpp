#include <iostream>   // ou #include <stdio.h>

using namespace std;

const int TAM=5;     // ou #define TAM 5
int vetor[TAM];
int vetorB[TAM];

int main() {
    int i,menor,maior,soma;

    cout << "Digite " << TAM << " valores: ";  //ou printf("Digite %d valores",TAM);

    for(i=0; i<TAM; i++) {
        cin >> vetor[i];                       //ou scanf("%d",&vetor[i]);
    }

    for(i=0; i<TAM; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    for(i=TAM-1; i>=0; i--) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    maior=vetor[0];
    for(i=1; i<TAM; i++) {
        if (vetor[i]>maior)
            maior = vetor[i];
    }
    cout << "O maior valor e: " << maior << endl;  //printf("O maior valor e: %d",maior);
    
    menor=vetor[0];
    for (int i=1;i<TAM;i++)
        if (vetor[i]<menor)
            menor=vetor[i];
    cout << "Menor número é " << menor << endl;

    soma=vetor[0];
    for(i=1; i<TAM; i++) {
        soma=soma+vetor[i];
    }
    cout << "A soma e: " << soma << endl;
    
    cout << "A media e: " << (float)soma/TAM << endl;
    
    //BONUS
    //Bônus
    for (int i=0;i<TAM;i++)
        vetorB[TAM-i-1]=vetor[i];
    
    for (int i=0;i<TAM;i++)
        cout << vetorB[i] << " ";
    cout << endl;
}
