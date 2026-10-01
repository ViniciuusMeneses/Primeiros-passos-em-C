#include <stdio.h>

int main() {
    int num1, num2, res = 0;
    
    printf("Insira o primeiro numero: ");
    scanf("%d", &num1);
    
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    
    int i = 0;
    while (i < num2) {
        res += num1;  
        i++;
    }
    
    printf("O resultado da multiplicacao e: %d\n", res);
    
    return 0;
}
