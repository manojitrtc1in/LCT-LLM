#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_MOD 1000000007LL
#define MOD 998244353LL
#define MAX_C 300000

typedef struct {
    long double real;
    long double imag;
} complex;

typedef struct {
    complex center;
    long double r;
} Circle;

typedef struct {
    long long first;
    long long second;
} modint;

typedef struct {
    long long a;
    long long b;
} Fraction;

typedef struct {
    long long vertexs[6];
} Dice;

modint hoge[MAX_C] = {0};
modint rev[MAX_C] = {0};
long long cnter[MAX_C];

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

modint pows(modint val, long long b) {
    modint ans = val;
    b--;
    while (b) {
        if (b % 2) {
            ans.value = (ans.value * val.value) % MAX_MOD;
        }
        val.value = (val.value * val.value) % MAX_MOD;
        b /= 2LL;
    }
    return ans;
}

void init() {
    printf("%.200Lf\n", 0.0);
}

void solve() {
    long long n;
    scanf("%lld", &n);
    char t[MAX_C];
    scanf("%s", t);
    
    long long len = strlen(t);
    for (long long i = 0; i < len; i++) {
        if (t[i] == '0') {
            cnter[i] = i * 2 + i % 2;
        }
    }
    
    modint nexts = {1, 1};
    for (long long i = 0; i < len; i++) {
        hoge[i + 1] = hoge[i];
        hoge[i + 1].first += nexts.first * (cnter[i] % 2);
        hoge[i + 1].second += nexts.second * (cnter[i] % 2);
        rev[i + 1] = rev[i];
        rev[i + 1].first += nexts.first * ((cnter[i] + 1) % 2);
        rev[i + 1].second += nexts.second * ((cnter[i] + 1) % 2);
        nexts.first *= 2;
        nexts.second *= 2;
    }
    
    long long query;
    scanf("%lld", &query);
    for (long long i = 0; i < query; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        a--; b--;
        
        long long Left_first = lower_bound(cnter, cnter + len, a * 2) - cnter;
        long long Left_second = lower_bound(cnter, cnter + len, (a + c) * 2) - cnter;
        long long Right_first = lower_bound(cnter, cnter + len, b * 2) - cnter;
        long long Right_second = lower_bound(cnter, cnter + len, (b + c) * 2) - cnter;
        
        if (Left_second - Left_first != Right_second - Right_first) {
            printf("No\n");
            continue;
        }
        
        int ok = 1;
        modint aa = hoge[Left_second];
        aa.first -= hoge[Left_first].first;
        aa.second -= hoge[Left_first].second;
        
        modint bb;
        if (a % 2 == b % 2) {
            bb = hoge[Right_second];
            bb.first -= hoge[Right_first].first;
            bb.second -= hoge[Right_first].second;
        } else {
            bb = rev[Right_second];
            bb.first -= rev[Right_first].first;
            bb.second -= rev[Right_first].second;
        }
        
        if (Left_first != 0) {
            aa.first /= pows((modint){2, 0}, Left_first).first;
            aa.second /= pows((modint){2, 0}, Left_first).second;
        }
        if (Right_first != 0) {
            bb.first /= pows((modint){2, 0}, Right_first).first;
            bb.second /= pows((modint){2, 0}, Right_first).second;
        }
        
        if (aa.first != bb.first || aa.second != bb.second) {
            ok = 0;
        }
        
        if (ok == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

int main() {
    init();
    solve();
    return 0;
}
