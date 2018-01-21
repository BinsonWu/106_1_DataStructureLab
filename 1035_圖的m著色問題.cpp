#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int n,k,m;
int b[200]={0};
int a[200][200]={0};
int tot=0;
void search(int i)
{
	if (i==n+1)
	{
		++tot;
		return;
	}
	bool c[10];
	for(int j=1;j<=10;++j)
	{
		c[j]=0;
	}
	for(int j=1;j<=n;++j)
	{
		if(a[i][j]==1)
		{
			c[b[j]]=1;
		}
	}
	for(int j=1;j<=m;++j)
	{
		if(c[j]==0)
		{
			b[i]=j;
			search(i+1);
			b[i]=0;
		}
	}
}
int main()
{
	cin>>n>>k>>m;
	memset(a,0,sizeof(a));
	int x,y;
	for(int i=1;i<=k;++i)
	{
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	search(1);
	cout<<tot;
	return 0;
	
}
