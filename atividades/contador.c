#include <stdio.h>

int main()
{
	int n1, i;
	
	printf("Escolha um numero \n");
	scanf("%d", &n1);
	for(i = 0; i < n1 ; i++ ){
		printf("%d %d \n",1+i , n1-i );
	}
	
	return 0;
}
