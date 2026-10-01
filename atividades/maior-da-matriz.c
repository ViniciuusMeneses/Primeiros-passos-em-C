#include <stdio.h>

int main()
{
	int m[3][3] = {0};
	int i, j, maior = 0;
	
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
		printf("\n\nMaior valor e %d", maior);
	return 0;
}
