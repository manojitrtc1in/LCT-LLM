#include <stdio.h>
#include <stdlib.h>

#define N 1000009

int a[N], n, s[N], top;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int k;
    scanf("%d", &k);
    a[k-1] *= -1;

    for (int i = n-1; i >= 0; i--) {
        if (a[i] > 0) {
            if (top && s[top] == a[i]) {
                top--;
            } else {
                top++;
                s[top] = a[i];
                a[i] = -a[i];
            }
        } else {
            top++;
            s[top] = -a[i];
        }
    }

    if (top) {
        printf("NO\n");
    } else {
        printf("YES ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}
