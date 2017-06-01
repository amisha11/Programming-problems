#include<stdio.h>
#include<conio.h>

int a[20][20], visited[20], start[20], finish[20], timer = 0, n;

void dfs(int v){
	int i;
	visited[v] = 1;
	start[v] = timer++;
	for(i = 1; i <= n; i++){
		if(a[v][i] && !visited[i]){
			printf(" %d->%d\n", v, i);
			dfs(i);
		}
	}
	finish[v] = timer++;
}

void main(){
	printf("Enter the number of vertices\n");
	scanf("%d", &n);
	printf("Enter the edges\n");
	int i, j, count = 0;
	for(i = 1; i <= n; i++){
		visited[i] = 0;
		for(j = 1; j <= n; j++){
			a[i][j] = 0;
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	//printf("Enter the source of dfs\n");
	//scanf("%d", &i);
	printf("\n");
	dfs(1);
	for(i = 1; i <= n; i++){
		if(visited[i])
			count++;
	}
	if(count == n)
		printf("\n Graph is connected\n");
	else
		printf("\n Graph is not connected\n");
	getch();
}