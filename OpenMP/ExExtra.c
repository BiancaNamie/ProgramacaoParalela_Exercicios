/* Numeros Amigos*/

#include <omp.h>
#include <stdio.h>
#include <math.h>

int mdc(int a, int b);

typedef struct Amigos{
    int numero;
    int dividendo;
    int divisor;
}Am;

int main()
{   
    Am teste[10001];
    int amigos[10001][10001] = {0};
    int N=10000;

    #pragma omp parallel
    {
        #pragma omp for
        for (int a=0; a<=N+1 ;a++){
            teste[a].numero = a; //preenche o vetor com todos os numeros
            teste[a].dividendo = 0;
            teste[a].divisor = 0;
        }
        

        #pragma omp for //define dividendos e divisores
        for (int i = 0; i < N +1 ; i++){
            teste[i].dividendo += 1 + teste[i].numero;
            for (int j=2;j<teste[i].numero;j++){
                if(teste[i].numero % j == 0){
                    teste[i].dividendo += j;
                }      
            }
            teste[i].divisor = i;
            int m = mdc(teste[i].dividendo, teste[i].divisor);  //simplifica dividendos e divisores
            teste[i].divisor /= m;
            teste[i].dividendo /= m;
        }
        #pragma omp single
        {
        teste[1].divisor = 1;
        teste[1].divisor = 1;
        teste[1].dividendo = 1;
        }
        #pragma omp for
        for(int i=1; i<N+1;i++){
            for (int j = i+1; j < N+1; j++)
            {
                if (teste[i].divisor==teste[j].divisor && teste[i].dividendo==teste[j].dividendo){              
                        amigos[i][j]=1;
                }
            }       
        }

    }


    for (int i = 1; i<N+1;i++){
        for (int j = i+1; j < N+1; j++){
            if (amigos[i][j] == 1)
            {
                printf("%d %d \n", i, j);
            } 
        }
    }
              
    getchar(); 
    return 0;                                  
}

int mdc(int a, int b)//maximo divisor comum, algoritmo de Euclides
{
  int aux;  
  while (b != 0){
     aux = a % b;
     a = b;
     b = aux;
  }
  return a;
}