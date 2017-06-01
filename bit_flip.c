#include <stdio.h>

void count_bit(int A, int B){
    int a[10], b[10], c[10], i = -1, j = -1, k, count = 0;
    while(A){
        i++;
        a[i] = A % 2;
        A = A/2;
    }
    while(B){
        j++;
        b[j] = B % 2;
        B = B/2;
    }
    if(i==j){
        for(k = 0; k <= i; k++){
            if(a[k]!=b[k]){
                count++;
            }
        }
    }
    else if(i < j){
        for(k = i + 1; k <= j; k++){
            a[k] = 0;
        }
        for(k = 0; k <= j; k++){
            if(a[k]!=b[k]){
                count++;
            }
        }
    }
    else {
        for(k = j + 1; k <= i; k++){
            b[k] = 0;
        }
        for(k = 0; k <= i; k++){
			if(a[k]!=b[k]){
                count++;
            }
        }
    }
    printf("%d", count);
}

int main() {
    int t, a, b, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
	    scanf("%d%d", &a, &b);
	    count_bit(a, b);
	}
	return 0;
}