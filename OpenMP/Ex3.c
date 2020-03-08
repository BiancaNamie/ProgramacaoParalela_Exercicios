/*Calcular a média harmônica de um vetor*/

#include <omp.h>
#include <stdio.h>
#include <math.h>

int tamanho = 5;
int i;
        
int main(){
    float vetor[tamanho] ;
    float mediaHarmonica = 0, soma=0, aux;
    
    for(i=0 ; i<tamanho ; i++){
        vetor[i] = i+1;
    }

    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for reduction(+: soma)
            for(i=0 ; i<tamanho ; i++){
                soma += 1 / vetor[i];
            }
    }

    mediaHarmonica = tamanho / soma;

    printf("Media Harmonica: %.2f ", mediaHarmonica);

    getchar();
}