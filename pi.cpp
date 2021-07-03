#include <stdio.h>
const float raiz = 3.4641016151377;
int main () {

    int n,i,s,m;
    float u,t,x;

    printf("Informe o valor de parcelas (n) :  ");
    scanf("%d",&n);

    s = 1;    //s = soma
    m = 1;   // m = multiplica (potência)
    t = 0;  // t = total da parcela

    for (i=0;i<=n;i++) {

         u = s * m ;   //denominador

      if (i%2 == 0) {
            t = t + 1.0/u;
      }
      else {
            t = t - 1.0/u;
    }
      s += 2;
      m = m * 3;
    }

    x = t * raiz;

    printf("O valor de pi sera %f",x);

return 0;
}
