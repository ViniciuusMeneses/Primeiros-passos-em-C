#include <stdio.h>

int main() {
    int idade;
    float peso;
    float dose = 0;
    int gota;

    printf("Informe a idade: ");
    scanf("%d", &idade);

    printf("Informe o peso (kg): ");
    scanf("%f", &peso);

    if (idade >= 12) {
        if (peso >= 60.0) {
            dose = 1000.0;
        } else {
            dose = 875.0;
        }
    } else {
        if (peso >= 5.0 && peso <= 9.0) {
            dose = 125.0;
        } else if (peso > 9.0 && peso <= 16.0) {
            dose = 250.0;
        } else if (peso > 16.0 && peso <= 24.0) {
            dose = 375.0;
        } else if (peso > 24.0 && peso <= 30.0) {
            dose = 500.0;
        } else if (peso > 30.0) {
            dose = 750.0;
        }
    }

    gota = (int)(dose * 0.04);

    printf("Dose: %.0f mg -> %d gotas\n", dose, gota);

    return 0;
}
