#include <stdio.h>

int main()
{
	int d, x = 0, y = 0, temp = 0;
	scanf("%d", &d);
	
	while (y - x != d){
		if (temp % 2 == 0) y++;
		
		temp++;
	}
	
	printf("%d minutos\n", temp+1);
	
	
	return 0;
}
