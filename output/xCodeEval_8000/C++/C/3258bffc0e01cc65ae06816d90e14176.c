#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
typedef struct { i64* arr; int size; } vi;
typedef struct { ld* arr; int size; } vd;
typedef struct { char** arr; int size; } vs;
typedef struct { char* arr; int size; } vc;
typedef struct { bool* arr; int size; } vb;
typedef struct { i64 first; i64 second; } pii;
typedef struct { i64 first; pii second; } pip;
typedef struct { pii first; i64 second; } ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

int getbit(i64 s, int i) { return (s >> i) & 1; }
i64 onbit(i64 s, int i) { return s | (1LL << i); }
i64 offbit(i64 s, int i) { return s & (~(1LL << i)); }
int cntbit(i64 s) { int cnt = 0; while (s) { cnt++; s &= (s - 1); } return cnt; }

char* s;
int q = 0;

void Input() {
    scanf("%s", s);
}

void Solve() {
    i64 baseAnswer = 1;
    int len = strlen(s);
    int* Map = (int*)calloc(26, sizeof(int));
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') continue;
        if (s[i] == '?') { q++; continue; }
        Map[s[i] - 'A']++;
    }
    int MapSize = 0;
    for (int i = 0; i < 26; i++) {
        if (Map[i] > 0) MapSize++;
    }
    for (i64 i = 10; i > 10 - MapSize; i--) baseAnswer *= i;
    if (s[0] >= 'A' && s[0] <= 'J') { baseAnswer /= 10; baseAnswer *= 9; }
    if (s[0] == '?') { baseAnswer *= 9; q--; }
    printf("%lld", baseAnswer);
    for (i64 i = 0; i < q; i++) printf("0");
}

int main() {
    s = (char*)malloc(1000005 * sizeof(char));
    Input();
    Solve();
    return 0;
}
