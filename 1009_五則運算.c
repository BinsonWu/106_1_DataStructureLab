#include<stdio.h>

int topI, topC;
int stackI[1000];
char stackC[1000];

void pushI(int n) {
	stackI[++topI] = n;
}
int popI(void) {
	return stackI[topI--];
}
void pushC(char ch) {
	stackC[++topC] = ch;
}
char popC(void) {
	return stackC[topC--];
}

void calculate(void) {
	int i = 0;
	while (++i <= topC)
		if (stackC[i] == '+')
			stackI[i + 1] = stackI[i] + stackI[i + 1];
		else
			stackI[i + 1] = stackI[i] - stackI[i + 1];
}

int main(void) {
	int n;
	char ch;
	while (scanf("%d", &n) != EOF) {
		topI = topC = 0;
		pushI(n);
		while (scanf("%c", &ch))
        {
            if (ch == ' ')
				continue;
			else if (ch == '\n' || ch == '\r' )
				break;
			else if (ch == '*') {
				scanf("%d", &n);
				pushI(popI() * n);
			}
			else if (ch == '/') {
				scanf("%d", &n);
				pushI(popI() / n);
			}
			else if (ch == '%') {
				scanf("%d", &n);
				pushI(popI() % n);
			}
			else {
				scanf("%d", &n);
				pushI(n);
				pushC(ch);
			}
        }

		calculate();
		printf("%d\n", popI());
	}
	return 0;
}

