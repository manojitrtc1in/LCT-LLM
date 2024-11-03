#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int to_int(char* s) {
    int x = 0;
    int i;
    for (i = 0; i < strlen(s); ++i) {
        x *= 10;
        x += (s[i] - '0');
    }
    return x;
}

void reverse(char* s) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void solve() {
    char s[MAX_SIZE];
    scanf("%s", s);
    int st10[MAX_SIZE];
    st10[0] = 1;
    int i;
    for (i = 1; i < MAX_SIZE; ++i) {
        st10[i] = st10[i - 1] * 10;
    }
    reverse(s);
    while (s[strlen(s) - 1] < '0' || s[strlen(s) - 1] > '9') {
        s[strlen(s) - 1] = '\0';
    }
    reverse(s);
    int VEC[MAX_SIZE];
    int size = strlen(s);
    for (i = size; i > 0; --i) {
        VEC[size - i] = to_int(s);
        reverse(s);
        s[strlen(s) - 1] = '\0';
        reverse(s);
    }
    reverse(VEC, size);

    int SET[MAX_SIZE];
    int ans = 0;
    int j;
    for (i = 0; i < size; ++i) {
        int x = VEC[i];
        while (x < 1989) {
            int found = 0;
            for (j = 0; j < i + 1; ++j) {
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
        SET[i] = x;
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
