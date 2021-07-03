#include <stdio.h>
#include <time.h>
#include <math.h>


void calcula_juros_mensalidade (int &fator, double &emprestimo,int &parcelas, double &juros_m, double &juros_t, double &anos_m, double &mensalidade) {

    juros_m = 1.8 + ((double)fator * 0.2);

    juros_t = juros_m / 100;

    anos_m = (double) parcelas/12;

    mensalidade = (emprestimo * pow( (1+juros_t), anos_m ) ) / parcelas;

}


int fator_de_risco (int idade, double patrimonio ){

    int fator;

    // Fator

    if (idade >= 18 && idade <= 30) {
        fator = 3;
    }
    else if (idade >= 31 && idade <= 50) {
        fator = 6;
    }
    else if (idade >= 51 && idade <= 60) {
        fator = 9;
    }
    else {
        fator = 12;
    }

    // Patrimonio

    if (patrimonio <= 50000.00) {

        fator = fator + 2;
    }
    else if (patrimonio >= 50000.01 && patrimonio <= 200000.00) {

        fator = fator + 1;
    }
    else if (patrimonio >= 200000.01 && patrimonio <= 1000000.00) {

        fator = fator - 1;
    }
    else {

        fator = fator - 2;
    }


 return fator;
}


//************************ Checa a Data *************************************


int calcula_idade (int dia_nascimento, int mes_nascimento, int ano_nascimento)
{
  //Checa a data atual do computador

  time_t t = time (NULL);
  struct tm lt = *localtime (&t);
  int ano_atual = lt.tm_year + 1900;
  int mes_atual = lt.tm_mon + 1;
  int dia_atual = lt.tm_mday;

  int pre_idade = ano_atual - ano_nascimento;

  int idade;

  if (mes_atual > mes_nascimento) {

    idade = pre_idade;
  }
  else if (mes_atual < mes_nascimento) {

    idade = pre_idade - 1;
  }
  else if (mes_atual == mes_nascimento) {


      if (dia_atual > dia_nascimento || dia_atual == dia_nascimento) {

            idade = pre_idade;
      }
      else if (dia_atual < dia_nascimento) {

            idade = pre_idade - 1;
      }
    }

  return idade;
}



bool bissexto (int ano)     // Ver se o ano é bissesto
{
  return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}


int numero_dias_mes (int mes, int ano)      // Ver os dias do mês
{
  if (mes < 1 || mes > 12 || ano <= 0)
    return -1;

  if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||
      mes == 10 || mes == 12)
    return 31;

  else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    return 30;

  else if (bissexto (ano))
    return 29;

  else
    return 28;
}

bool data_valida (int dia, int mes, int ano)    // Vê se esta certa
{
  int numero_dias = numero_dias_mes (mes, ano);

  return numero_dias != -1 && dia >= 1 && dia <= numero_dias;
}



void le_dados (int &dia, int &mes, int &ano, int &parcelas, double &patrimonio, double &emprestimo)
{

//******************** Valida Data *****************************************

  printf ("Digite sua data de nascimento:\n ");
  printf ("\nDia: ");
  scanf ("%d", &dia);

  printf ("Mes: ");
  scanf ("%d", &mes);

  printf ("Ano: ");
  scanf ("%d", &ano);

  bool x = data_valida (dia, mes, ano);

  while (!x)
    {
      printf ("Data invalida. Digite sua data de nascimento novamente: \n");
      printf ("\nDia: ");
      scanf ("%d", &dia);

      printf ("Mes: ");
      scanf ("%d", &mes);

      printf ("Ano: ");
      scanf ("%d", &ano);
      x = data_valida (dia, mes, ano);
    }

//**************************************************************************




//********** Valida Patrimonio, Emprestimo e meses *************************

  printf ("\nInsira o valor de seu patrimonio: ");
  scanf ("%lf", &patrimonio);

  printf ("Insira o valor do Emprestimo: ");
  scanf ("%lf", &emprestimo);

  printf ("Insira o valor da quantidade de meses de pagamento: ");
  scanf ("%d", &parcelas);


  while (patrimonio < 0 || emprestimo < 1000 || parcelas < 2) {


      printf ("Dados invalidos\n");

      printf ("Insira novamente o valor de seu patrimonio: ");
      scanf ("%lf", &patrimonio);

      printf ("Insira novamente o valor do EmprC)stimo: ");
      scanf ("%lf", &emprestimo);

      printf
    ("Insira novamente o valor da quantidade de meses de pagamento: ");
      scanf ("%d", &parcelas);

    }


//**************************************************************************

}


int main () {

  // Declaração das variáveis

  int dia, mes, ano;
  int parcelas;
  double patrimonio;
  double emprestimo;
  int fator;
  int patr;

  double juros_m;
  double mensalidade;
  double juros_t ;
  double anos_m ;

  // Chamada de Funções

  le_dados (dia, mes, ano, parcelas, patrimonio, emprestimo);

  int idade = calcula_idade (dia, mes, ano);


    if (idade < 18) {   // Define se a idade é valida para emprestimo

        printf("\n\nIdade Mínima é de 18 anos, não são permitidos empréstimos antes disso");
        return 0;       // Pula fora da função

    }

    fator = fator_de_risco (idade,patrimonio);

    printf ("\nFator: %d",fator);

     calcula_juros_mensalidade (fator, emprestimo, parcelas, juros_m, juros_t, anos_m, mensalidade);

    printf ("\nJuros Mensais: %.1lf",juros_m);

    printf ("\nMensalidade: R$ %.2lf",mensalidade);

}

