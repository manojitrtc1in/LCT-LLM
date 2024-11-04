#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxN 100300

int to_int(char* s) {
    int x = 0;
    int i = 0;
    while (s[i] != '\0') {
        x *= 10;
        x += (s[i] - '0');
        i++;
    }
    return x;
}

void solve() {
    char s[20];
    scanf("%s", s);
    int st10[20];
    st10[0] = 1;
    for (int i = 1; i < 20; ++i) {
        st10[i] = st10[i - 1] * 10;
    }
    int len = strlen(s);
    for (int i = len - 1; i >= 0; --i) {
        if (s[i] < '0' || s[i] > '9') {
            s[i] = '\0';
        } else {
            break;
        }
    }
    int VEC[20];
    int VEC_size = 0;
    for (int i = len; i > 0; --i) {
        VEC[VEC_size++] = to_int(s);
        s[strlen(s) - 1] = '\0';
    }
    int SET[maxN];
    int SET_size = 0;
    int ans = 0;
    for (int i = 0; i < VEC_size; ++i) {
        int x = VEC[i];
        while (x < 1989) {
            int found = 0;
            for (int j = 0; j < SET_size; ++j) {
                if (SET[j] == x) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                x += st10[i + 1];
            } else {
                break;
            }
        }
        SET[SET_size++] = x;
        ans = x;
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
