#include <stdio.h>
int main() {

    int N,i;
    double soma,media;

    printf("Quantos elementos vai ter o vetor? ");
    scanf("%d",&N);

    double vetN[N];

    for (i=0;i<N;i++){

        printf("Digite um numero: ");
        scanf("%lf",&vetN[i]);
    }

    soma = 0;

    for (i=0;i<N;i++){

        soma = soma + vetN[i];

    }

    media = soma/N;

    printf("\nMEDIA DO VETOR = %.3lf\n",media);
    printf("ELEMENTOS ABAIXO DA MEDIA:\n");

    for (i=0;i<N;i++){

        if (vetN[i]<media){

          printf("%.1lf\n",vetN[i]);

        }
    }










return 0;
}
