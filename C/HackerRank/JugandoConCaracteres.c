#include <stdio.h>

int main (void)
{
	char ch;
	char str[100];
	char sen[100];
	
	scanf("%c%*c",&ch);
	gets(str);
	gets(sen);
	
	printf("%c \n",ch);
	printf("%s \n",str);
	printf("%s \n",sen);
	
return 0;
}

