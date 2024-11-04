#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;
typedef long long ll;
#define MAX_SIZE 20
#define INF64 1000000000000000000
#define INF32 1000000000

const double EPS = 0.000000001;
const double id0 = 1000000000;

int to_int(char *s) {
    int x = 0;
    for (int i = 0; i < strlen(s); ++i) {
        x *= 10;
        x += (s[i] - '0');
    }
    return x;
}

int st10[MAX_SIZE];

void solve() {
    char s[100];
    scanf("%s", s);
    st10[0] = 1;
    for (int i = 1; i < MAX_SIZE; ++i) {
        st10[i] = st10[i - 1] * 10;
    }

    int len = strlen(s);
    while (len > 0 && (s[len - 1] < '0' || s[len - 1] > '9')) {
        s[--len] = '\0';
    }

    int VEC[MAX_SIZE];
    int vec_size = 0;

    for (int i = len; i > 0; --i) {
        VEC[vec_size++] = to_int(s);
        s[i - 1] = '\0'; // Remove last character
    }

    int SET[1000000] = {0}; // Assuming a maximum size for the set
    int ans = 0;

    for (int i = 0; i < vec_size; ++i) {
        int x = VEC[i];
        while (x < 1989 || SET[x]) {
            x += st10[i + 1];
        }
        SET[x] = 1; // Insert x into the set
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
