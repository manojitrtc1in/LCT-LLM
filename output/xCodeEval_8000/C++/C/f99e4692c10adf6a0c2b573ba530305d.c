#include <stdio.h>

#define N 1000009

int a[N], n, s[N], top;

int main(){

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int x;
    scanf("%d", &x);
    a[x-1] *= -1;

    for(int i=n-1; i>=0; i--){
        if(a[i] > 0){
            if(top && s[top] == a[i]){
                top--;
            }
            else{
                s[++top] = a[i];
                a[i] = -a[i];
            }
        }
        else{
            s[++top] = -a[i];
        }
    }

    if(top){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        for(int i=0; i<n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}
