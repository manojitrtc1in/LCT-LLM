#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50

int main() {
    int n;
    scanf("%d", &n);
    
    int l[MAX_N][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &l[i][j]);
        }
    }
    
    if (n >= 50) {
        printf("0\n");
        return 0;
    }
    
    if (n <= 2) {
        printf("%d\n", n);
        for (int i = 0; i < n; i++) {
            printf("%d\n", i + 1);
        }
        return 0;
    }
    
    int *er = (int *)malloc(n * sizeof(int));
    int er_count = 0;
    
    for (int i = 0; i < n; i++) {
        int f = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                int w = 0;
                for (int d = 0; d < 5; d++) {
                    w += (l[i][d] - l[j][d]) * (l[i][d] - l[k][d]);
                }
                if (w > 0) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) {
                break;
            }
        }
        if (f == 0) {
            er[er_count++] = i + 1;
        }
    }
    
    printf("%d\n", er_count);
    for (int i = 0; i < er_count; i++) {
        printf("%d\n", er[i]);
    }
    
    free(er);
    return 0;
}
