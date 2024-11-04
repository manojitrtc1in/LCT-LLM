#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
typedef long long ll;
typedef struct {
    int first;
    int second;
} pii;
typedef struct {
    ll first;
    ll second;
} pll;
typedef struct {
    int* data;
    int size;
    int capacity;
} vi;
typedef struct {
    int* data;
    int size;
    int capacity;
} seti;
typedef struct {
    double first;
    double second;
} pdd;
typedef long double ld;

const double EPS = 0.000000001;
const double id0 = 1000000000;
const ll INF64 = 1000000000000000000;
const int INF32 = 1000000000;

int to_int(char* s) {
    int x = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        x *= 10;
        x += (s[i] - '0');
    }
    return x;
}

void reverse(char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void solve() {
    char s[100];
    scanf("%s", s);
    int st10[20];
    st10[0] = 1;
    for (int i = 1; i < 20; ++i) {
        st10[i] = st10[i - 1] * 10;
    }
    reverse(s);
    while (s[strlen(s) - 1] < '0' || s[strlen(s) - 1] > '9') {
        s[strlen(s) - 1] = '\0';
    }
    reverse(s);
    vi VEC;
    for (int i = strlen(s); i > 0; --i) {
        VEC.data[VEC.size++] = to_int(s);
        reverse(s);
        s[strlen(s) - 1] = '\0';
        reverse(s);
    }
    reverse(VEC.data);
    seti SET;
    int ans = 0;
    for (int i = 0; i < VEC.size; ++i) {
        int x = VEC.data[i];
        while (x < 1989 || SET.data[x]) {
            x += st10[i + 1];
        }
        SET.data[x] = 1;
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
