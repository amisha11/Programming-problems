#include <stdio.h>
#include <conio.h>

int maze[10][10];
int sol[10][10];
int n;

void start(int i, int j)
{
	if ((j + 1 < n) && (i < n))
		if (maze[i][j + 1] != 0)
		{
			sol[i][j + 1] = 1;
			start(i, j + 1);
		}	
	if ((i + 1 < n) && (j < n))
		if (maze[i + 1][j] != 0)
		{
			if (j + 1 < n)
				sol[i][j + 1] = 0;
			sol[i + 1][j] = 1;
			start(i + 1, j);
		}
	if (sol[n-1][n-1] != 1)
	{
		if (i + 1 < n)
			sol[i + 1][j] = 0;
		if (j + 1 < n)
			sol[i][j + 1] = 0;
	}
}

void solution_init()
{
	int l, m;
	for (l = 0; l < n; l++)
		for (m = 0; m < n; m++)
			sol[l][m] = 0;
	sol[0][0] = 1;
}

void main()
{
	printf("\nEnter the size of maze : ");
	scanf("%d", &n);
	int i, j;
	printf("\nEnter the value for maze :\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &maze[i][j]);
	solution_init();
	start(0,0);
	printf("\nThe solution for the given rat in a maze problem is : ");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%d\t", sol[i][j]);
	}
	getch();
}