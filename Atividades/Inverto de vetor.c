#include <stdio.h>

int main()
{
	int v[10];
	int i, n = 10;
	
	for(i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}
	for(n = 0, i = 9; i > n; i--){
		printf("%d\n", v[i]);
	}
	return 0;
}
