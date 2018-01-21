#include <stdio.h>
#include <stdlib.h>
int n;
int b[150]={0};
char a[600];
long long sum=0;
void print()
{
	int i;
	sum++;
	for(i=1;i<=n;++i)
	{
		printf("%c",a[i]);
	}
	printf("\n");
}
void search(int i)
{
	int j;
	for( j='a';j<='z';++j)
	{
		if(b[j]!=0)
		{
			a[i]=j;
			b[j]--;
			if(i==n)
			{
				print();
			}
			else
			{
				search(i+1);
			}
			b[j]++;
		}
	}
}

int main()
{
	scanf("%d\n",&n);
	char c;
	int i;
	for( i=1;i<=n;++i)
	{
		scanf("%c",&c);
		b[c]++;
	}
	scanf("%c",&c);
	search(1);
	printf("%lld",sum);
	return 0;
}

