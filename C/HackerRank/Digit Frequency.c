#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	char *s;
    int i;
    int arreglo[10];
    
    for(i =0; i<10; i++)
    {
    	arreglo[i] = 0;
	}
    
	s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    for(i=0; i< strlen(s); i++)
    {
    	if(s[i]-'0' >= 0 && s[i]-'0'<=9)
    	{
    		arreglo[s[i]-'0']++;
		}
	}
	
	for(i =0; i<10; i++)
    {
    	printf("%d ", arreglo[i]);
	}
    
    return 0;
}
