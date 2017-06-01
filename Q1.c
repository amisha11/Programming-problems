#include <stdio.h>

long int findTidy(long int num){
	long int n = num;
	long int j, k, arr[255], dig = 0;
	long int flag, i;
	for(k = n; k >= n/1.5; k--){
		flag = 0;
		dig = 0;
		j = k;
		while(j!=0){
			arr[dig] = j % 10;
        	j = j / 10;
        	dig++;
		}
		for (i = 0; i < dig - 1; i++) {
        	if (arr[i] < arr[i+1]){
        		flag = 1;
        		//break;
        	}
		}
		if(flag==0){
			return k;
		}
	}
	return 0;
}

int main(void) {
    freopen("B-small-attempt5.in","r", stdin);
    freopen("output-B.in", "w", stdout);
	long int n, i, num, tidy;
	scanf("%ld", &n);
	long int arr[100];
	for(i = 1; i <= n ; i++){
	    scanf("%ld", &arr[i]);
	}
	for(i = 1; i <= n ; i++){
		num = arr[i];
		tidy = findTidy(num);
		printf("Case #%ld: %ld\n", i, tidy);
	}
	return 0;
}
