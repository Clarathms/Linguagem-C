 #include <stdio.h>
int main () {

    int n,ns1,k,ns2,i,j;


    printf("Quantos números serão colocados em S1? ");             // Definir S1
    scanf("%d",&n);
    printf("\n");

    int matn [n];  // vetor de n

    for (int i = 0 ; i < n ; i++) {

       printf("Digite o %d° número (de 1 a 100): ",i+1);
       scanf("%d",&ns1);
       if (ns1 >= 1 && ns1 <= 100) {
           matn[i] = ns1;
       }
       else{
        do {
            printf("Número inválido! Digite novamente: ");
            scanf("%d", &ns1);

            if (ns1 >= 1 && ns1 <= 100) {
                matn[i] = ns1;
            }
        }    while(ns1 < 0 || ns1 > 100);
        }
    }



    printf("\nQuantos números serão colocados em S2? ");             // Definir S2
    scanf("%d",&k);
    printf("\n");

    int matk [n];  // vetor de k

    for (int j = 0 ; j < k ; j++) {

       printf("Digite o %d° número (de 1 a 100): ",j+1);
       scanf("%d",&ns2);

       if (ns2 >= 1 && ns2 <= 100) {
           matk[j] = ns2;
       }
       else{
        do {
            printf("Número inválido! Digite novamente: ");
            scanf("%d", &ns2);
            if (ns2 >= 1 && ns2 <= 100) {
                matk[j] = ns2;
            }
        }  while(ns2 < 0 || ns2 > 100);
        }
    }



   //******** Imprimir vetores***********

    printf("\nS1 = [");
    for (int i = 0; i < n; i++) {
        printf("%d, ", matn[i]);
    }
    printf("] \n\n");

    printf("S2 = [");
    for (int j = 0; j < k; j++) {
    printf("%d, ", matk[j]);
    }
    printf("] \n");

   //**************************************

  //*************** Identifica os números em comum e as posições se tiver *********************************


    while ( i < n && j < k){
            if (matn[i] == matk[j]) {
                i++;
                j++;
            }
            else {

                i = i - j + 1;
                j = 0;

            }


    }

    if ( j == k ) {     // Frente para trás
        printf ("\n\nS2 ocorre em S1 na posição %d de frente para trás \n",i-j);
    }
    else {              // Trás para frente

        i = n;

        j = 0;

        while (i >= 0 && j < k) {

            if (matn[i] == matk[j]) {

                i--;
                j++;

                if ( j == k ) {
                    printf("\n\nS2 ocorre em S1 na posição %d de trás para frente\n",i+j);
                }

            }
            else {      // Em nenhum dos dois

                i = i + j - 1;
                j = 0;

                if (i == 0 && j == 0) {
                    printf ("\n\nS2 não encontrado em S1");
                }
            }
        }
    }



return 0;
}
