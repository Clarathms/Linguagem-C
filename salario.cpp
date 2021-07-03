#include <stdio.h>
int main (){

    int texp,i,n,hc,ht,he;
    char f;
    float sph,sb,hextra,inss,ir,sl;


      printf("Quantos funcionarios serao digitados? ");
      scanf("%d",&n);

 for (i=0; i<n ; i++) {

      printf("\nHoras Contradas do funcionario %d: ",i+1);
      scanf("%d",&hc);

      // hc = horas contratadas

      printf("Total de horas trabalhadas pelo funcionario %d: ",i+1);
      scanf("%d",&ht);

      // ht = horas trabalhadas

      printf("Quanto tempo (em anos) de experiência o funcionário %d possui? ",i+1);
      scanf("%d",&texp);

      // texp = Tempo de Experiência

      getchar();
      printf("Função do funcionario %d:\n ",i+1);
      printf("Escreva P para Programador, A para Analista ou G para Gerente: ");
      f =  getchar();

      // f = função
     // sph = Salario por hora


    if (f == 'P' || f == 'p') {

        if (texp <= 2){
           sph = 25.00;
        }
        else if (texp >=3 && texp <=5 ) {
           sph = 30.00;
        }
        else {
          sph = 38.00;
        }
    }
    else if (f == 'A' || f == 'a') {

         if (texp <= 2){
           sph = 45.00;
        }
        else if (texp >=3 && texp <=5 ) {
           sph = 55.00;
        }
        else {
          sph = 70.00;
        }
    }


    else if (f == 'G' || f == 'g') {


        if (texp <= 2){
           sph = 85.00;
        }
        else if (texp >=3 && texp <=5 ) {
           sph = 102.00;
        }
        else {
          sph = 130.00;
        }
    }


        //sb = Salário Bruto
        // Definir previamente um valor para que essas variáveis não assumam outro valor lixo
        sb = 1;
        hextra = 0;


  if (ht<=hc) {

       // Não possui hora excedente
        sb = sb * ht * sph;

  }
  else {

        he = ht - hc;    // he = hora excedente

        if (he <= 13) {

            hextra = hextra + sph * (23.0/100) ;
        }
        else if ( he > 13 && he <= 22) {
            hextra = hextra + sph * (37.0/100) ;
        }
        else {
            hextra = hextra + sph * (56.0/100) ;
        }

        sb = sb * (hc * sph) + (he * hextra);

    printf ("\n O funcionário %d trabalhou %d horas extras",i+1,he);
    printf("\n");

  }

  // Impressão dos valores de horas extras (acima) e Salário Bruto ****************

   printf("\n");
   printf (" O salário bruto do funcionário %d será de R$ %.2f\n",i+1,sb);
   printf("\n");

 //********************************************************************************

     ir = 1;
     inss = 1;

     inss = inss * sb * (11.0/100);

     printf(" O desconto do INSS sobre o salário do funcionário %d será de R$%.2f\n", i+1 , inss);


  if (sb <= 1500) {

     ir = 0;
  }
  else if (sb <= 2700) {

       ir = ir * (15.0/100) * (sb - inss);
  }
  else if (sb <= 4200) {

       ir = ir * (20.0/100) * (sb - inss);
  }
  else {

       ir = ir * (30.0/100) * (sb - inss);
  }


  sl = 0;  // salário liquido

  sl = sl + (sb - inss - ir);

  // Impressão dos valores de IR e salário liquido

  printf("\n");
  printf (" O desconto do IR sobre o salário do funcionário %d será de R$%.2f\n", i+1 , ir);
  printf("\n");
  printf(" O salário liquido (descontados o INSS e IR) será de R$%.2f ",sl);
  printf("\n");

 }


return 0 ;

}
