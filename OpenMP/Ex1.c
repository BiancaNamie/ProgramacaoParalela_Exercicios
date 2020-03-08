/*Dados 2 vetores, calcular a soma deles;*/

#include <omp.h>
#include <stdio.h>

int tamanho = 5;
int i;
        
int main(){
    int vetor1[tamanho];
    int vetor2[tamanho];
    int vetorResultado[tamanho];
    
    for(i=0 ; i<tamanho ; i++){
        vetor1[i] = i;
        vetor2[i] = i+5;
    }  
    
    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for
            for(i=0 ; i<tamanho ; i++){
                vetorResultado[i] = vetor1[i] + vetor2[i];
            }
    }
    
    for(i=0 ; i<tamanho ; i++){
        printf("%d ", vetorResultado[i]);
    }   

    getchar();
}