#include <stdio.h>
int main() {
    double n = 3.14159, r;
    scanf("%lf", &r);
    r *= r;
    printf("A=%.4lf\n", n * r);
    return 0;
}
