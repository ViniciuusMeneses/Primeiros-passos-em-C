#include <stdio.h>

int main()
{
	int n[8];
	int i, menor, maior = 0;
	int pmenor, pmaior;
	
	for(i = 0; i < 8; i++){
		scanf("%d", &n[i]);
		if(n[i] > maior){
			maior = n[i];
			pmaior = i;
		}
		if(n[i] < menor){
			menor = n[i];
			pmenor = i;
		}
	}
	
	printf("\nMaior e Pocisao Posicao maior %d %d", maior, pmaior);
	printf("\nMenor e Posicao menor %d %d", menor, pmenor);
		
	return 0;
}
