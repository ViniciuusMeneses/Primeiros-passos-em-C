#include <stdio.h>

int main()
{
	int esc, i;
	
	printf("Escolha um numero ");
	scanf("%d", &esc);
	printf("A tabuada e \n");
	
	for(i = 1; i <= 10; i++){
		printf("%d \n", esc*i);
	}
