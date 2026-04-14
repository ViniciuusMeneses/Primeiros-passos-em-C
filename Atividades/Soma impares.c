#include <stdio.h>

int main()
{
    int n1, n2, i, soma = 0;
    
    printf("Escolha um numero: ");
    scanf("%d", &n1);
    printf("Escolha outro numero: ");
    scanf("%d", &n2);
    
    if(n1<n2){
        int aux = n2;
        n2 = n1;
        n1 = aux;
    }


    
    if (n1 % 2 == 0) {
        n1 -= 1;
    }
   
   
    for (i = n1; i > n2; i -= 2) {
        soma += i;
        // printf("- %d\n", i);
    }

    printf("A soma dos impares entre os numeros eh: %d\n", soma);

    return 0;
}
