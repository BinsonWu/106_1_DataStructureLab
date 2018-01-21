#include<stdio.h>

int N;

char str[1005];

int main()
{
	while(scanf("%d%*c",&N)==1) while(N--)
	{
		gets(str);
		int i=0;
		while(str[i])
		{
			while(str[i]==' ') { printf("%c",str[i++]); }
			int WordLeft=i;
			while(str[i]&&str[i]!=' ') { ++i; }
			int WordRight=i-1;
			while(WordLeft<=WordRight) { printf("%c",str[WordRight--]); }
		}
		printf("\n");
	}
	return 0;
}
