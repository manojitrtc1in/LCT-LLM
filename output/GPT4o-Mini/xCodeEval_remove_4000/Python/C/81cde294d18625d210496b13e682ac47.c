#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    if (n >= 100) {
        printf("1\n");
        free(l);
        return 0;
    }

    int ans = n * n;
    int *cur = (int *)calloc(n + 1, sizeof(int));
    
    for (int i = 1; i <= n; i++) {
        cur[i] = cur[i - 1] ^ l[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if ((cur[j] ^ cur[i - 1]) > (cur[k] ^ cur[j])) {
                    ans = (ans < (k - i - 1)) ? ans : (k - i - 1);
                }
            }
        }
    }

    if (ans == n * n) {
        ans = -1;
    }
    
    printf("%d\n", ans);
    
    free(l);
    free(cur);
    return 0;
}
