#include<stdio.h>

int main()
{
	char ms[15],p[15];
	int np,ns,i;
	printf("Enter the main sequence:\n");
	scanf("%s",&ms);
	printf("\nEnter the Pattern to be matched:\n");
	scanf("%s",&p);
	
	for (np=0;p[np]!='\0';np++);
	for (ns=0;ms[ns]!='\0';ns++);
	
	for (i=0;i<ns-np;i++)
	{
		int j=0;
		while (ms[i+j]==p[j] && j<np)
			j++;
		if (j==np)
			break;
	}
	if (i==ns-np)
		printf("\nPattern does not exists");
	else
		printf("\nPattern exists at %d index",i);
	return 0;
}
