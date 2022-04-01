//autor: Tejeda Moyao Leon
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main (void)
{
	FILE * doc;
	char inf[100];
	char *a;
	int x;
	int y;
	char alm [100][100];
	
	doc=fopen ("Alumno.csv", "r");
	
	x=0;
	y=0;
	
	int n=1;
	
	if(doc != NULL)
	{
	
		while (!feof(doc))
		{
			fgets (inf, 100, doc);
			a = strtok (inf, "");
			alm [x][y]= *a;
			n++;
			x++;
//			printf ("%s", alm [x][y]);
		}
	}
	free (doc);
	fclose (doc);
	
	
	for (x=0; x<n; x++)
	{
		printf ("%c", alm [0][0]);
	}
	
		
return 0;
}
