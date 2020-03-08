/*Calcular a média e o desvio padrão dos dados de um vetor*/

#include <omp.h>
#include <stdio.h>
#include <math.h>

int tamanho = 5;
int i;
        
int main(){
    float vetor[tamanho] ;
    float media, desvioPadrao = 0, soma = 0, aux;
    
    for(i=0 ; i<tamanho ; i++){
        vetor[i] = i+1;
    }

    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for reduction(+: soma)
            for(i=0 ; i<tamanho ; i++){
                soma = soma + vetor[i];
            }
    }

    media = soma / tamanho;

    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for reduction(+: soma)
            for(i=0 ; i<tamanho ; i++){
                desvioPadrao += pow(vetor[i]  - media, 2);
            }
    }

    desvioPadrao = sqrt( desvioPadrao / tamanho);
  
    printf("Media: %.2f ", media);
    printf("Desvio Padrao: %.2f", desvioPadrao);

    getchar();
}