#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char lng[MAX_LENGTH];
    char sht[MAX_LENGTH];
    scanf("%s", lng);
    scanf("%s", sht);
    int n = strlen(lng);
    int m = strlen(sht);
    int leftmost[m + 1];
    int rightmost[m + 1];
    rightmost[m] = n;

    int idx = 0;
    for (int i = 0; i < m; i++) {
        while (sht[i] != lng[idx]) idx++;
        leftmost[i] = idx;
        idx++;
    }
    idx = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (sht[i] != lng[idx]) idx--;
        rightmost[i] = idx;
        idx--;
    }

    int ans = rightmost[0];
    for (int i = 0; i < m; i++)
        ans = max(ans, rightmost[i + 1] - leftmost[i] - 1);
    printf("%d\n", ans);

    return 0;
}
