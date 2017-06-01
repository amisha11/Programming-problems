#include <stdio.h>
#include <string.h>

void main(){
    freopen("A-large.in","r", stdin);
    freopen("output-A.in", "w", stdout);
	int n, i, num, j, k, cake, flag = 0, z, len;
    char str[2000];
	scanf("%d", &n);
	z = 0;
	while(z < n){
        flag = 0;
        cake = 0;
        scanf(" %s %d", str, &num);
        len = strlen(str);
        for(i = 0; i < len; i++){
            if(str[i] == '-'){
                cake++;
                j = i;
                k = num;
                if(i + num > len){
                    j = len - num;
                }
                while(k){
                    if(str[j]=='-'){
                        str[j] = '+';
                    }
                    else{
                        str[j] = '-';
                    }
                    j++;
                    k--;
                }
            }
        }
        for(i = 0; i < len; i++){
        if(str[i]=='-'){
            printf("Case #%d: IMPOSSIBLE\n", z+1);
            flag = -1;
            break;
        }
	}
	if(flag == 0){
        printf("Case #%d: %d\n", z+1, cake);
    }
	z++;
}
return 0;
}
