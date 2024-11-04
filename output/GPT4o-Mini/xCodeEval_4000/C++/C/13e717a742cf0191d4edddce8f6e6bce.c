#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define SZ(A) (sizeof(A) / sizeof(A[0]))

int a[10], b[10]; 
char s[100]; 
int r, rr, x, y, xx, yy, zero;

void calc(int x) {
    int y = 10 - x; 
    if (!a[x] || !a[y]) return;
    int r = 1; 
    REP(i, 10) r += (a[i] - (i == x) < 0) ? 0 : (a[9 - i] - (9 - i == y) < 0) ? 0 : (a[i] - (i == x)) + (a[9 - i] - (9 - i == y));
    if (r > rr) rr = r, xx = x, yy = y;
}

int main() {
    scanf("%s", s); 
    REP(i, strlen(s)) ++a[s[i] - '0'];
    
    r = -1; 
    x = y = s[0] - '0'; 
    FOR(i, 0, a[0] + 1) {
        a[0] -= i; 
        rr = 0; 
        xx = yy = s[0] - '0'; 
        calc(1); calc(2); calc(3); calc(4); calc(5); 
        if (rr + i > r) r = rr + i, zero = i, x = xx, y = yy; 
        a[0] += i;
    }
    
    if (!x) --zero; 
    a[0] -= zero; 
    memcpy(b, a, sizeof(a)); 
    --a[x]; 
    --b[y];
    
    REP(i, 10) REP(j, a[i] - (a[i] < b[9 - i] ? a[i] : b[9 - i])) printf("%d", i);
    REP(i, 10) REP(j, (a[i] < b[9 - i] ? a[i] : b[9 - i])) printf("%d", i);
    if (a[x] >= 0) printf("%d", x); 
    REP(i, zero) putchar('0'); 
    puts("");
    
    REP(i, 10) REP(j, b[9 - i] - (a[i] < b[9 - i] ? a[i] : b[9 - i])) printf("%d", 9 - i);
    REP(i, 10) REP(j, (a[i] < b[9 - i] ? a[i] : b[9 - i])) printf("%d", 9 - i);
    if (b[y] >= 0) printf("%d", y); 
    REP(i, zero) putchar('0'); 
    puts("");
    
    return 0;
}
