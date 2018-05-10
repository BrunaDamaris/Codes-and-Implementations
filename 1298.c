#include <stdio.h>
#include <string.h>
#define max 1000

char matriz[max][max];
char matriz1[max][max];


int score(char matriz[max][max],int i,int j)
{
	int point=0;
	if(matriz[i][j] == 'b')
	{
		point++;
	}
	if(matriz[i][j] == 'p')
	{
		point+=5;
	}
	if(matriz[i][j] == 'o')
	{
		point+=10;
	}
	if(matriz[i][j] == 'd')
	{
		point+=50;
	}
	return point;
}

int walk(int i,int j,int n,int m)
{
	int points=0,path1=0,path2=0,path3=0,path4=0;
	if((matriz[i][j] == '#') || (i < 0) || (j < 0))
	{
		return (0);
	}
	else if(i<n && j<m)
	{
		points = score(matriz,i,j);
		matriz[i][j] = '#';
		path1 = walk(i-1,j,n,m);
		path2 = walk(i+1,j,n,m);
		path3 = walk(i,j-1,n,m);
		path4 = walk(i,j+1,n,m);
		if((path1 > path2) && (path1 > path3) && (path1 > path4))points+=path1;
		if((path2 > path1) && (path2 > path3) && (path2 > path4))points+=path2;
		if((path3 > path1) && (path3 > path2) && (path3 > path4))points+=path3;
		if((path4 > path1) && (path4 > path2) && (path4 > path3))points+=path4;
		//points+=bestscore(path1,path2,path3,path4);
		matriz[i][j]=matriz1[i][j];
	}
	return points;
}

int main()
{
	int n,m,i,j,k=0;
	scanf("%d%d",&n,&m);
	for(i=0;i < n;i++)
	{
		for(j=0;j < m;j++)
		{
			scanf("%c\n",&matriz[i][j]);
		}
	}
	for(i=0;i < n;i++)
	{
		for(j=0;j < m;j++)
		{
			matriz1[i][j]=matriz[i][j];
		}
	}
	i=j=0;
	k = walk(i,j,n,m);
	printf("%d\n",k);
	return 0;
}