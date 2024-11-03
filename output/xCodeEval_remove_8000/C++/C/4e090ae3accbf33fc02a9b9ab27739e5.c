#include <stdio.h>
#include <math.h>

#define MS 3001
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORQ(i,a,b) for(int i=(a);i<=(b);i++)

long long pw[MS];

int pr[3] = {2, 7, 61};

void count() {
    pw[0] = 1;
    for(int c = 1; c < MS; c++)
        pw[c] = pw[c-1] * 2;
}

long long square(long long x) {
    return x * x;
}

long long bigmod(long long b,long long p,long long m) {
    if (p == 0)
        return 1;
    else if (p%2 == 0)
        return square(bigmod(b,p/2,m)) % m;
    else
        return ((b % m) * bigmod(b,p-1,m)) % m;
}

int sqr(int x) {
    return x*x;
}

int ok(int x) {
    if(x == 1)
        return 0;
    if(mr(x))
        return 0;
    int v = sqrt(1.0*x);
    FORQ(i,1,v) {
        int j = sqr(i);
        if(x > j && sqr(sqrt(1.0*x-j)) + j == x)
            return 1;
    }
    return 0;
}

int main() {
    count();

