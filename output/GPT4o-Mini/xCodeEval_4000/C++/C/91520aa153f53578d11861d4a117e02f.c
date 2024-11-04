#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 100300
#define MOD 1000000007

long long st10[20];

int to_int(const char *s) {
    int x = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        x *= 10;
        x += (s[i] - '0');
    }
    return x;
}

void solve() {
    char s[100];
    scanf("%s", s);
    
    st10[0] = 1;
    for (int i = 1; i < 20; ++i) {
        st10[i] = st10[i - 1] * 10;
    }

    int len = strlen(s);
    while (len > 0 && (s[len - 1] < '0' || s[len - 1] > '9')) {
        s[--len] = '\0';
    }

    long long VEC[100];
    int vec_size = 0;

    for (int i = len; i > 0; --i) {
        VEC[vec_size++] = to_int(s);
        s[len - 1] = '\0'; // Remove last character
        len--;
    }

    long long SET[100] = {0};
    int set_size = 0;
    long long ans = 0;

    for (int i = 0; i < vec_size; ++i) {
        long long x = VEC[i];
        while (x < 1989) {
            int found = 0;
            for (int j = 0; j < set_size; ++j) {
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

        SET[set_size++] = x;
        ans = x;
    }
    printf("%lld\n", ans);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
