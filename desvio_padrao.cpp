#include <stdio.h>
#include <math.h>

double desvio_padrao (int v1[], int k, int inicio, int final, int somatorio1) {

    double media = (double) somatorio1 / k;       // Calcula a media do desvio padrão
    double somatorio = 0;   // Total


    for (inicio; inicio < final; inicio++)          // Separa os blocos

        somatorio += pow(v1[inicio] - media, 2);

    double div = somatorio / (k - 1);
    double dp = sqrt(div);      // Desvio padrao - raiz
    return dp;
}


void calcula_dp (int v1[], int n, double v2[], int k) {

        int j = 0;
        int somatorio1 = 0;
        int inicio = 0;
        int final = k;

    for (int i = 0; i < n; i++) {

        somatorio1 += v1[i];
        if ((i + 1) % k == 0) {

            v2[j] = desvio_padrao(v1, k, inicio, final, somatorio1);    // chamar o desvio padrão
            somatorio1 = 0;
            inicio += k;
            final += k;
            j++;
        }
    }
}

void imprime_vetor( int v1[], int n) {

    printf ("V1 = [");
     for (int i = 0; i < n; i++) {

        printf(" %d, ", v1[i]);
     }
    printf ("]");
}

void le_vetor(int v1[], int n) {

    //le o vetor
     for (int i = 0; i < n; i++) {

        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &v1[i]);
     }
     printf("\n");

     imprime_vetor(v1, n);
}

int main()
{

    int n, k;

    //*********** Vê se n e k são válidos***************

    printf ("Digite o valor de n : ");
    scanf("%d",&n);

    while (n <= 2) {
        printf("Valor inválido! Digite novamente: ");
        scanf("%d",&n);
    }

    printf ("Digite o valor de k : ");
    scanf("%d",&k);
    printf("\n");

    while (2 > k || k > n) {

        printf("Valor inválido! Digite novamente: ");
        scanf("%d",&k);

    }

    while (n % k != 0) {

        printf("Valor inválido! Digite novamente: ");
        scanf("%d",&k);
    }

    //***********************************************

    //declaraçao dos vetores

    int v1[n];

    int t_v2 = n/k;
    double v2[t_v2];

    int inicio;
    int tam_bloco;

    //chamada das funções

    le_vetor(v1, n);

    calcula_dp(v1, n, v2, k);

    // Chamar o V2:

    printf("\n\nV2 = [");

    for (int j = 0; j < n / k; j++) {
      printf(" %.2f, ", v2[j]);
    }

    printf("]");



}
