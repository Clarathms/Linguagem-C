#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

    long long cpf,alt,cripto;
    int i,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11;


    srand(time(NULL));
    int k = rand() % 9 + 1;    // Calcula k

    cpf = 0;



                 while(cpf > 99999999999 || cpf <= 10000000000) {

                                 // Input 

                                 printf(" Digite o n�mero de CPF: ");
                                 scanf ("%lld",&cpf);

                        // *********************************** Para separar cada d�gito **************************************************

                      n1 =  cpf / 10000000000;
                      n2 = (cpf % 10000000000) / 1000000000;
                      n3 = ((cpf % 10000000000) % 1000000000) / 100000000;
                      n4 = (((cpf % 10000000000) % 1000000000) % 100000000) / 10000000;
                      n5 = ((((cpf % 10000000000) % 1000000000) % 100000000) % 10000000) / 1000000;
                      n6 = (((((cpf % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) / 100000;
                      n7 = ((((((cpf % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) / 10000;
                      n8 = (((((((cpf % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) / 1000;
                      n9 = ((((((((cpf % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) / 100;
                      n10 =(((((((((cpf % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) / 10;
                      n11 =((((((((((cpf % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10) / 1;

                      //***********************************************************************************************************************



                      // ***************** Mudar a ordem dos d�gitos (antes do giro de k) *****************************************************

                     int an11 = n11;
                     int an1 = n1;
                     n1 = n11;

                     int an6 = n6;
                     n6 = an1;

                     int an2 = n2;
                     n11 = an2;

                     n2 = n10;

                     int an7 = n7;
                     n7 = an6;

                     int an5 = n5;
                     n5 = an7;

                     int an8 = n8;
                     n8 = an5;

                     int an4 = n4;
                     n4 = an8;

                     int an9 = n9;
                     n9 = an4;

                     int an3 = n3;
                     n3 = an9;

                     int an10 = n10;
                     n10 = an3;

                    //**************************************************************************************************************************


                    // **************** Para fazer o giro ****************************

                     int A = 0;


                    for (i = 1 ; i <= k ; i++) {

                     A = n1;
                     n1 = n2;
                     n2 = n3;
                     n3 = n4;
                     n4 = n5;
                     n5 = n6;
                     n6 = n7;
                     n7 = n8;
                     n8 = n9;
                     n9 = n10;
                     n10 = n11;
                     n11 = A;

                    }

                     printf(" O CPF criptografado ser� igual a: %d%d%d%d%d%d%d%d%d%d%d%d",n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,k);


                }


return 0;
}