#include <stdio.h>

int main() {
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int ans = 3;
    if (a % m == 1) {
        ans -= 1;
    }
    if (b % m == 0 || b == n) {
        ans -= 1;
    }
    if (m == 1) {
        printf("1\n");
        return 0;
    } else if ((a - 1) / m == (b - 1) / m) {
        printf("1\n");
        return 0;
    } else if ((a % m - b % m) % m == 1) {
        printf("%d\n", (b - 1) / m - (a - 1) / m + 1);
        return 0;
    }
    printf("%d\n", (ans < (b - 1) / m - (a - 1) / m + 1) ? ans : (b - 1) / m - (a - 1) / m + 1);
    return 0;
}
