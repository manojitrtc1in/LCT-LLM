#include <stdio.h>

long long mulmod(long long a, long long b, long long MOD){
    if (b == 0) return 0;
    long long res = mulmod(a, b >> 1, MOD);
    res += res;
    res %= MOD;
    return (b & 1)? (a + res) % MOD : res;
}

int gcd(int a, int b){
    while (a!=0 && b!=0){
        if (a>b){
            a%=b;
        }
        else{
            b%=a;
        }
    }
    return a+b;
}

long long gcd(long long a, long long b){
    while (a!=0 && b!=0){
        if (a>b){
            a%=b;
        }
        else{
            b%=a;
        }
    }
    return a+b;
}

