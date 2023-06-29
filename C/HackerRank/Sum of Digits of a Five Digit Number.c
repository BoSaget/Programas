#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    int aux;
    aux = 0;
    scanf("%d", &n);
    
    for(int i =0; i<5; i++)
    {
        aux = n%10 + aux;
        n=n/10;
    }

    printf("%d", aux);

return 0;
}