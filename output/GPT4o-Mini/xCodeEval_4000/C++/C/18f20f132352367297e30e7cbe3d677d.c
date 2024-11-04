#include <stdio.h>
#include <string.h>

char a[128], c[128];
int b, d, t[128];

int main() {
    scanf("%d%d", &b, &d);
    scanf("%s%s", a, c);
    int s = 0, n = strlen(c);
    
    for (int i = 0; c[i]; ++i) {
        int *k = &t[i];
        *k = 0; // Initialize k
        for (int j = 0; a[j]; ++j) {
            if (a[j] == c[(i + *k) % n]) {
                ++(*k);
            }
        }
    }
    
    for (int i = 0; i < b; ++i) {
        s += t[s % n];
    }
    
    printf("%d\n", s / n / d);
    return 0;
}
