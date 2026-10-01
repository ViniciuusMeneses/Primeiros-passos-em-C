#include <stdio.h>


int main() {
    int num;
    int menor;   
    int resul;   

    printf("Insira um numero: ");
    scanf("%d", &num);

    menor = num;     
    resul = 1;       

    while (menor > 1) {   
        resul = resul * menor;  
        menor = menor - 1;      
    }

    printf("O fatorial de %d e %d\n", num, resul);

    return 0;
}
