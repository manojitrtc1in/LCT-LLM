#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    scanf("%s %s", s, t);
    
    int n = strlen(s), m = strlen(t);
    int front[MAX_LEN], back[MAX_LEN];
    int pos = 0;

    for (int i = 0; i < m; i++) {
        front[i] = -1;
        for (int j = pos; j < n; j++) {
            if (s[j] == t[i]) {
                front[i] = j;
                pos = j + 1;
                break;
            }
        }
    }

    pos = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        back[i] = -1;
        for (int j = pos; j >= 0; j--) {
            if (s[j] == t[i]) {
                back[i] = j;
                pos = j - 1;
                break;
            }
        }
    }

    int ans = back[0] > n - 1 - front[m - 1] ? back[0] : n - 1 - front[m - 1];
    for (int i = 0; i < m - 1; i++) {
        if (back[i + 1] - front[i] - 1 > ans) {
            ans = back[i + 1] - front[i] - 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
