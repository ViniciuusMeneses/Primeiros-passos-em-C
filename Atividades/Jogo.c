#include <stdio.h>
#include <stdlib.h>

int main() {
    int jogo;

    printf("-----Steam indie-----\n");
    printf("Jogo das perguntas (1)\n");
    printf("Cobra na caixa (2)\n");
    printf("Gousmas War (3)\n");
    scanf("%d", &jogo);

    if (jogo == 1) {
        int pontos = 0;
        int resposta;

        printf("Primeira pergunta\n");
        printf("Qual o unico time do norte a disputar uma Libertadores?\n");
        printf("Paysandu (1)\n");
        printf("Manaus (2)\n");
        printf("Goias (3)\n");
        printf("Remo (4)\n");
        scanf("%d", &resposta);

        if (resposta == 1) {
            pontos += 200;
            printf("Acertou! Voce ganhou 200 pontos. Total: %d\n", pontos);
        } else if (resposta == 2) {
            printf("Errou, so disputa serie D\n");
        } else if (resposta == 3) {
            printf("Errou, Goias e do norte? kkkkkkkkkkkkk\n");
        } else {
            printf("Errou, Remo so disputa Rainha das Rainhas\n");
        }
        
        system("pause");
        system("cls");
        
        printf("Segunda pergunta\n");
        printf("Qual o atual time disputando a primeira divisão\n");
        printf("Paysandu (1)\n");
        printf("Manaus (2)\n");
        printf("Goias (3)\n");
        printf("Remo (4)\n");
        scanf("%d", &resposta);
		
        if (resposta == 1) {
            pontos += 200;
            printf("Acertou! Voce ganhou 200 pontos. Total: %d\n", pontos);
        } else if (resposta == 2) {
            printf("Errou, so disputa serie D\n");
        } else if (resposta == 3) {
            printf("Errou, Goias e do norte? kkkkkkkkkkkkk\n");
        } else {
            printf("Errou, Remo so disputa Rainha das Rainhas\n");
        }
        
        
        system("pause");
        
        printf("pontuacao total: %d", pontos);
        
        

    } else if (jogo == 2) {
        printf("Calma, to fazendo pae\n");
    } else if (jogo == 3) {
        printf("Calma, to fazendo pae\n");
    } else {
        printf("TO FAZENDO EGUA\n");
    }

    return 0;
}
