#include<stdio.h>
int g[10][10]={0},v,e;
void CreateGraph()
{
	printf("Enter number of vertices:");
	scanf("%d",&v);
	printf("Enter number of edges:");
	scanf("%d",&e);
	printf("Enter edge information:\n");
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		printf("Enter two vertices:");
		scanf("%d %d",&a,&b);
		printf("Enter edge cost:");
		scanf("%d",&c);
		g[a][b]=c;
		g[b][a]=c;
	}
}

int FindMinVertex(int d[],int visited[])
{
	int min=1000,pos=0;
	for(int i=1;i<=v;i++)
	{
		if(d[i]<min && visited[i]!=1)
		{
			min=d[i];
			pos=i;
		}
	}
	return pos;
}

void PrimsAlgo()
{
	int d[10]={100,100,100,100,100,100,100,100,100,100},p[10]={0},visited[10]={0},path[10]={0},current=1,count=1;
	int cost=0;
	path[count]=current;
	d[current]=0;
	visited[current]=1;
	while(count!=v)
	{
		path[count]=current;
		for(int i=1;i<=v;i++)
		{
			if(g[current][i]!=0 && visited[i]!=1 && d[i]>g[current][i])
			{
				d[i]=g[current][i];
				p[i]=current;
			}
		}
		current=FindMinVertex(d,visited);
		visited[current]=1;
		count++;
	}

	//for calculating cost
	for(int x=1;x<=v;x++)
	{
	cost=cost+d[x];
	}
	printf("\nCost is %d\n",cost);
	//for printing path
	for(int y=1;y<=v;y++)
	{
	printf("%d ",path[y]);
	}
	printf("\n");
	//another method for printing path
	int s=v,node=0;
	while(s!=0)
	{
		for(int b=1;b<=v;b++)
		{
			if(p[b]==node)
			{
				printf("%d ",b);
				node=b;
				break;
			}
		}
	s--;
	}
}
int main()
{
	CreateGraph();
	PrimsAlgo();
}
