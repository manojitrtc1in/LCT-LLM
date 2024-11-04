#include <stdio.h>
#include <string.h>

#define MAX 128

int main() {
    int b, d;
    scanf("%d%d", &b, &d);
    
    char a[MAX], c[MAX];
    scanf("%s%s", a, c);
    
    int t[MAX] = {0};
    int s = 0, n = strlen(c);
    
    for (int i = 0; c[i]; ++i) {
        int k = t[i];
        for (int j = 0; a[j]; ++j) {
            if (a[j] == c[(i + k) % n]) {
                ++k;
            }
        }
        t[i] = k;
    }
    
    for (int i = 0; i < b; ++i) {
        s += t[s % n];
    }
    
    printf("%d\n", s / n / d);
    
    return 0;
}
