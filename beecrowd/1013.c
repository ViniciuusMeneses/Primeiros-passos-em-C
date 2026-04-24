#include <stdio.h>

int main() {
    int v[3]; 
    int i;
    int maiorNum;

    for(i = 0; i < 3; i++) {
        scanf("%d", &v[i]);
    }

    maiorNum = v[0];

    for(i = 1; i < 3; i++) {
        if(maiorNum < v[i]) {
            maiorNum = v[i];
        }
    }

    printf("%d eh o maior\n", maiorNum);

    return 0;
}
