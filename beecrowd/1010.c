#include <stdio.h>
int main() {
   double v1, v2;
   int q1, q2;
   char p1[50];
   char p2[50];
   
   scanf("%s %d %lf", &p1, &q1, &v1);
   scanf("%s %d %lf", &p2, &q2, &v2);
   
   
   printf("VALOR A PAGAR: R$ %.2lf\n", q1*v1 + q2*v2 );
    return 0;
}
