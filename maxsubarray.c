#include<stdio.h>

int maxsub(int arr[20], int n){
	int maxsf = arr[0], gm = arr[0], i;
	for(i = 0; i < n; i++){
		maxsf = max(arr[i], maxsf + arr[i]);
		if(maxsf > gm){
			gm = maxsf;
		}
	}
	return gm;
}

int max(int i, int j){
	if(i > j){
		return i;
	}
	else{
		return j;
	}
} 

void main(){
	printf("\nEnter the size of the array:\t");
	int n, i;
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements of the array:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int sum = maxsub(arr, n);
	printf("Max sum subarray =\t%d", sum);
}