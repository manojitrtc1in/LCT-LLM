#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxN 100300

int to_int(char* s) {
    int x = 0;
    for (int i = 0; i < strlen(s); ++i) {
        x *= 10;
        x += (s[i] - '0');
    }
    return x;
}

void solve() {
    char s[100];
    scanf("%s", s);
    int st10[20];
    st10[0] = 1;
    for (int i = 1; i < 20; ++i) st10[i] = st10[i - 1] * 10;
    strrev(s);
    while (s[strlen(s) - 1] < '0' || s[strlen(s) - 1] > '9') s[strlen(s) - 1] = '\0';
    strrev(s);
    int VEC[100];
    int size = 0;
    for (int i = strlen(s); i > 0; --i) {
        VEC[size++] = to_int(s);
        strrev(s);
        s[strlen(s) - 1] = '\0';
        strrev(s);
    }
    for (int i = size - 1; i >= 0; --i) {
        int x = VEC[i];
        while (x < 1989) {
            int isFound = 0;
            for (int j = 0; j < size; ++j) {
                if (VEC[j] == x) {
                    isFound = 1;
                    break;
                }
            }
            if (isFound) {
                x += st10[i + 1];
            } else {
                break;
            }
        }
        VEC[i] = x;
    }
    int SET[100];
    int setSize = 0;
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        int x = VEC[i];
        int isFound = 0;
        for (int j = 0; j < setSize; ++j) {
            if (SET[j] == x) {
                isFound = 1;
                break;
            }
        }
        if (!isFound) {
            SET[setSize++] = x;
            ans = x;
        }
    }
    printf("%d\n", ans);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
