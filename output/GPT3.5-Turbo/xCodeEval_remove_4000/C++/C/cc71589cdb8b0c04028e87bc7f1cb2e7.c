#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000 + 7

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int first;
    int second;
} pair;

int sz(char* str) {
    return strlen(str);
}

void forn(int i, int size) {
    // implementation of forn
}

int atoll(const char* str) {
    return atoi(str);
}

int clock() {
    // implementation of clock
}

void puts(const char* str) {
    printf("%s\n", str);
}

void scanf(const char* format, int* variable) {
    scanf(format, variable);
}

void freopen(const char* filename, const char* mode, FILE* stream) {
    // implementation of freopen
}

void cerr_precision(int precision) {
    // implementation of cerr_precision
}

void cout_precision(int precision) {
    // implementation of cout_precision
}

void cerr_fixed() {
    // implementation of cerr_fixed
}

void cout_fixed() {
    // implementation of cout_fixed
}

int INF = 1e9;
li INF64 = 1e18;
int MOD = 1e9 + 7;
ld EPS = 1e-9;
ld PI = acos(-1.0);

int n;
char s[N];

int read() {
    static char buf[N];
    if (scanf("%s", buf) != 1)
        return 0;
    strcpy(s, buf);
    strcpy(s, s + 4);
    n = sz(s);
    return 1;
}

li lim[] = {0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};
char pr1[][4] = {"", "198", "19", "2", "", "", "", "", "", ""};
char pr2[][4] = {"", "199", "20", "3", "1", "1", "1", "1", "1", "1"};

char* solve() {
    li x = atoll(s);
    if (x >= lim[n])
        return strcat(pr1[n], s);
    else
        return strcat(pr2[n], s);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    freopen("input.txt", "r", file);

    int tt = clock();

    cerr_precision(15);
    cout_precision(15);
    cerr_fixed();
    cout_fixed();

    int tc;
    scanf("%d", &tc);
    while(tc--){
        read();
        while(read()) {
            puts(solve());
        }

        printf("TIME = %d\n", clock() - tt);
        tt = clock();
    }

    return 0;
}
