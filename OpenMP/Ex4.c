/*Encontrar o maior e o menor valor de um vetor.*/

#include <omp.h>
#include <stdio.h>
#include <math.h>

int tamanho = 5;
int i;
        
int main(){
    float vetor[tamanho] ;
    
    for(i=0 ; i<tamanho ; i++){
        vetor[i] = 7-i;
    }

    float minimo = vetor[0], maximo = vetor[0];

    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for reduction(min: minimo) reduction(max: maximo)
            for(i=1 ; i<tamanho ; i++){
                minimo = fmin(vetor[i], minimo);
                maximo = fmax(vetor[i], maximo);
            }
    }

    printf("Minimo: %.2f \n", minimo);
    printf("Maximo: %.2f \n", maximo);

    getchar();
}