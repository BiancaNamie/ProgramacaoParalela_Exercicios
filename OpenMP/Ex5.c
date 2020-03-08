/* Retornar todos os valores primos de 0 até N.
 * Válido
 * Balanceado 
 * Otimizado */

#include <omp.h>
#include <stdio.h>
#include <math.h>
void main()
{   
    int N = 100;
    int primos[N+1];
    int inicio, aux = 2;
    
    #pragma omp parallel
    {
        #pragma omp for
            for (int a=0; a<=N ;a++){
                primos[a] = a; //preenche o vetor com todos os numeros
            }
    }

    primos[1] = 0;

loopwhile:  //while que retira os multiplos do numero primo
    #pragma omp parallel
    {
        #pragma omp for
        for (inicio = aux + aux ; inicio < N +1 ; inicio+=aux){
        //pega todos os multiplos do menor numero primo ainda nao calculado e os tira do array de primos
                primos[inicio] = 0;
        }
    }
    do{
        aux++;  //procura o proximo numero primo
    } while (primos[aux] == 0 && aux != N/2);
    if (aux+1 < N){
        goto loopwhile; //volta para retirar os multiplos do prox primo
    }

    for (int i = 0; i < N +1; i++){
        if (primos[i] != 0)
        {
            printf("%d ", primos[i]);
        }
    }
                         
    getchar();                                   
}
