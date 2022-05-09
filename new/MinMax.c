#include<stdio.h>
#include<stdlib.h>

int min(int x, int y)
{
	if (x<y) return x;
	else return y;
}

int max(int x, int y)
{
	if (x<y) return y;
	else return x;
}

int minmax(int a[], int i, int j, int f[])
{
	int g[2],h[2];
	
	if (i==j)
		f[0]=f[1]=a[i];
	else if (i==j-1)
	{
		f[0]=min(a[i],a[j]);
		f[1]=max(a[i],a[j]);
	}
	else
	{
		int mid=(i+j)/2;
		minmax(a,i,mid,g);
		minmax(a,mid+1,j,h);
		f[0]=min(g[0],h[0]);
		f[1]=max(g[1],h[1]);
	}
}

int main()
{
	int n, *a, i, f[2];
	
	printf("Enter the number of elements = ");
	scanf ("%d",&n);
	
	a=(int*)malloc(sizeof(int)*n);
	printf("\nEnter elements in array\n");
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	minmax(a,0,n-1,f);
	printf("Min value = %d\nMax value = %d",f[0],f[1]);
	return 0;
}
