#include <stdio.h>

int main()
{
	int m[3][3] = {0};
	int i, j, maior = 0, soma = 0;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			scanf("%d", &m[i][j]);
			if(m[i][j] > maior){
				maior = m[i][j];
			}
	    }
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d", m[i][j]);
		}
	}
	soma = m[0][0] + m[2][2] + m[0][2] + m[2][0];
		printf("\n\nMaior valor e %d", maior);
		printf("\nsoma dos valores nas pontas e %d", soma);
	return 0;
}
