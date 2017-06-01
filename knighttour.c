#include <stdio.h>
#include <conio.h>

int n, temp;
int arr[10][10];
int count = 0;

void initialise()
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			arr[i][j] = 0;
	arr[0][0] = 1;
	count++;
}

void sol(int i, int j)
{
	if (count < temp){
		if ((i + 2) < n)
		{
    		if (((j + 1) < n) && (arr[i + 2][j + 1] == 0))
			{
				count++;
				arr[i + 2][j + 1] = count;
				sol(i + 2, j + 1);
				if (count < temp)
				{
					count--;
					arr[i + 2][j + 1] = 0;
				}
			}
			if (((j - 1) >= 0) && (arr[i + 2][j - 1] == 0))
			{
				count++;
				arr[i + 2][j - 1] = count;
				sol(i + 2, j - 1);
				if (count < temp)
				{
					count--;
					arr[i + 2][j - 1] = 0;
				}
			}
		}
		
		if ((i - 2) >= 0)
		{
			if (((j + 1) < n) && (arr[i - 2][j + 1] == 0))
			{
				count++;
				arr[i - 2][j + 1] = count;
				sol(i - 2, j + 1);
				if (count < temp)
				{
					count--;
					arr[i - 2][j + 1] = 0;
				}
			}
			if (((j - 1) >= 0) && (arr[i - 2][j - 1] == 0))
			{
				count++;
				arr[i - 2][j - 1] = count;
				sol(i - 2, j - 1);
				if (count < temp)
				{
					count--;
					arr[i - 2][j - 1] = 0;
				}
			}
		}
		
		if ((j + 2) < n)
		{
			if (((i + 1) < n) && (arr[i + 1][j + 2] == 0))
			{
				count++;
				arr[i + 1][j + 2] = count;
				sol(i + 1, j + 2);
				if (count < temp)
				{
					count--;
					arr[i + 1][j + 2] = 0;
				}
			}
			if (((i - 1) >= 0) && (arr[i - 1][j + 2] == 0))
			{
				count++;
				arr[i - 1][j + 2] = count;
				sol(i - 1, j + 2);
				if (count < temp)
				{
					count--;
					arr[i - 1][j + 2] = 0;
				}
			}
		}
	
		if ((j - 2) >= 0)
		{
			if (((i + 1) < n) && (arr[i + 1][j - 2] == 0))
			{
				count++;
				arr[i + 1][j - 2] = count;
				sol(i + 1, j - 2);
				if (count < temp)
				{
					count--;
					arr[i + 1][j - 2] = 0;
				}
			}
			if (((i - 1) >= 0) && (arr[i - 1][j - 2] == 0))
			{
				count++;
				arr[i - 1][j - 2] = count;
				sol(i - 1, j - 2);
				if (count < temp)
				{
					count--;
					arr[i - 1][j - 2] = 0;
				}
			}
		}
	}
}

void main()
{
	int i, j;
	printf("\nEnter the size of the board : ");
	scanf("%d", &n);
	temp = n * n;
	initialise();
	printf("\nSolution : \n");
	sol(0,0);
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%d\t", arr[i][j]);
	}
	getch();
}