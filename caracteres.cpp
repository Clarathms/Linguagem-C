#include <stdio.h>
#include <ctype.h>


void imprime_caracteres(char vet[], int n) {

    printf("\n");
    printf("Letas trocadas: ");

    for (int i = 0; i < n; i++) {

        printf("%c", vet[i]);


    }
}

int converte_caracteres (char vet[], int n) {


    char l;           // letras para receber o vetor
    int c1 = 0;      // contagem de conversoes
    int c2 = 0;     // contagem de conversoes
    int c = 0;     // soma de conversoes

    for (int i = 0; i < n; i++) {

        l = vet[i];

        if ((l >= 97) && (l <= 122)) {

            vet[i] = toupper(vet[i]);        //  minusculas para maiusculas
            c1++;
       }

        else if ((l >= 65) && (l <= 90))  {

            vet[i] = tolower(vet[i]);       //  maiusculas para minusculas
            c2++;
        }
    }

    c = c + c1 + c2;

    //imprime_caracteres(vet, n);

    return c;


}

void le_caracteres (char vet [],int n) {


    for (int i = 0; i < n; i++) {       // lê o vetor
        getchar();
        printf ("\n%dª letra: ", i + 1);
        scanf ("%c",&vet[i]);
    }


}


int main () {

    int n;


    printf ("Quantos números terá o vetor? ");
    scanf ("%d",&n);

    while (n < 3) {

        printf("Número inválido, digite novamente: ");
        scanf ("%d",&n);

    }

    char vet[n];

    //************ Chamada de funções************

    le_caracteres(vet,n);
    int c = converte_caracteres(vet, n);
    imprime_caracteres(vet, n);

    printf("\n\nQuantidade de conversões: %d\n", c);


}
