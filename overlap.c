#include <stdio.h>

struct node{
	int s, e;
};

void sort_arr(struct node arr[], int n){
	int i, j;
	struct node temp;
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(arr[i].s > arr[j].s){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

struct node arr[20];

void main(){
	int n, i, j;
	printf("Enter the number of intervals\n");
	scanf("%d", &n);
	struct node temp;
	printf("Enter the intervals\n");
	for(i = 0; i < n; i++){
		scanf("%d %d", &arr[i].s, &arr[i].e);
	}
	sort_arr(arr, n);
	i = 0;
	j = 0;
	printf("\nMerged Intervals are :\n");
	for(i = 0; i < n; i++){
		temp.s = arr[i].s;
		for(j = i + 1; j < n; j++){
			if(arr[i].e > arr[j].s){
				i = j;
			}
			else{
				break;
			}
		}
		temp.e = arr[i].e;
		printf("(%d, %d)\n", temp.s, temp.e);
	}
}