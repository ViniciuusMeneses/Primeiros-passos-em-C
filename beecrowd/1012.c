#include <stdio.h>

int main()
{
    double b, h, r;
    
    scanf("%lf %lf %lf", &b, &h, &r);
    printf("TRIANGULO: %.3lf", b*r/2);
    printf("\nCIRCULO: %.3lf", 3.14159*r*r);
    printf("\nTRAPEZIO: %.3lf", ((b+h)*r)/2);
    printf("\nQUADRADO: %.3lf", h*h);
    printf("\nRETANGULO: %.3lf\n", b*h);

    return 0;
}
