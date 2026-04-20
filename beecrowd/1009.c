#include <stdio.h>

int main() {
    char n[50];  
    double s, b;

    scanf("%s", n);  
    scanf("%lf", &s);    
    scanf("%lf", &b);    

    printf("TOTAL = %.2lf\n", s + b/20*3);
    return 0;
}
