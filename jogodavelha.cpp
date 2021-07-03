#include <stdio.h>
#include <stdlib.h>

char mat [3] [3];

void inic_mat () {      // void para inicializar

    for (int i = 0 ; i < 3 ; i++) {
       for (int j = 0 ; j < 3 ; j++) {

          mat [i] [j] = '_' ;
       }
   }
}

int valido (char letra) {

    if (letra == 'X' || letra == 'O'){

        return 1;      // ja foi ocupado
    }
    else {
        return 0;     // não foi ocupado (posição)
    }
}

int coord_valida (int x , int y) {      // para ver se a coordenada é válida (x e y indicam as coord)

    if (x>=0 && x<3){
        if (y>=0 && y<3){
            return 1;
        }
    }
    printf("Coordenadas invalidas!\n");
    return 0;
}

int pos_v (int x, int y) {           // para ver se a coordenada está ocupada

    if (mat[x][y] != 'X' && mat [x][y] != 'O')
        return 1;

    printf("Posição já ocupada!\n");
    return 0;

}

//************************************** Para ver se alguém ganhou *********************************************************

int ganhou_l () {       // Linhas
    int i,j,igual = 1;
    for (i = 0 ; i < 3 ; i++){
        for (j = 0 ; j < 2 ; j++) {
            if (valido(mat[i][j]) && mat[i][j] == mat[i][j+1] ){   // comparações em j
               igual++;      // incrementa uma unidade
            }
        }
        if (igual == 3){
            return 1;   // alguém ganhou
            igual = 1;
        }
    }
    return 0;   // Ninguém ganhou ainda por linhas
}


int ganhou_c () {       // Colunas
    int i,j,igual = 1;
    for (i = 0 ; i <3 ; i++){
        for (j = 0 ; j < 2 ; j++) {
            if (valido(mat[j][i]) && mat[j][i] == mat[j+1][i] ){   // comparações em i
               igual++;      // incrementa uma unidade
            }
        }
        if (igual == 3)
            return 1;   // alguém ganhou
        igual = 1;

    }
    return 0;   // Ninguém ganhou ainda por colunas
}


int ganhou_dp () {      // Diagonal Principal
    int i, igual = 1;
    for (i = 0; i < 2; i++) {
        if (valido(mat[i][i]) && mat[i][i] == mat [i+1][i+1]) {
            igual++;
        }
    }
    if (igual == 3) {
        return 1;   // Alguém ganhou pela Diagonal Principal
    }
    else {
        return 0;   // Ninguém ganhou pela Diagonal Principal
    }
}


int ganhou_dsec () {      // Diagonal Secundária
    int i, igual = 1;
    for (i = 0; i < 2; i++) {
        if (valido(mat[i][3-i-1]) && mat[i][3-i-1] == mat [i+1][3-i-2]) {     // 3 (colunas) - i - 1 (para que dê a linha correspondente)
            igual++;
        }
    }
    if (igual == 3) {
        return 1;   // Alguém ganhou pela Diagonal Principal
    }
    else {
        return 0;   // Ninguém ganhou pela Diagonal Principal
    }
}

//**************************************************************************************************************************


void imprimir () {


int l,c,jog;

for ( l = 0; l < 3; l++) {
    for ( c = 0; c < 3; c++){

            printf(" %c ",mat[l][c]);
    }
     printf("\n");
}

}

void jogar() {

    int x,y;             // Coordenadas
    int valida;
    int ordem = 1;      // Jogador 1
    int ganhou = 0;
    int jogadas = 0;
    int jog1 = 1;
    int jog2 = 2;
    int jog;


do{
    do{
        imprimir();

        printf("\nDigite a coordenada que deseja jogar (de 1 a 3): ");
        scanf("%d %d",&x,&y);

        valida = coord_valida(x-1,y-1);     // Verifica se os valores digitados são válidos
        if(valida == 1) {
            valida += pos_v(x-1,y-1);       // Verifica se a posição está vazia
        }

    } while (valida != 2);              // Coordenada é valida e posição está vazia

    if (ordem == 1) {                   // Quando o jog 1 estiver jogando

        jog = 1;
        printf("\nJogada do jogador 1:\n");
        mat[x-1][y-1] = 'X';
    }
    else {
        jog = 2;
        printf("\nJogada do jogador 2:\n");
        mat[x-1][y-1] = 'O';               // Se não for o jogador 1
    }
    jogadas++;                         // Se der velha
    ordem++;
    if (ordem == 3) {
        ordem = 1;
    }
    ganhou += ganhou_l();
    ganhou = ganhou_c();
    ganhou += ganhou_dp();
    ganhou += ganhou_dsec();

} while (ganhou == 0 && jogadas < 9);       // Para que o loop pare se ninguém ganhar



  if (ganhou != 0){
      if (ordem - 1 == 1)  {               // Jog 1 venceu
      imprimir();
        printf("\n Jogador %d vence!\n\n",jog1);
      }
      else {
          imprimir();
        printf("\n Jogador %d vence!\n\n",jog2);    //// Jog 2 venceu
      }
  }
  else {
        printf("\n Velha! \n\n");       // Ninguém ganhou
  }

}

int main () {

    inic_mat ();    // Inicializa a matriz
    jogar ();



return 0;
}
