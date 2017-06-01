#include <stdio.h>
#include <math.h>

int n;
int x1[10], x2[10], z1[10], y2[10], X1[10], X2[10], Y1[10], Y2[10], ans[10];

void overlap(int i)
{
    int l, L, b, B;
    l = abs(x1[i] - x2[i]);
    b = abs(z1[i] - y2[i]);
    L = abs(X1[i] - X2[i]);
    B = abs(Y1[i] - Y2[i]);
    if ((l == L) || (b == B))
        ans[i] = 1;
    else
        ans[i] = 0;
}

int main() {
	scanf("%d", &n);
	int i = 0;
	while(i < n)
	{
	    scanf("%d %d %d %d %d %d %d %d", &x1[i], &z1[i], &x2[i], &y2[i], &X1[i], &Y1[i], &X2[i], &Y2[i]);
		i++;
	}
	for(i = 0; i < n; i++)
	{
		overlap(i);
	    printf("%d\n", ans[i]);
	}
	return 0;
}