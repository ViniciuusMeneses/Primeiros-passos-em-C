#include <stdio.h>
#include <unistd.h>

int main(){
	int jogo;
	
	printf("-----Steam indie-----\n");
	printf("Jogo das pergunstas (1)\n");
	printf("Cobra na caixa (2)\n");
	printf("Gousmas War (3)\n");
	scanf("%d", &jogo);
	if(jogo == 1){
		int pontos = 0;
		int resposta;
		
		printf("Primeira pergunta\n");
		printf("Qual o unico time do norte a disputa uma Libertadores?\n");
		printf("Paysandu (1)\n");
		printf("Manaus (2)\n");
		printf("Goias (3)\n");
		printf("Remo (4)\n");
		scanf("%d", &resposta);
		if(resposta == 1){
			printf("acertou mais 200 pontos");
			pontos + 200;
			pergunta + 2;
		} else if(resposta == 2){
			printf("errou, so disputa serie D");
		}else if(resposta == 3){
			printf("errou, Goias e do norte? kkkkkkkkkkkkk");
		}else{
			printf("errou, remo so disputa rainha das rainhas");
		}
	
		
			
			
	} else if( pergunta == 2){
		printf("Calma, to fazendo pae");
	} else if(jogo == 3){
		printf("calma, to fazendo pae");
	} else{
		printf("TO FAZENDO EGUA");
	}
	
	
	
	return 0;
}
