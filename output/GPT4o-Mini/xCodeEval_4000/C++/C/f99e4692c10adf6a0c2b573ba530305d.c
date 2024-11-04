#include <stdio.h>
#include <stdlib.h>

#define N 1000009

int a[N], n, s[N], top;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int index;
    scanf("%d", &index);
    a[index - 1] *= -1;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > 0) {
            if (top && s[top] == a[i]) {
                --top;
            } else {
                s[++top] = a[i];
                a[i] = -a[i];
            }
        } else {
            s[++top] = -a[i];
        }
    }

    if (top) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }

    return 0;
}
