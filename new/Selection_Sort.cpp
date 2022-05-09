//Selection Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionsort(int arr[], int n)
{
	for (int i=0;i<n-1;i++)
	{
		int min=i,temp;
		for (int j=i+1;j<n;j++)
		{
			if (arr[j]<arr[min])
			{
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

void insertionsort(int arr[], int n)
{
	for (int i=1;i<n;i++)
	{
		for (int j=i-1;j>=0;j--)
		{
			if (arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void simplemerge(int arr[], int low, int mid, int high)
{
	int *temp;
	temp=(int*)(malloc((high-low+1)*sizeof(int)));
	int i=low,j=mid+1,k=0;
	
	while(i<=mid && j<=high)
	{
		if (arr[i]<arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	
	while (i<=mid)
		temp[k++]=arr[i++];
	while (j<=high)
		temp[k++]=arr[j++];
	
	k=0;
	for (i=low;i<=high;i++)
		arr[i]=temp[k++];
}

void mergesort(int arr[], int low, int high)
{
	int mid;
	if (low<high)
	{
		mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		simplemerge(arr,low,mid,high);
	}
}

void myquicksort(int arr[], int n)
{
	
}

int main()
{
	int *inp;
	float total;
	FILE *input,*output;
	clock_t start,end;
	
	for (int i=10000;i<=50000;i=i+10000)
	{
		
		input = fopen("input.txt","w");
		output = fopen("output.txt","w");
		
		inp = (int*)(malloc(i*sizeof(int)));
		printf("\nFor n = %d\n",i);
		for (int j=0;j<i;j++)
		{
			fprintf(input,"%d ",rand()%i);
		}
		fclose(input);
		
		input = fopen("input.txt","r");
		
		for (int j=0;j<i;j++)
		{
			fscanf(input,"%d",&inp[j]);
			//printf("%d ",inp[j]);
		}
		
		printf("\n");
		start=clock();
		mergesort(inp,0,i);
		end=clock();
		
		total = (float)(end-start)/CLOCKS_PER_SEC;
		for (int j=0;j<i;j++)
		{
			fprintf(output,"%d ",inp[j]);
			//printf("%d ",inp[j]);
		}
		
		printf("\nTotal Time : %f\n\n",total);
		
		fclose(input);
		fclose(output);
	}
	
	return 0;
}
